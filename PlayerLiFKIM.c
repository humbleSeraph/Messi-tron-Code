/****************************************************************************
 Module
   TemplateService.c

 Revision
   1.0.1

 Description
   This is a tempate file for implementing a simple service under the 
   Gen2 Events and Services Framework.

 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 01/16/12 09:58 jec      began conversion from TemplateFSM.c
****************************************************************************/
/*----------------------------- Include Files -----------------------------*/
/* include header files for this state machine as well as any machines at the
   next lower level in the hierarchy that are sub-machines to this machine
*/
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "TemplateService.h"

#include "PlayerLiFKIM.h"
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

#define _MS_ *187.5
#define WAIT_TIME (10_MS_)

/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this service.They should be functions
   relevant to the behavior of this service
*/

void InitLiFSPI(void);
void InitLiFTimer(void); 
void Build_TagDetected(char byte, int i);
void Build_TagOut (char byte, int i); 
void StartFan(void);
void SetLiftLevel(void);
void KillFan(void);
void ActivateFan(void); 

void Heartbeat(void);
void Send_TagOut(void); 
void Send_TagDetect(void); 

/*---------------------------- Module Variables ---------------------------*/
// with the introduction of Gen2, we need a module level Priority variable
static uint8_t MyPriority;
static int counter = 0; 
char dummyData;
char liFData;
char statusData;

char tagDetect[2];
char tagOut [2]; 

int tick = 0;
int counter;
int dummyFlag;
int initFlag;
int heartBeating;
int tCounter; 
int j;
int n; 
int tagFlag;

/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitTemplateService

 Parameters
     uint8_t : the priorty of this service

 Returns
     bool, false if error in initialization, true otherwise

 Description
     Saves away the priority, and does any 
     other required initialization for this service
 Notes

 Author
     J. Edward Carryer, 01/16/12, 10:00
****************************************************************************/
bool InitPlayerLiFKIM ( uint8_t Priority )
{
  ES_Event ThisEvent;

  MyPriority = Priority;
  /********************************************
   in here you write your initialization code
   *******************************************/
  // post the initial transition event
  
  InitLiFSPI();
  InitLiFTimer(); 
  
  //"just in case" explicit configuring of ports for SPI
  DDRS &= BIT4LO;
  DDRS |= BIT5HI | BIT6HI | BIT7HI;
  
  //set both tagDetect and tagOut arrays to "Request for Energy Level"; 
  
  tagDetect[0] = 0x3C;
  tagDetect[1] = 0xA5; 
  
  tagOut[0] = 0x3C;
  tagOut[1] = 0x69; 
  
  counter = 0;
  dummyFlag = 1;
  heartBeating = 0; 
  initFlag = 1;
  tCounter = 0;
  j = 0; 
  n = 0; 
  tagFlag = 0; 
  
  
  
  
  ThisEvent.EventType = ES_INIT;
  if (ES_PostToService( MyPriority, ThisEvent) == true)
  {
      return true;
  }else
  {
      return false;
  }
}

void InitLiFSPI()
{
//Enable SPI and set E128 to Master 
SPICR1 |= _S12_SPE | _S12_MSTR; 

//Set Baud Rate to divide 24MHz clock by 1792, which is (6+1) * 2^(7+1)
SPIBR |= _S12_SPPR2 | _S12_SPPR1;      //gets the 7 in the equation
SPIBR &= ~_S12_SPPR0;
SPIBR |= _S12_SPR2 | _S12_SPR1;   //gets the 7 in the exponent 
SPIBR &= ~_S12_SPR0; 

//Set clock to idle high and sample even edges
SPICR1 |= _S12_CPOL | _S12_CPHA;  

//Disable slave select ouput
SPICR1 |= _S12_SSOE;

//MSB First
SPICR1 &= ~_S12_LSFBE;

// Enable SPI Interrupt 
SPICR1 |= _S12_SPIE; 

//Enable MODFEN to give SPI control of SS line
SPICR2 |= _S12_MODFEN;

}



void InitLiFTimer()
{
/************************************** Timer 1, channel 5 ************************/

// turn timer system on
TIM1_TSCR1 = _S12_TEN;  

// set prescale clock to /128 = 187.5kHz
TIM1_TSCR2 = _S12_PR0 | _S12_PR1 | _S12_PR2;


TIM1_TIOS |= _S12_IOS5;
TIM1_TCTL1 &= ~(_S12_OL5 | _S12_OM5); 
TIM1_TC5 = TIM1_TCNT + WAIT_TIME;
TIM1_TFLG1 = _S12_C5F;
TIM1_TIE |= _S12_C5I;

EnableInterrupts;


}



void interrupt _Vec_tim1ch5 LIFKIMTimer()
{
	
	
	ES_Event ThatEvent;
	ES_Event CallEvent;
	
 //DisableInterrupts; 	
	//printf("L6");
	
	TIM1_TFLG1 = _S12_C5F;
  
  
  
  if (tagFlag == 1)
  {
	CallEvent.EventType = TAG_OUT;
	PostPlayerLiFKIM(CallEvent);

  }
  
  else
  
  {
	ThatEvent.EventType = TRIGGER2;
	PostPlayerLiFKIM(ThatEvent); 
  }

  TIM1_TC5 += WAIT_TIME; 
  
  //EnableInterrupts; 


}


void interrupt _Vec_spi ReadLiFKIM(void)
{
  
  //DisableInterrupts; 
  
  //printf("L7");
  
  if (SPISR & _S12_MODF)
  {
		printf("modf\n\r");
	
  }
  
  if ((SPISR & _S12_SPIF) == _S12_SPIF)
  {
		dummyData = SPIDR;
		
		if (heartBeating == 1)
		{
			if ((counter %2) != 0)
			{
				dummyData = SPIDR; 
				//printf("ddata:%X\n\r", dummyData);
			}
			
			else
			{
				liFData = SPIDR;
				
				Build_LiFKIM(liFData, 0); 
				//printf("ldata:%X\n\r", liFData); 
			}
		}
  }
  
  //EnableInterrupts; 

}

void StartFan(void)
{
	if((counter % 2) != 0)
	{
	
		if ((SPISR & _S12_SPTEF) == _S12_SPTEF)   //read SPISR and send command if transmit empty flag is set 
			{
				SPIDR = 0xC3;
			}
		//dummyFlag = 2;
	}
	
	else
	
	{
		if ((SPISR & _S12_SPTEF) == _S12_SPTEF)
			{
				SPIDR = 0x00; 
			}
			
		//dummyFlag = 1; 
		counter = 0;
	}
	

}


void ActivateFan(void)
{
	if((counter % 2) != 0)
	{
	
		if ((SPISR & _S12_SPTEF) == _S12_SPTEF)   //read SPISR and send command if transmit empty flag is set 
			{
				SPIDR = 0x1E;
			}
		//dummyFlag = 2;
		
		printf("acti\n\r"); 
	}
	
	else
	
	{
		if ((SPISR & _S12_SPTEF) == _S12_SPTEF)
			{
				SPIDR = 0x00; 
			}
			
		//dummyFlag = 1; 
		counter = 0;
	}
	

}

void KillFan(void)
{
	if((counter % 2) != 0)
	{
	
		//printf("killt\n\r");
	
		if ((SPISR & _S12_SPTEF) == _S12_SPTEF)   //read SPISR and send command if transmit empty flag is set 
			{
				SPIDR = 0xF0;
			}
		//dummyFlag = 2;
	}
	
	else
	
	{
		if ((SPISR & _S12_SPTEF) == _S12_SPTEF)
			{
				SPIDR = 0x00; 
			}
			
		//dummyFlag = 1; 
		counter = 0;
	}
	

}




void Heartbeat(void)
{

	heartBeating = 1; 
	
	if((counter % 2) != 0)
	{
	
		if ((SPISR & _S12_SPTEF) == _S12_SPTEF)   //read SPISR and send command if transmit empty flag is set 
			{ 
				SPIDR = 0x0F;
			}
		dummyFlag = 1;
	}
	
	else
	
	{
		if ((SPISR & _S12_SPTEF) == _S12_SPTEF)
			{
				SPIDR = 0x00; 
			}
			
		counter = 0;
	}

}

void Send_TagOut(void)
{
	
	
	if((counter % 2) != 0)
	{
	
		if ((SPISR & _S12_SPTEF) == _S12_SPTEF)   //read SPISR and send command if transmit empty flag is set 
			{
				SPIDR = tagOut[j];
				printf("past\n\r");
			}
			j++;
			if (j > 1)
			{
				j =0; 
			}
			//printf("ta\n\r");
	}
	
	else
	
	{
		if ((SPISR & _S12_SPTEF) == _S12_SPTEF)
			{
				SPIDR = 0x00; 
			}
			
		counter = 0;
	}

}

void Send_TagDetect(void)
{
	
	if((counter % 2) != 0)
	{
	
		if ((SPISR & _S12_SPTEF) == _S12_SPTEF)   //read SPISR and send command if transmit empty flag is set 
			{
				SPIDR = tagDetect[n];
				//printf("here3\n\r");
			}
			n++;
			if (n > 1)
			{
				n = 0; 
			}
			//printf("tagdetect\n\r");
			
	}
	
	else
	
	{
		if ((SPISR & _S12_SPTEF) == _S12_SPTEF)
			{
				SPIDR = 0x00; 
				//printf("here4\n\r"); 
			}
			
		counter = 0;
	}

}

void Build_TagDetected(char byte, int i)
{
	tagDetect[i] = byte; 

}

void Build_TagOut (char byte, int i)
{
	tagOut[i] = byte; 

}
/****************************************************************************
 Function
     PostTemplateService

 Parameters
     EF_Event ThisEvent ,the event to post to the queue

 Returns
     bool false if the Enqueue operation failed, true otherwise

 Description
     Posts an event to this state machine's queue
 Notes

 Author
     J. Edward Carryer, 10/23/11, 19:25
****************************************************************************/
bool PostPlayerLiFKIM( ES_Event ThisEvent )
{
  return ES_PostToService( MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunTemplateService

 Parameters
   ES_Event : the event to process

 Returns
   ES_Event, ES_NO_EVENT if no error ES_ERROR otherwise

 Description
   add your description here
 Notes
   
 Author
   J. Edward Carryer, 01/15/12, 15:23
****************************************************************************/
ES_Event RunPlayerLiFKIM( ES_Event ThisEvent )
{
  ES_Event ReturnEvent;
  ES_Event LiFKIMEvent;
  
  
  ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
  /********************************************
   in here you write your service code
   *******************************************/
   
   switch(ThisEvent.EventType)
   {
		
		case ES_TIMEOUT:
		
		    KillFan(); 
		
		break; 
		
		case TIME_OUT:
		
			KillFan();
			// maybe put ActivateFan() here? 
			printf("b-l:to\n\r");
			
		break; 

		
		
		case START_ENGINE:
			counter++;
			StartFan();
			ActivateFan();
			//StartFan();
			
			tCounter = 0; 
		
		break;
		
		case GET_STATUS:
			counter++;
			Heartbeat(); 
		
		break; 
		
		case TAG_CALL:
			
			tagFlag = 1; 
			
		break; 
		
		case TAG_OUT:
		
				counter ++;
				//printf("ta\n\r");
				//Send_TagOut();
				
				if (tCounter < 4)
				{
				
				Send_TagDetect();
				tagFlag = 0; 
				tCounter++;
				printf("tCount: %i\n\r", tCounter);
				
				}
				else 
				
				{
				
					if (tCounter < 8)
					{
						Send_TagOut();
						tagFlag = 0; 
						tCounter++; 
						printf("tCount2: %i\n\r", tCounter); 
						
						
					}
				
				}
			

			
		break; 
		

   }
   
  return ReturnEvent;
}

/***************************************************************************
 private functions
 ***************************************************************************/

/*------------------------------- Footnotes -------------------------------*/
/*------------------------------ End of file ------------------------------*/

