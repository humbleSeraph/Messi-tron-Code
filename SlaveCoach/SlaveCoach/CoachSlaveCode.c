/*
    Natalie Burkhard  05/05/14
    Slave PIC code for SPI comm with the Coach Master PIC, PIC16F690

SLAVE PIC
------------------------------------------------------------------
1        +5              Vdd       Vss       GND                20
2       Energy_1(out)!	 A5        A0       Accel_L(in)		    19
3       LED				 A4        A1       Accel_R(in)	        18
4       Magnet_L(in)!    A3        A2       Mic(in)!		 	17
5       DirecSel(in)     C5        C0       Player_1(in)		16
6       TeamSelect(in)	 C4        C1       Player_2(in)	    15
7       Player_4(in)	 C3        C2       Player_3(in)	    14
8        _SS (in)!		 C6        B4       SDI(in)		  		13
9       SDO (out)!	 	 C7        B5       Energy_3(out)!		12
10      Energy_2(out)!	 B7        B6       SCK(in)     		11
-------------------------------------------------------------------

	will be asked for speed, direction, braking, kicking, whimsy, translation (L or R)
	will need to update Act Comm display, energy level display 
	update sensor reanigs at 4 Hz (using internal oscillator; may not be perfect)
*/

#include "CoachSlaveCode.h"

__CONFIG( CP_OFF & WDTE_OFF & PWRTE_ON & FOSC_INTRCIO & MCLRE_OFF );

//----------------------------Bits & Ports
#define ACTIVE_ON	PORTB|=BIT7HI
#define ACTIVE_OFF	PORTB&=(~BIT7HI)
//----------------------------Comm
#define NumBytes	8
#define AlignByte	0x37

#define Dummy	0
#define Player	1
#define Speed	2
#define Direc	3
#define Brake	4
#define Kick	5
#define Whimsy	6
#define Trans	7

#define MaxADC 

signed char BytesOut[NumBytes];
signed char BytesIn[NumBytes];

//Sensor Interface Variables
static unsigned char NominalAccelerationLeft = 0;
static unsigned char NominalAccelerationRight = 0;
static unsigned char LeftThrust = 0;
static unsigned char RightThrust = 0;
static unsigned char LeftCrossingFlag = 0;
static unsigned char RightCrossingFlag = 0;
//Adding temporary variables for potentiometer controls
static signed char LeftTemp = 0;
static signed char RightTemp = 0;

// Variable to hold whether we should kick on next SSP send
static signed char Microphone = 0, MagnetL = 0;

static unsigned char LeftZCR = 0;
static unsigned char RightZCR = 0;

//----------------------------Comm Variables
static unsigned char TOCounter = 0;
static unsigned char ActiveCommuncation = 0; // holds whether or not we have active communication
static unsigned char i = 0; // which byte we're transmitting
//----------------------------Function definitions
void InitTimers(void);
void InitPorts(void);
void InitComm(void);
void InitInterrupts(void);

signed char ReadPlayer( void );
void ReadKick( void );
void ReadWhimsy( void );
signed char ReadTrans( void );
void UpdateEnergy( signed char x );
void Initialize_Sensors(void);
void Read_Thrust(void);

//-------------------------------------------------------------------
//----------------------------Code-----------------------------------
//-------------------------------------------------------------------
void main(void)
{
	InitTimers();	
	InitPorts();
	InitComm();
	InitInterrupts();
	Initialize_Sensors();

	while(1)
	{
		// continuously check for audio or magnets
		ReadKick();
		ReadWhimsy();
	} // end while(1)

}; // end main
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------



//----------------------------Function interrupt response
void interrupt ISR( void )
{
	if (SSPIF)
	{			
		BytesIn[i] = SSPBUF;
		SSPBUF = BytesOut[i];
		i++;
		if(i>=7)
		{
			i=0; 
			// reset dynamic read sensor variables
			Microphone = 0; 
			MagnetL = 0; 
		}

		SSPIF = 0;
	}// end if SSPIF


	if (TMR2IF)
	{
		TOCounter++;
		Read_Thrust();
		ReadKick();
		ReadWhimsy();

		//if(TOCounter==2)
		//{
			UpdateEnergy(BytesIn[1]);
		//}

		//if (TOCounter==2) //update bytes @ 10 Hz
		//{
			BytesOut[Dummy]		= AlignByte; // 0x37
			BytesOut[Player]	= ReadPlayer(); // 0x18- static
			BytesOut[Speed] 	= LeftTemp;
			BytesOut[Direc] 	= RightTemp;
			BytesOut[Brake] 	= 0;
			BytesOut[Kick] 		= Microphone; // dynamic read
			BytesOut[Whimsy] 	= MagnetL; // dynamic read
			BytesOut[Trans] 	= 0;
			TOCounter = 0;
		//}

		TMR2IF = 0;
	} // end if TMR2IF

	return;
}

//----------------------------
signed char ReadPlayer( void )
{
	// read PortC<3:0> for player select inputs
	unsigned char x=0;
	x = PORTC & 0b00011111 ;
	return x;
}

//----------------------------
void ReadKick( void )
{
	//Code to catch microphone signal, gets reset when sending that byte
	if( ( (PORTA & BIT2HI)==0 )	||( (PORTA & BIT3HI)==0 ) ) // microphone or magL
	{ 
		Microphone = 0xFF;  // also contains MagL info
	}
}

//-----------------------------------------------------------------------
void Read_Thrust(void)
{	
	//Reads the Accelerometer Values and updates the module level variables
	//First Read RA0
	ADCON0 = (BIT0HI);
	ADCON0 |= BIT1HI;
	while (ADCON0 & BIT1HI)
	;
	LeftThrust = ADRESH;
	LeftTemp = (signed char) LeftThrust;
	if (LeftTemp < 0)
	LeftTemp = LeftTemp + 128;
	else
	LeftTemp = LeftTemp - 127;
	LeftTemp = -LeftTemp;

	//Second Read RA1
	ADCON0 = (BIT2HI|BIT0HI);
	ADCON0 |= BIT1HI;
	while (ADCON0 & BIT1HI)
	;
	RightThrust = ADRESH;
	RightTemp = (signed char) RightThrust;
	if (RightTemp < 0)
	RightTemp = RightTemp + 128;
	else
	RightTemp = RightTemp - 127;
	RightTemp = -RightTemp;
}

//----------------------------
void ReadWhimsy( void )
{
	// read PortA<4:3> for magnets 
	if ( (PORTA & BIT3HI)==0 )
	{
		MagnetL = 0xFF;
	}
}

//----------------------------
void UpdateEnergy( signed char x )
{
	if( (x & BIT0HI)!=0)
	{ PORTA &= ~BIT5HI; }
	else
	{ PORTA |= BIT5HI; }

	if( (x & BIT1HI)!=0)
	{ PORTB &= ~BIT7HI; }
	else
	{ PORTB |= BIT7HI; }

	if( (x & BIT2HI)!=0)
	{ PORTB &= ~BIT5HI; }
	else
	{ PORTB |= BIT5HI; }
}

//----------------------------Function InitTimers
void InitTimers(void)
{
	// setup internal timer for 1 MHz, int osc, internal oscillator used for system clock
	OSCCON = 0b01000001;
	// set up timer 2
	T2CON 	= 0b01111110; // (Fosc)/(4 instruc * 16 prescale * 16 postscale * 255 PR2 count) = 38.2 Hz
	PR2 	= 255;
}

//----------------------------Function InitPorts
void InitPorts( void )
{	
    // setup I/O, analog   
    ANSEL 	= 0b00000011;	 // <1:0> are analog for accelerometers
    ANSELH 	= 0;
    TRISA 	= 0b00001111;    // Input=1, Output=0
    TRISB 	= 0b01010000;
    TRISC 	= 0b01111111;
	PORTA = 0b00100000; // init energy level to high so #8 turns on (not used, so all others are off)
	PORTB = 0b10100000; // init energy level to high
	PORTC = 0;
}

//----------------------------Function InitInterrupts
void InitInterrupts(void)
{
    // Communication interrupts for receive, transmit
	// Timer2 overflows for 5Hz time-outs
	INTCON 	= 0b11000000; // set GIE, set PEIE
	TMR2IE	= 1;
	SSPIE	= 1;
	PIR1 	= 0;
}

//----------------------------Function InitComm
void InitComm( void )
{
	// setup SSP (SPI analog) for comm w/ Xbee PIC (master)
	SSPSTAT = 0; // data on rising edge, data @ middle
	WCOL = 0; 	// no collision
	SSPOV = 0; 	// no overflow
	SSPEN = 1; 	// ssp enable
	CKP = 1;	// idle high	
	SSPM3 = 0; //0100 SPI Slave, clk=SCK pin, SS enabled
	SSPM2 = 1;
	SSPM1 = 0;
	SSPM0 = 0;

	// initialize bytes
	BytesOut[Player]	= ReadPlayer();
	BytesOut[Speed] 	= LeftTemp;
	BytesOut[Direc] 	= RightTemp;
	BytesOut[Brake] 	= 0;
	BytesOut[Kick] 		= Microphone;
	BytesOut[Whimsy] 	= MagnetL;
	BytesOut[Trans] 	= 0;
	
	BytesIn[1] = 0;
}

//-----------------------------------------------------------------------
////Sensor Interfaces
void Initialize_Sensors(void)
{	
	//Clock Divisor = 32
	ADCON1 = BIT5HI; //ADFM = 0 for Left Justified

	//Setup NominalAcceleration (Self Calibration Process)

	//First Read RA0
	ADCON0 = (BIT0HI);
	ADCON0 |= BIT1HI;
	while (ADCON0 & BIT1HI)
	;
	NominalAccelerationLeft = ADRESH;

	//Second Read RA1
	ADCON0 = (BIT2HI|BIT0HI);
	ADCON0 |= BIT1HI;
	while (ADCON0 & BIT1HI)
	;
	NominalAccelerationRight = ADRESH;
}