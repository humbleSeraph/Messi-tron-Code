/****************************************************************************
Module
TemplateFSM.c

Reviion
1.0.1

Description
This is a template file for implementing flat state machines under the
Gen2 Events and Services Framework.

Notes

History
When           Who     What/Why
-------------- ---     --------
01/15/12 11:12 jec      revisions for Gen2 framework
11/07/11 11:26 jec      made the queue static
10/30/11 17:59 jec      fixed references to CurrentEvent in RunTemplateSM()
10/23/11 18:20 jec      began conversion from SMTemplate.c (02/20/07 rev)
****************************************************************************/
/*----------------------------- Include Files -----------------------------*/
/* include header files for this state machine as well as any machines at the
next lower level in the hierarchy that are sub-machines to this machine
*/
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "TemplateFSM.h"
#include "PlayerTransmitSM.h"
#include "PlayerBrainSM.h"
#include "PropellerModule.h" 
#include "PlayerLiFKIM.h"

#include <ADS12.h>
#include "Bin_Const.h"
#include "bitdefs.h"  
#include "ES_Types.h"
#include <hidef.h> 
#include <mc9s12e128.h>
#include <s12E128bits.h>
#include "S12eVec.h"
#include <stdio.h>
#include <stdlib.h>
#include <termio.h>
/*----------------------------- Module Defines ----------------------------*/

#define Transmit_Debug

#define _MS_ *187.5
#define TRANSMIT_RATE (200_MS_)
#define INTRA_TRANSMIT_RATE (10_MS_)
/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this machine.They should be functions
relevant to the behavior of this state machine
*/

void InitTxSCI(void);
void InitTxSPI(void);
void InitTxPorts(void);
void InitTxTimers(void); 

void Build_Response(char byte, int i); 
void Build_Address(char byte, int i); 

/*---------------------------- Module Variables ---------------------------*/
// everybody needs a state variable, you may need others as well.
// type of state variable should match htat of enum in header file
static TemplateState_t CurrentState;
static TemplateState_t CurrentSubState;

// with the introduction of Gen2, we need a module level Priority var as well
static uint8_t MyPriority;
static char sumCounter = 0;  




static char transmitCounter;
int transmitFlag;


char ThisState;
char LastState; 
char LED_value; 



char DelimR;
char LengthByte_MSB; 
char LengthByte_LSB;
char APIiD;
char FrameID;
char Status;
char givenCheckSum;
char SourceAdd_MSB;
char SourceAdd_LSB;
char SignalStrength;
char Receive_Options;
char responseArray [6]; 
char addressArray [2]; 
static int j = 0;
int addr = 0; 
int responseCounter = 0;
static unsigned char commActive; 


/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
Function
 InitTemplateFSM

Parameters
 uint8_t : the priorty of this service

Returns
 bool, false if error in initialization, true otherwise

Description
 Saves away the priority, sets up the initial transition and does any
 other required initialization for this state machine
Notes

Author
 J. Edward Carryer, 10/23/11, 18:55
****************************************************************************/
 bool InitPlayerTransmitSM ( uint8_t Priority )
 {
  ES_Event ThisEvent;

  MyPriority = Priority;
// put us into the Initial PseudoState
  
  CurrentState = Sleep; 
  CurrentSubState = Send_Delim;
// post the initial transition event
  ThisEvent.EventType = ES_INIT;


  InitTxSCI();
  //InitTxSPI();
  InitTxPorts();
  InitTxTimers();  
  
  
  //ES_Timer_InitTimer(1, 195);
  
  
  transmitFlag = 0;
  responseCounter = 0;
  addr = 0; 
  commActive = 0;
  
  if (ES_PostToService( MyPriority, ThisEvent) == true)
  {
	return true;
  }else
  {
	return false;
  }
}

void InitTxSCI()
{
//SCI1BDH = 0x00;  // IREN = 0, SBR<12:8>=0, others don't care
SCI1BDL = 155; // 10011011,  SBR<7:0>=n=155, BR = 9600Hz = 24MHz/(16*(n+1))

SCI1CR1 &= ~_S12_LOOPS;  // LOOPS=0, M=0, PE=0, others don't care
SCI1CR1 &= ~_S12_M;  
SCI1CR1 &= ~_S12_PE;

SCI1CR2 |= ( _S12_TE | _S12_RE); // 01101100- RIE=1, TE=1, RE=1- INTERRUPT on RIE
// with RIE interrupt, must clear OR and RDRF flags

}

void InitTxPorts()
{

// put relevant port assignments here 

DDRS |= BIT3HI;
DDRS &= BIT2LO;

DDRP |= BIT1HI | BIT3HI | BIT4HI | BIT5HI; 
PTP |= BIT5HI | BIT4HI | BIT3HI | BIT1HI;




}

void InitTxTimers()
{
/*************************** using Timer 0, Channel 4 ***************************/



// turn timer system on
TIM0_TSCR1 = _S12_TEN;  

// set prescale clock to /128 = 187.5kHz
TIM0_TSCR2 = _S12_PR0 | _S12_PR1 | _S12_PR2;


/********************* set up for SendMessage Timer, should send e'rry 5Hz ******************/



TIM0_TIOS |= _S12_IOS4;                               //set up comp 4 to OC, leave the rest alone
TIM0_TCTL1 &= ~(_S12_OL4 | _S12_OM4);                 //no pin connected for OC4
TIM0_TC4 = TIM0_TCNT + TRANSMIT_RATE;                 //sched first rise
TIM0_TFLG1 = _S12_C4F;                                //clear OC4 Flag
TIM0_TIE |= _S12_C4I;                                 //enable OC4 Interrupt 




/******************* set up for intramessage Timer, sends every .4 ms ****************/



/*

TIM0_TIOS |= _S12_IOS6;                               //set up comp 4 to OC, leave the rest alone
TIM0_TCTL1 &= ~(_S12_OL6 | _S12_OM6);                 //no pin connected for OC4
TIM0_TC4 = TIM0_TCNT + INTRA_TRANSMIT_RATE;                 //sched first rise
TIM0_TFLG1 = _S12_C6F;                                //clear OC4 Flag
TIM0_TIE |= _S12_C6I;                                 //enable OC4 Interrupt 
 
*/


EnableInterrupts;     

}



void interrupt _Vec_tim0ch4 MessageTimer(void)
{
	ES_Event ThisEvent;


	//DisableInterrupts; 


	//printf("t4");
	
	TIM0_TFLG1 = _S12_C4F;


	

	transmitFlag = 1;
	ThisEvent.EventType = TRANSMIT;
	PostPlayerTransmitSM(ThisEvent);


	PTP ^= BIT5HI;
	//printf("hr\n\r"); 

	TIM0_TC4 += TRANSMIT_RATE; 
	
	//EnableInterrupts; 


}






void Build_Response (char byte, int i)
{

responseArray[i] = byte;

}

void Build_Address(char addrbyte, int i)
{

addressArray[i] = addrbyte;

}



/****************************************************************************
Function
 PostTemplateFSM

Parameters
 EF_Event ThisEvent , the event to post to the queue

Returns
 boolean False if the Enqueue operation failed, True otherwise

Description
 Posts an event to this state machine's queue
Notes

Author
 J. Edward Carryer, 10/23/11, 19:25
****************************************************************************/
 bool PostPlayerTransmitSM( ES_Event ThisEvent )
{
  return ES_PostToService( MyPriority, ThisEvent);
}

/****************************************************************************
Function
RunTemplateFSM

Parameters
ES_Event : the event to process

Returns
ES_Event, ES_NO_EVENT if no error ES_ERROR otherwise

Description
add your description here
Notes
uses nested switch/case to implement the machine.
Author
J. Edward Carryer, 01/15/12, 15:23
****************************************************************************/
ES_Event RunPlayerTransmitSM( ES_Event ThisEvent )
{


/************ variables to store bytes when Receiving Message ***************/


char TR_CheckSum;
char TR_pseudoCheckSum; 
char DataIn;
ES_Event ThatEvent; 



/*********************************************************************************/

TemplateState_t NextState = CurrentState;
TemplateState_t NextSubState = CurrentSubState;

ES_Event PTSMEvent;
ES_Event PTSMIIEvent;

char transmitSum = 0x00; 
char checkSum = 0x00;  
char receiveSum = 0x00;




ES_Event ReturnEvent;
ReturnEvent.EventType = ES_NO_EVENT; // assume no errors

	if (transmitFlag == 1)
	{

		switch (CurrentState)
		{

			case Sleep:
			
				PTP ^= BIT1HI;
				
				NextState = Sleep; 
				
				//printf("sleeping\n\r");
				
				if (ThisEvent.EventType == COACH_CALL)
				{
					
					NextState = Response; 
					PTP |= BIT1HI;
					
				}
				
				if (ThisEvent.EventType == CAN_TRANSMIT)
				{

					NextState = SendStatus;
					printf("gcll\n\r");
				
				}
			
			break;
			
			case Response:
			
				PTP &= BIT3LO; 
				//PTU ^= BIT4HI;
				

			
				/*
				if (ThisEvent.EventType == TIME_OUT)
				
				{
					NextState = Sleep; 
				
				
				}
				*/
				
				if (ThisEvent.EventType == TRANSMIT)
				{
					
									
						switch (CurrentSubState)
						{
							 case Send_Delim:

								  //must read SCI1SR1 before transmitting doing it here bec it's the first transmit

								  if ((SCI1SR1 & 0xFF) == SCI1SR1)                    
								  { 

									SCI1DRL = 0x7E;
									
					
									NextSubState = Send_LengthByte_MSB;
									
									
									//printf("a0\n\r");
									
									
									//printf ("1:%X \n\r", 0x7E);



									
								  }

							  break;

							  case Send_LengthByte_MSB:

								  SCI1DRL = 0x00;  
								  
						
								  NextSubState = Send_LengthByte_LSB;
								  
								  //printf ("2:%X \n\r", 0x00);
								  
								  
									//printf("b0\n\r");

					
								  



							  break;

							  case Send_LengthByte_LSB:

								  SCI1DRL = 0x07;                                      //test message will be two bytes long
								  
			
								  NextSubState = Send_APIiD; 
								  
								  transmitCounter = 0x02; 
								  
								  
								  //printf("c0\n\r");

								  //printf ("3:%X \n\r", 0x07);

								  

								  


							  break; 

							  case Send_APIiD:

								  SCI1DRL = 0x01;
						
								  NextSubState = Send_FrameID;
								  
								  //printf ("4:%X \n\r", 0x01);


								  sumCounter += 0x01;
								  
								  //printf ("d0\n\r"); 

								  
								  

							  break; 

							  case Send_FrameID:

								  SCI1DRL = 0x01;
								  
			
								  NextSubState = Send_DestAddress_MSB;

								  sumCounter += 0x01;
								  
								 
								  //printf ("5:%X \n\r", 0x01);

								   #ifdef Transmit_Debug

								  //printf ("a:%X \n\r", sumCounter); 

									#endif


							  break;

							  case Send_DestAddress_MSB:

								  SCI1DRL = addressArray[addr];
								  
								  sumCounter += addressArray[addr];
								  
								  //SCI1DRL = 0x20;
								  
								  //sumCounter += 0x20; 
								  
								  //printf ("6:%X \n\r", addressArray[addr]);
								  
								  addr++; 
								  
								  NextSubState = Send_DestAddress_LSB;

								  
								 

								   #ifdef Transmit_Debug

								  //printf ("b: %X \n\r", sumCounter); 

									#endif

							  break; 

							  case Send_DestAddress_LSB:

								  SCI1DRL = addressArray[addr];  

								  sumCounter += addressArray[addr];
								  
								  //SCI1DRL = 0x80;
								  
								  //sumCounter += 0x80; 
								  
								  //printf ("7:%X \n\r", addressArray[addr]);
								  
								  NextSubState = Send_Options;

								
								   #ifdef Transmit_Debug

								  //printf ("c: %X \n\r", sumCounter); 

									#endif 

							  break; 

							  case Send_Options:

								  SCI1DRL = 0x00;
								  
								  sumCounter += 0x00;
								  
								  //printf ("8:%X \n\r", 0x00);
								  
								  NextSubState = Send_DataOut;
								  

							  

								
								  #ifdef Transmit_Debug

								  //printf ("d:%X \n\r", sumCounter); 

								  #endif

							  break;

							  case Send_DataOut: 

								  SCI1DRL = responseArray[j];
								  
								  sumCounter += responseArray[j];
								  
								  transmitCounter--;

								  
								  #ifdef Transmit_Debug

								  //printf ("m:%X \n\r", responseArray[j]); 

								  #endif
								  
								  j++;
								  
								  if (transmitCounter > 0)
								  {
									NextSubState = Send_DataOut;
									

									

								  }
								  else
								  {
									NextSubState = CheckSum;
									//printf("val:%i\n\r",j);	
								

								  } 

								  

							  break; 

							  case CheckSum:

								  checkSum = 0xFF - sumCounter; 
								  
								  //printf("10:%X \n\r", checkSum); 
								  
								  SCI1DRL = checkSum; 

								  NextSubState = Send_Delim;

								  
								

								  //SCI1CR2 &= ~(_S12_TCIE); 

								  #ifdef Transmit_Debug

								  //printf ("f:%X \n\r", sumCounter); 

								  #endif
								  

								  
								  transmitFlag = 0;
								  sumCounter = 0;
								  j = 0; 
								  addr = 0;
								 


							  break; 
						}
					
						//printf("hur\n\r"); 
				
				
						PTP |= BIT3HI;	
						NextState = Response; 
						
						
						if (QueryPlayerBrainSM() == Paired)
						
						{
						
						PTP |= BIT3HI; 
						NextState = SendStatus;
						
						//printf("qbr\n\r");
						}
						

					
					
					
				}
			
			break;
			
			case SendStatus: 
			
				PTP ^= BIT4HI;
			 
				if (ThisEvent.EventType == TAG_OUT)
				{
				
					NextState = Sleep; 
					PTP |= BIT4HI;
					//printf("tag\n\r");
				
				}
				
				else if (ThisEvent.EventType == ES_TIMEOUT)
				
				{

					NextState = Sleep; 
					PTP |= BIT4HI; 

				}

			
				if (ThisEvent.EventType == TRANSMIT)
				{
					switch (CurrentSubState)
					{
						case Send_Delim:

							  //must read SCI1SR1 before transmitting doing it here bec it's the first transmit



									//printf("a0\n\r");
									
									
									if (SCI1SR1 & _S12_TDRE)
									{
									
									SCI1DRL = 0x7E;
									NextSubState = Send_LengthByte_MSB;
									
									}
									
					
									NextSubState = Send_LengthByte_MSB;


								
								
				
								//NextSubState = Send_LengthByte_MSB;

								//printf("ssdelim\n\r");
								//printf ("1:%X \n\r", 0x7E);

						  break;

						  case Send_LengthByte_MSB:

							  
							  
							  //printf("b0\n\r"); 

									if (SCI1SR1 & _S12_TDRE)
									{
									
									SCI1DRL = 0x00;  
									NextSubState = Send_LengthByte_LSB;
									
									}
									

							  
					
							  
							  
							  //printf("b0\n\r"); 
							  
							  //printf("ssdelbm\n\r");

							  //printf ("2:%X \n\r", 0x00);

						  break;

						  case Send_LengthByte_LSB:

							  
							 if (SCI1SR1 & _S12_TDRE)
							{
							  
							  SCI1DRL = 0x07;                                      //test message will be two bytes long
							  
		
							  NextSubState = Send_APIiD; 
							  
							  transmitCounter = 0x02;
							 }
								

							  
							  //printf ("3:%X \n\r", 0x07);

						  break; 

						  case Send_APIiD:

							  
							if (SCI1SR1 & _S12_TDRE)
							{
							  SCI1DRL = 0x01;
							  
							  

							  NextSubState = Send_FrameID;
							  
							  //printf ("4:%X \n\r", 0x01);


							  sumCounter += 0x01;
							  
							 }

							  


						  break; 

						  case Send_FrameID:
						  
						  
						  	if (SCI1SR1 & _S12_TDRE)
							{

							  SCI1DRL = 0x01;
							  
		
							  NextSubState = Send_DestAddress_MSB;

							  sumCounter += 0x01;
							  
							  
							}

							  
							  //printf ("5:%X \n\r", 0x01);
							  

							  

							   #ifdef Transmit_Debug

							  //printf ("a:%X \n\r", sumCounter); 

								#endif

						  break;

						  case Send_DestAddress_MSB:
						  
					  
							if (SCI1SR1 & _S12_TDRE)
							{

							  SCI1DRL = addressArray[addr];
							  
							  sumCounter += addressArray[addr];
							  
							  //SCI1DRL = 0x20;
							  
							  //sumCounter += 0x20; 
							  
							  //printf ("6:%X \n\r", addressArray[addr]);
							  //printf("a:%i\n\r", addr);
							  
							  addr++; 
							  
							  NextSubState = Send_DestAddress_LSB;
							 }
							  


							   #ifdef Transmit_Debug

							  //printf ("b: %X \n\r", sumCounter); 

								#endif

						  break; 

						  case Send_DestAddress_LSB:

							if (SCI1SR1 & _S12_TDRE)
							{
							  
							  SCI1DRL = addressArray[addr];  

							  sumCounter += addressArray[addr];
							  
							  //SCI1DRL = 0x80;
							  
							  //sumCounter += 0x80; 
							  
							  //printf ("7:%X \n\r", addressArray[addr]);
							  //printf("a:%i\n\r", addr);
							  
							  NextSubState = Send_Options;
							  
							  
							 }

							  

							   #ifdef Transmit_Debug

							  //printf ("c: %X \n\r", sumCounter); 

								#endif 

						  break; 

						  case Send_Options:
						  
					  
							if (SCI1SR1 & _S12_TDRE)
							{

							  SCI1DRL = 0x00;
							  
							  sumCounter += 0x00;
							  
							  //printf ("8:%X \n\r", 0x00);
							  
							  NextSubState = Send_DataOut; 
							  
							 }
							  

							  

							  

							  #ifdef Transmit_Debug

							  //printf ("d:%X \n\r", sumCounter); 

							  #endif

						  break;

						  case Send_DataOut: 
						  
					  
							if (SCI1SR1 & _S12_TDRE)
							{

							  SCI1DRL = responseArray[j];
							  
							  sumCounter += responseArray[j];
							  
							  transmitCounter --;
							  
							  
							  //printf("8\n\r");
							  
							  #ifdef Transmit_Debug

							  //printf ("m:%X \n\r", responseArray[j]); 

							  #endif
							  
							  j++;
							  
							  if (transmitCounter > 0)
							  {
								NextSubState = Send_DataOut;

								


							  }
							  else
							  {
								NextSubState = CheckSum; 

	
							  } 
							 }

							  

						  break; 

						  case CheckSum:
						  
						  
						  	if (SCI1SR1 & _S12_TDRE)
							{

							  checkSum = 0xFF - sumCounter; 
							  
							  //printf("10:%X \n\r", checkSum); 
							  
							  SCI1DRL = checkSum; 

							  NextSubState = Send_Delim;


							  //SCI1CR2 &= ~(_S12_TCIE); 

							  #ifdef Transmit_Debug

							  //printf ("f:%X \n\r", sumCounter); 

							  #endif
							  
							  
		
			
							  
							  transmitFlag = 0;
							  sumCounter = 0;
							  j = 0; 
							  addr = 0;
							  
							  //printf("cs\n\r"); 
							  
							  
							 }
							  


						  break; 
					
					
					}
				
				
					NextState = SendStatus; 
				
				}
				
				/*
				else if (ThisEvent.EventType == ALREADY_PAIRED)
				{
					
					NextState = Response; 
					PTP |= BIT4HI; 
				}
				
				
				
				else if (ThisEvent.EventType == TAG_DETECTED)
				
				{
				
				}
				*/

				
			
				
			
			
			break; 
			
			


		}

	}

	
	CurrentState = NextState;
	CurrentSubState = NextSubState;

return ReturnEvent;
}

/****************************************************************************
Function
 QueryTemplateSM

Parameters
 None

Returns
 TemplateState_t The current state of the Template state machine

Description
 returns the current state of the Template state machine
Notes

Author
 J. Edward Carryer, 10/23/11, 19:21
****************************************************************************/
 TemplateState_t QueryPlayerTransmitSM ( void )
 {
   return(CurrentState);
 }

/***************************************************************************
private functions
***************************************************************************/

