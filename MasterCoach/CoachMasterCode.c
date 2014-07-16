/*
    Natalie Burkhard  05/05/14
    Code for EUSART comm the Coach controller, PIC16F690
//Edit by Shikhar
MASTER PIC
------------------------------------------------------------------
1        +5              Vdd       Vss       GND                20
2        osc1			 A5        A0        led11		        19
3        osc2			 A4        A1        led10		        18
4        _MCLR		     A3        A2        led9			 	17
5        led1		     C5        C0        led8				16
6        _XbeeReset		 C4        C1        led7			    15
7        led3			 C3        C2        led2			    14
8        _SS(out)	 	 C6        B4        SDI(in)		  	13
9        SDO(out)	 	 C7        B5        RX(in)	  			12
10       TX(out)		 B7        B6        SCK(out)      		11
-------------------------------------------------------------------

 	to reset Xbee, toggle C4 low then back to hi

    Functionality:
        - On reset / Upon initialization, turn off all displays, read all sensor inputs, prepare MessageOut (pairing)
        - On 5 Hz time-outs (CCP + TMR1), transmit MessageOut
            When transmit is complete, read all sensor inputs, prepare MessageOut
            If the transmit is a success, update ActiveComm display (keep it on; later can implement blinking)
        - When status is received, update the energy level display
	

	Comm:
		EUART: BR = 9600; if don't receive a message for 1 s, must reinitialize
		SSP: SCK = 312500
*/

#include "CoachMasterCode.h"
#include "CommInterface.h"

__CONFIG( CP_OFF & WDTE_OFF & PWRTE_ON & FOSC_HS & MCLRE_ON );

//----------------------------Masks
#define RESET			BIT0HI
#define RESET_PORT 		PORTA
#define TAG_OUT			BIT1HI
#define TAG_OUT_PORT	PORTA
#define PAIR			BIT2HI
#define PAIR_PORT	 	PORTA
// ??????

#define PAIR_Error		BIT0HI
#define PAIR_Error_PORT	PORTC_Copy
#define COMM_Error	 	BIT1HI
#define COMM_Error_PORT	PORTC_Copy
#define PAIRED	 		BIT2HI
#define PAIRED_PORT	 	PORTC_Copy



#define Set_PAIRED    	PAIRED_PORT|=PAIRED
#define Clear_PAIRED   	PAIRED_PORT&=~PAIRED
#define Set_COMM_Error	COMM_Error_PORT|=COMM_Error
#define Clear_COMM_Error COMM_Error_PORT&=~COMM_Error
#define Set_PAIR_Error	PAIR_Error_PORT|=PAIR_Error
#define Clear_PAIR_Error PAIR_Error_PORT&=~PAIR_Error 


//----------------------------API  Identifiers
#define	API_TXREQ	0x01	// uC -> XBee to send broadcast or directed message
#define API_TXSTAT	0x89	// Xbee -> uC after packet send attempt
#define	API_RXPACK	0x81	// Xbee -> uC on receipt of data frame from diff radio


////////All States now defined in header file

#define LOWER_SS	PORTC_Copy&=(~BIT6HI)
#define RAISE_SS	PORTC_Copy|=BIT6HI

#define NumBytes	8 //7 important, 1 dummy
#define AlignByte	0x37
//----------------------------EUART State Variables
static X_State CurrentX_State = X_Idle_State, NextX_State = X_Idle_State;
static unsigned char X_Transition = 1, R_Transition = 0;
static R_State CurrentR_State = R_Idle_State, NextR_State = R_Idle_State; 
//----------------------------Comm Variables
static unsigned char PlayerAddress = 0;
static unsigned char LostCommCounter = 0;
static unsigned int	 TOCounter= 0;
static signed char ByteIn = 0, NextByteOut = 0x7E;
static unsigned char SEND = 0;
static unsigned char SendKick = 0, SendWhimsy = 0;
//----------------------------Xmitted (X) and Received (R) Data Frame Bytes
// first send 0x7E
static signed char X_LengthMSB=0x00;
static signed char X_LengthLSB=0x00;
static signed char X_API=0x01;
static signed char X_FID=0x01;
static signed char X_AddrMSB=0x20;
static signed char X_AddrLSB=0x88;			
static signed char X_Options=0x00; 
static signed char X_CMD=0x01; 
static signed char X_RF1=0x0A;	
static signed char X_RF2=0x0B;
static signed char X_RF3=0x0C;
static signed char X_RF4=0x0D;
static signed char X_RF5=0x0E;	
static unsigned char R_LengthMSB=0, R_LengthLSB=0, R_API=0, R_AddrMSB=0, R_AddrLSB=0, R_SigStr=0, R_Options=0, R_CMD=0, R_RF1=0, R_FID=0, R_STATUS=0;

//----------------------------SSP Bytes
static signed char BytesOut[NumBytes];
static signed char BytesIn[NumBytes];
static unsigned char i=0;

///////////Handling Different Message Types
#define RESET 0
#define TAG_OUT 1
#define TAG_DETECTED 2
#define PLAYER_STATUS 3
#define REQ_PAIR 4
#define PAIR_RESP 5
#define CTRL 6


//MessageType CurrentType = TAG_DETECT;
static unsigned char CurrentType = CTRL;
static signed char TXData[6];
static unsigned char MessageCounter=0;
//Dummy Variables - Need Function Interfaces
static unsigned char TAGINFO = 0b00000111;
static unsigned char SDATA = 0b10011111;
static unsigned char PAIRDATA = 0b00000110;
static unsigned char RESPDATA = 0b00000111;
static signed char SPD = 127;
static signed char DIR = 50;
static unsigned char AUX = 0xff;
static unsigned char WHIM = 0;
static unsigned char TRANS = 0;


///Switch Response
unsigned char SwitchState = 0;
unsigned char SwitchMask = 0b00000111;
 
//COACH Behaviour
static unsigned char Paired = 0;
static unsigned char CommActive = 0;

//Temporary SPI Data Variable
static signed char SPI_Var = 0;

//PORTC Programming Issue
static unsigned char PORTC_Copy=0;


//----------------------------Function definitions
void InitTimers(void);
void InitPorts(void);
void InitComm(void);
void InitInterrupts(void);
void EvaluateMessage(void);
unsigned char Encode_Message (unsigned char);
signed char CalculateChecksum( void  );
void XBee_State (unsigned char x);
void Process_Status (unsigned char status);
void Process_SPI(void);
//-------------------------------------------------------------------
//----------------------------Code-----------------------------------
//-------------------------------------------------------------------
void main(void)
{
	// should only execute main loop once; after this just respond to interrupts
	InitTimers();	
	InitPorts();
	InitComm();
	InitInterrupts();
	SSPBUF = BytesOut[i];
	
	while(1)
	{		
		//-----------------------------------------------------------------------------------------		
		//-----------------------------------------------------------------------------------------
		//-----EUART STUFF-------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------
	if(CommActive)
	{

		if( X_Transition!=0 )
		{
			X_Transition = 0;

			switch( CurrentX_State )
			{
				case X_Idle_State :
				{
						SEND = 1;
						NextX_State = X_StartDelim_State;
						NextByteOut = 0x7E;	
						//	Starting Edit for Variable Message Size		
						MessageCounter = Encode_Message(CurrentType);	
						X_LengthLSB = MessageCounter + 5; //For framing bytes
						//  Populating the Message Frame
						X_CMD = TXData[0];
						X_RF1 = TXData[1];
						X_RF2 = TXData[2];
						X_RF3 = TXData[3];
					    X_RF4 = TXData[4];
						X_RF5 = TXData[5];
					
				}
				break;

				case X_StartDelim_State :
				{

					NextX_State = X_LengthMSB_State;
					NextByteOut = X_LengthMSB ; 
				}
				break;

				case X_LengthMSB_State :
				{
					NextX_State = X_LengthLSB_State;
					NextByteOut = X_LengthLSB; 
				}
				break;
	
				case X_LengthLSB_State :
				{
					NextX_State = X_API_State;
					NextByteOut = X_API; 
				}
				break;
	
				case X_API_State :
				{
					NextX_State = X_FID_State;
					NextByteOut = X_FID; 
				}
				break;
		
				case X_FID_State :
				{
					NextX_State = X_AddrMSB_State;
					NextByteOut = X_AddrMSB; 
				}
				break;

				case X_AddrMSB_State :
				{
					NextX_State = X_AddrLSB_State;
					NextByteOut = X_AddrLSB; 
				}
				break;
	
				case X_AddrLSB_State :
				{
					NextX_State = X_Options_State;
					NextByteOut = X_Options; 
				}
				break;

				case X_Options_State :
				{
					NextX_State = X_CMD_State; // will later need logic here for what transition to do based on length LSB
					NextByteOut = X_CMD; 
				}
				break;
	
				case X_CMD_State :
				{
					MessageCounter--;
					if(MessageCounter)
						{	
							NextX_State = X_RF1_State;
					     	NextByteOut = X_RF1; 
						}
					else
						{	
							NextX_State = X_Checksum_State;
							NextByteOut = CalculateChecksum(); 
      					}     
				}
				break;

				case X_RF1_State :
				{
					MessageCounter--;
					if(MessageCounter)
						{	
							NextX_State = X_RF2_State;
					     	NextByteOut = X_RF2; 
						}
					else
						{	
							NextX_State = X_Checksum_State;
							NextByteOut = CalculateChecksum(); 
      					}                   
				}
				break;

				case X_RF2_State :
				{
					MessageCounter--;
					if(MessageCounter)
						{	
							NextX_State = X_RF3_State;
					     	NextByteOut = X_RF3; 
						}
					else
						{	
							NextX_State = X_Checksum_State;
							NextByteOut = CalculateChecksum(); 
      					}  
				}
				break;

				case X_RF3_State :
				{
					MessageCounter--;
					if(MessageCounter)
						{	
							NextX_State = X_RF4_State;
					     	NextByteOut = X_RF4; 
						}
					else
						{	
							NextX_State = X_Checksum_State;
							NextByteOut = CalculateChecksum(); 
      					}  
				}
				break;

				case X_RF4_State :
				{
					MessageCounter--;
					if(MessageCounter)
						{	
							NextX_State = X_RF5_State;
					     	NextByteOut = X_RF5; 
						}
					else
						{	
							NextX_State = X_Checksum_State;
							NextByteOut = CalculateChecksum(); 
      					}  
				}
				break;

				case X_RF5_State :
				{
					NextX_State = X_Checksum_State;
					NextByteOut = CalculateChecksum(); 
				}
				break;
	
				case X_Checksum_State :
				{
					SEND = 0;
					NextX_State = X_Idle_State;	
					NextByteOut = 0x7E;
				}
				break;
			} // end switch case
		}// end if X_Transition

		if( R_Transition!=0 )
		{
			R_Transition = 0;

			switch( CurrentR_State )
			{
				case R_Idle_State :
				{
					if (ByteIn == 0x7E) // should always be this!	
					{ NextR_State = R_LengthMSB_State; }
				}
				break;

				case R_LengthMSB_State :
				{
					if ( ByteIn == 0x00 ) // should always be this!
					{ NextR_State = R_LengthLSB_State; }
				}
				break;
	
				case R_LengthLSB_State :
				{
					NextR_State = R_API_State;
					R_LengthLSB = ByteIn;
				}
				break;
	
				case R_API_State :
				{
				///Adding Code to Handle different types of received messages
					R_API = ByteIn; 
					if (R_API == API_TXSTAT)
						NextR_State = R_FID_State;
					else if (R_API == API_RXPACK)
						{
							NextR_State = R_AddrMSB_State;
							LostCommCounter = 0;
						}
					else
						NextR_State = R_Idle_State;
				}
				break;

				case R_AddrMSB_State :
				{
					NextR_State = R_AddrLSB_State;
					R_AddrMSB = ByteIn;
				}
				break;
	
				case R_AddrLSB_State :
				{
					NextR_State =R_SigStr_State;
					R_AddrLSB = ByteIn;
				}
				break;

				case R_SigStr_State :
				{
					NextR_State = R_Options_State;
					R_SigStr = ByteIn; 
				}
				break;

				case R_Options_State :
				{
					NextR_State = R_CMD_State; // will later need logic here for what transition to do based on length LSB
					R_Options = ByteIn; 
				}
				break;
	
				
				case R_CMD_State:
				{
					NextR_State = R_RF1_State;
					R_CMD = ByteIn;
					
				}
				break;

				case R_RF1_State :
				{	
					NextR_State = R_Idle_State;
					R_RF1 = ByteIn;
					if (R_CMD == 0x05)
						{	//PAIR_RESP Received
							
							if(R_RF1&BIT0HI)
								{
									Paired = 1;
									//Stop Broadcasting and send Direct Messages
									X_AddrMSB = R_AddrMSB;
				 					X_AddrLSB = R_AddrLSB;
									CurrentType = CTRL;
									Set_PAIRED;
									PORTC = PORTC_Copy;
									LostCommCounter = 0;

								}
							else
								{
									XBee_State(0);
								}

						}
					if (R_CMD == 0x06)
						{  //STATUS Received
							Process_Status(R_RF1);
						}
							
								
				}
				break;
				
								
				case R_FID_State :
				{
					NextR_State = R_STATUS_State;	
					R_FID = ByteIn; 
				}
				break;
				
				case R_STATUS_State :
				{
					NextR_State = R_Idle_State;	
					R_STATUS = ByteIn; 
					//Code to Resend Message if no ACK
					if (R_STATUS)
						{
							X_Transition = 1;
							CurrentX_State = X_Idle_State;
							NextX_State = CurrentX_State;
						}
				}
				break;
				
				

			} // end switch case
		}// end if R_Transition


		if (SEND && TXIF) // for some reason, with TXIE I get 0x7E transmitted twice. 
		{
			X_Transition = 1; 
			TXREG = NextByteOut;
		}

		CurrentX_State = NextX_State;
		CurrentR_State = NextR_State;

	}	
}

}; // end main



//----------------------------Function interrupt response
void interrupt ISR( void ) // must figure out what interrupt triggered it
{
	
//Disable Interrupts
	INTCON &= 0b00110111;

	if (RCIF) // receive interrupt
	{
		R_Transition = 1;
		ByteIn = RCREG; 		// save the byte 
		//LostCommCounter = 0; 	// reset the counter- we have active comm!	
	}

	if (SSPIF)
	{	
	
		RAISE_SS;
		PORTC = PORTC_Copy;
		SPI_Var = SSPBUF;  // read
		if (SPI_Var==AlignByte)
		i=0;

		BytesIn[i] = SPI_Var;
 
		i++;
			
		if(i>=NumBytes)
		{
			i=0;
			Process_SPI();
		}
 		
		
		LOWER_SS;
		PORTC = PORTC_Copy;
	
		SSPBUF = BytesOut[i]; // write
		SSPIF = 0;
	}	
	
	if (TMR2IF) // 38.2 Hz timeout if at 10MHz, 76.5 Hz if at 20MHz
	{
		
		TOCounter++;
		
		if (TOCounter>=78) // 5 Hz TO
		{	
			
			TOCounter = 0;
			X_Transition = 1;
			CurrentX_State = X_Idle_State;
			NextX_State = CurrentX_State;

			LostCommCounter++; 
			if (LostCommCounter>=25)
			{
				LostCommCounter = 0;
				// ACTIVATE THIS IS IN FINAL BUILD
		    	XBee_State(0);///JUST Commented for TESTING -- NEEDED IN PRODUCTION CODE
				// throw error!
			}
		}
		TMR2IF = 0;
	} // end if TMR2IF
	
	if (RABIF)
	{	
		SwitchState = PORTA;
		SwitchState &= SwitchMask;
		if(SwitchState == 0b00000001)
			{	
				CurrentType = RESET;
				//Clear_COMM_Error;
			}
		if(SwitchState == 0b00000010)
			{
				CurrentType = TAG_OUT;
			}
		if(SwitchState == 0b00000100)
			{
				///Starts the Communication Procedure by Broadcasting a Pair Message
				CurrentType = REQ_PAIR;
				//LostCommCounter = 0;
				XBee_State(1);
				//CurrentX_State = X_Idle_State;
				
			}
		RABIF = 0;
	}

//Renable Interrupts
	INTCON |= 0b11001000;		
	return;
}


//----------------------------Function InitTimers
void InitTimers(void)
{
	T2CON 	= 0b01111110; // (Fosc)/(4 instruc * 16 prescale * 16 postscale * 50 PR2 count)=390 Hz
	PR2 	= 50; 
}

//----------------------------Function InitPorts
void InitPorts( void )
{	
    // setup I/O, analog   
    ANSEL 	= 0;     		 // <1:0> are analog for accelerometers
    ANSELH 	= 0;
    TRISA 	= 0b00111111;    // Input=1, Output=0
    TRISB 	= 0b00110000;	
    TRISC 	= 0b00000000;	// slave select is an output
    // initialize outputs to off
    PORTA = 0; 
    PORTB = 0;
    PORTC = BIT4HI; // XBee reset off
}

//----------------------------Function InitInterrupts
void InitInterrupts(void)
{
    // Communication interrupts for receive, transmit
	// Timer2 overflows for 5Hz time-outs
	INTCON 	= 0b11001000; // set GIE, set PEIE
	RCIE	= 1;
	TMR2IE	= 1;
	SSPIE	= 1;
	PIR1 	= 0;
	//New Code for Pin Change Interrupts on PORTA0:2
	IOCA = (BIT0HI|BIT1HI|BIT2HI);
}

//----------------------------Function InitComm
void InitComm( void )
{
	// setup EUSART for comm w/ Xbee
	SPBRG 	= 129; // SPBRG = Fosc / (16 * BR ) - 1 
	SPBRGH 	= 0;  // 129 for 20MHz, 64 for 10 MHz
	TXSTA 	= 0b00100100;	// TXEN set, BRGH set, 8 bit trans, async
	RCSTA 	= 0b10010000;	// SPEN set, 8 bit receive, CREN set, no addr detection


	// setup SSP (SPI) for comm w/ Slave PIC
	SSPSTAT = 0; // data on rising edge, data @ middle
	WCOL = 0; 	// no collision
	SSPOV = 0; 	// no overflow
	SSPEN = 1; 	// ssp enable
	CKP = 1;	// idle high
	SSPM3 = 0; //SPI Master, Clock -> 0010 = Fosc/64; 0011 = TMR2/2
	SSPM2 = 0;
	SSPM1 = 1;
	SSPM0 = 1;

	LOWER_SS;
	PORTC = PORTC_Copy;
	
	BytesOut[0] = AlignByte;
	BytesOut[1] = SDATA;
	BytesOut[2] = 0x00;
	BytesOut[3] = 0x00;
	BytesOut[4] = 0x00;
	BytesOut[5] = 0x00;
	BytesOut[6] = 0x00;
	BytesOut[7] = 0x00;
	
	BytesIn[0] = 0;
	BytesIn[1] = 0;
	BytesIn[2] = 0;
	BytesIn[3] = 0;
	BytesIn[4] = 0;
	BytesIn[5] = 0;
	BytesIn[6] = 0;
	BytesIn[7] = 0;
}

//----------------------------Function CalculateChecksum
signed char CalculateChecksum( void  )
{
	signed char checksum = 0xFF;
	
	checksum -= ( X_API + X_FID + X_AddrMSB + X_AddrLSB + X_Options + X_CMD  );

	if (X_LengthLSB > 6)
	{	checksum -= X_RF1;	}
	if (X_LengthLSB > 7)
	{	checksum -= X_RF2;	}
	if (X_LengthLSB > 8)
	{	checksum -= X_RF3;	}
	if (X_LengthLSB > 9)
	{	checksum -= X_RF4;	}
	if (X_LengthLSB > 10)
	{	checksum -= X_RF5;	}
	
	return checksum;
}

///////
void Process_Status (unsigned char status)
{
	SDATA = status;
}

//----------------------------Function InitiatePairing
void InitiatePairing(void)
{
	// should  occur upon reset
	// broadcast a REQ_PAIR message: 
		// contains jersey number of the PLAYER to which the COACH wishes to pair (read PlayerSelectBits)
		// & the team color that the coach is playing for (read TeamSelectBit)
}

void XBee_State (unsigned char x)
{
	if(x)
		{	
			CommActive = 1;
			CurrentR_State = R_Idle_State;
			CurrentX_State = X_Idle_State;
			Clear_PAIR_Error;
			Set_COMM_Error;
			LostCommCounter = 0;
			PORTC = PORTC_Copy;
		}
	else
		{
			LostCommCounter = 0;		
			CommActive = 0;
			Clear_COMM_Error;
			Clear_PAIRED;
			Set_PAIR_Error;
			PORTC = PORTC_Copy;
			
		}
}
			
		

////Encode Function
unsigned char Encode_Message (unsigned char Type)
{
 	 /* The input argument type is enumerated can hold one of the following values
 	 RESET
 	 TAG_OUT
 	 TAG_DETECTED
 	 PLAYER_STATUS
 	 REQ_PAIR
 	 PAIR_RESP
 	 CTRL
 	 */
 	 unsigned char Length = 0;

 	 switch (Type)
 	 	{
 	 	 	case RESET:
 	 	 		{
 	 	 		  //Construct a Reset Message
 	 	 		  TXData[0] = 0x04;
				  TXData[1] = 0;
 	 	 		  TXData[2] = 0;
 	 	 		  TXData[3] = 0;
 	 	 		  TXData[4] = 0;
 	 	 		  TXData[5] = 0;	
 	 	 		  Length = 1;
 	 	 		  
 	 	 		  
 	 	 		}
 	 	 	break;
 	 	 	
 	 	 	case TAG_OUT:
 	 	 		{
 	 	 		  //Construct a Tag Out Message
 	 	 		  TXData[0] = 0x02;
 	 	 		  TXData[1] = TAGINFO;
				  TXData[2] = 0;
 	 	 		  TXData[3] = 0;
 	 	 		  TXData[4] = 0;
 	 	 		  TXData[5] = 0;
 	 	 		  Length = 2;
 	 	 		  
 	 	 		}
 	 	 	break;
 	 	
			
 	 	    case TAG_DETECTED:
 	 	 		{
 	 	 		  //Construct a Tag Detected Message
 	 	 		  TXData[0] = 0x07;
 	 	 		  TXData[1] = TAGINFO;
				  TXData[2] = 0;
 	 	 		  TXData[3] = 0;
 	 	 		  TXData[4] = 0;
 	 	 		  TXData[5] = 0;
 	 	 		  Length = 2;
 	 	 		  
 	 	 		  
 	 	 		}
 	 	 	break;
		 	
 	 	    case PLAYER_STATUS:
 	 	 		{
 	 	 		  //Construct a Status Message
 	 	 		  TXData[0] = 0x06;
 	 	 		  TXData[1] = SDATA;
				  TXData[2] = 0;
 	 	 		  TXData[3] = 0;
 	 	 		  TXData[4] = 0;
 	 	 		  TXData[5] = 0;
 	 	 		  Length = 2;
 	 	 		  
 	 	 		}
 	 	 	break;
 	
 			case REQ_PAIR:
 	 	 		{
 	 	 		  //Construct a Pair Request Message
 	 	 		  TXData[0] = 0x03;
 	 	 		  TXData[1] = PAIRDATA;
				  TXData[2] = 0;
 	 	 		  TXData[3] = 0;
 	 	 		  TXData[4] = 0;
 	 	 		  TXData[5] = 0;
 	 	 		  Length = 2;
				  //Set Message to BroadCast	 
 	 	 		  X_AddrMSB = 0xff;
				  X_AddrLSB = 0xff;
 	 	 		}
 	 	 	break;
  	 	

	  		case PAIR_RESP:
 	 	 		{
 	 	 		  //Construct a Pair Respons Message
 	 	 		  TXData[0] = 0x05;
 	 	 		  TXData[1] = RESPDATA;
				  TXData[2] = 0;
 	 	 		  TXData[3] = 0;
 	 	 		  TXData[4] = 0;
 	 	 		  TXData[5] = 0;
 	 	 		  Length = 2;
 	 	 		  
 	 	 		}
 	 	 	break;

			case CTRL:
 	 	 		{
 	 	 		  //Contruct a Control Message
 	 	 		  TXData[0] = 0x01;
 	 	 		  TXData[1] = SPD;
 	 	 		  TXData[2] = DIR;
 	 	 		  TXData[3] = AUX;
 	 	 		  TXData[4] = WHIM;
 	 	 		  TXData[5] = TRANS;
 	 	 		  Length = 6;
 	 	 		  SendKick = 0;
 	 	 		  SendWhimsy = 0; 
				  PORTC &= ~BIT3HI;
 	 	 		}
 	 	 	break;
 	 	 	
 	 	 	default:
 	 	 	Length = 0;
 	 	 	
 	 	 }
return Length;

}

void Process_SPI(void)
{
	if ( BytesIn[5] != 0)
	{
		PORTC |= BIT3HI;
		SendKick = 0x0F;
	}
	if ( BytesIn[6] != 0)
	{
		//PORTC |= BIT3HI;
		SendWhimsy = 0xFF;
	}
	//Process Incoming Bytes
	if ((BytesIn[0]==AlignByte)&&(BytesIn[7]==0x00))
	{
		PAIRDATA = BytesIn[1];
		SPD = BytesIn[2];
		DIR = BytesIn[3];
		AUX = SendKick;		
		WHIM = SendWhimsy;
		TRANS = 0;		
	}
	//Process the Outgoing Byte
	BytesOut[1] = SDATA;
}