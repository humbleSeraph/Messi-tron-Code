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
#include "PlayerReceiveSM.h"
#include "PlayerBrainSM.h"
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


#define Receive_Debug 
#define _MS_ *187.5
#define LISTEN_PERIOD (20_MS_)
#define TIMEOUT_PERIOD (1000_MS_)

#define LiFKIM_Timer 1
#define PlayerBrain_Timer 2
/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this machine.They should be functions
relevant to the behavior of this state machine
*/

void InitSCI(void);
void InitRxPorts(void);
void InitTimers(void);
void sendDataThru(void); 

/*---------------------------- Module Variables ---------------------------*/
// everybody needs a state variable, you may need others as well.
// type of state variable should match htat of enum in header file
static TemplateState_t CurrentState;

// with the introduction of Gen2, we need a module level Priority var as well
static uint8_t MyPriority;
static int sendFlag = 0; 
  
char sumCounter_R = 0; 


char ByteIn; 
char givenCheckSum_R; 

static char receiveCounter;
static char iPacketPreamble[8];
static char iPacketRFData[6];
int i;
int startListen;
int k;
char blah_blah;
char realreceiveCheckSum; 
int timeOutFlag;



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
 bool InitPlayerReceiveSM ( uint8_t Priority )
 {
  ES_Event ThisEvent;

  MyPriority = Priority;
// put us into the Initial PseudoState
  CurrentState = Read_Delim;
// post the initial transition event
  ThisEvent.EventType = ES_INIT;
  
  
  i = 1;
  startListen = 0;
  sumCounter_R = 0; 
  timeOutFlag = 0;

  InitSCI();
  InitRxPorts();
  
  ES_Timer_InitTimer(0,20);
  
  ES_Timer_InitTimer(LiFKIM_Timer,7000); 
  
  ES_Timer_InitTimer(PlayerBrain_Timer,7000); 
  

  
  
  if (ES_PostToService( MyPriority, ThisEvent) == true)
  {
	return true;
  }else
  {
	return false;
  }
}

void InitSCI()
{
//SCI1BDH = 0x00;  // IREN = 0, SBR<12:8>=0, others don't care
SCI1BDL = 156; // 10011011,  SBR<7:0>=n=155, BR = 9600Hz = 24MHz/(16*(n+1))

SCI1CR1 &= ~_S12_LOOPS;  // LOOPS=0, M=0, PE=0, others don't care
SCI1CR1 &= ~_S12_M;  
SCI1CR1 &= ~_S12_PE;

SCI1CR2 |= ( _S12_RIE | _S12_TE | _S12_RE); // 01101100- RIE=1, TE=1, RE=1- INTERRUPT on RIE
// with RIE interrupt, must clear OR and RDRF flags

}


void InitRxPorts()
{
	DDRT |= BIT3HI; 
	PTT &= BIT3LO;
	
}




void interrupt _Vec_sci1 CommHandler(void)
{

ES_Event ByteInEvent;

//DisableInterrupts;

//printf("r3");

if ((SCI1SR1 & BIT3HI) != 0 )
{
	printf("Overrun Error \n\r");
	blah_blah = SCI1DRL;
	

} 

if ((SCI1SR1 & BIT1HI) != 0)
{
	printf("Framing Error \n\r"); 
	blah_blah = SCI1DRL;
}


// check for RDRF Flag which tells me that a message has fully come into my register
if ( (SCI1SR1 & _S12_RDRF) == _S12_RDRF)
{
	
	ByteIn = SCI1DRL; 

	
	// guard condition so that I only start listening when the first byte is Incoming Delimiter
	if (ByteIn == 0x7E )
	{
		i = 0;
		k = 0; 
		startListen = 1; 
		
		
		// reset timeout counter, which goes off when too much time (20ms) has elapsed 
		timeOutFlag = 0;
			
			
			ES_Timer_InitTimer(0,20);
			
			ES_Timer_InitTimer(LiFKIM_Timer,7000); 
  
			ES_Timer_InitTimer(PlayerBrain_Timer,7000); 
			
			//TIM0_TC5 += LISTEN_PERIOD;
			//TIM1_TC4 += TIMEOUT_PERIOD;

			
 
	}
		//printf ("i:%i\n\r", i);
		//printf ("k %i\n\r", k);
		
	// if too much time has gone by this flag is set and I repopulate my array
	// from the beginning 
	if (timeOutFlag == 1)
	{
		i = 0;
	
	}
		
	if (startListen)
	{
		if (i < 8)
		{
			timeOutFlag = 0;

			ES_Timer_InitTimer(0,20);
			
			ES_Timer_InitTimer(LiFKIM_Timer,7000); 
  
			ES_Timer_InitTimer(PlayerBrain_Timer,7000); 
			
			//TIM0_TC5 += LISTEN_PERIOD;
			//TIM1_TC4 += TIMEOUT_PERIOD; 
			
			i++;
			iPacketPreamble[i-1] = ByteIn;
			
			if (i == 2)
			{
				receiveCounter = iPacketPreamble[i] - 5;

			
			}
			
			if (i > 2)
			{
				sumCounter_R += ByteIn; 
			
			}
		
		
		}
		
		else
		{
			if (receiveCounter > 0)
			{
				iPacketRFData[k] = ByteIn; 
				sumCounter_R += ByteIn;
				k++;
				receiveCounter--;
			
			}
			else
			{
				givenCheckSum_R = ByteIn; 
				realreceiveCheckSum = givenCheckSum_R + sumCounter_R;
				
				//printf("s:%d \n\r", sumCounter_R); 
				//printf ("b:%d \n\r", iPacketRFData[0]);
				//printf ("c:%d \n\r", iPacketRFData[1]);
				
				//LED_value = iPacketRFData[0]; 
				//printf ("is: %X \n\r", iPacketRFData[0]); 
				//printf ("cs:%d \n\r", givenCheckSum);
				
				startListen = 0; 
				PTP &= BIT4LO;
				PTT |= BIT3HI; 
				//PTU |= BIT3HI; 
				//Decode_Preamble(iPacketPreamble);
				//Decode_Message(iPacketRFData); 
			
			}
		
		
		}
		
	}
	
	
	
	
	

}

//EnableInterrupts; 


}

void sendDataThru(void)
{

	Decode_Preamble(iPacketPreamble);
	Decode_Message(iPacketRFData); 


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
 bool PostPlayerReceiveSM( ES_Event ThisEvent )
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
ES_Event RunPlayerReceiveSM( ES_Event ThisEvent )
{

TemplateState_t NextState = CurrentState;


ES_Event ReturnEvent;
ReturnEvent.EventType = ES_NO_EVENT; // assume no errors;

		if (ThisEvent.EventType == PUSH)
		{
			sendDataThru();

		}
		
		else if (ThisEvent.EventType == ES_TIMEOUT)
		{
			timeOutFlag = 1;
		
		}
		

CurrentState = NextState;
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
 TemplateState_t QueryPlayerReceiveSM ( void )
 {
   return(CurrentState);
 }

/***************************************************************************
private functions
***************************************************************************/

