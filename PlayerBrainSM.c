/****************************************************************************
 Module
   TemplateFSM.c

 Revision
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

#include "PlayerBrainSM.h"
#include "PlayerTransmitSM.h"
#include "PlayerLiFKIM.h"
#include "PropellerModule.h"

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

/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this machine.They should be functions
   relevant to the behavior of this state machine
*/

void Decode_Message(char *data);
void Decode_Preamble(char *intro); 
void Build_LiFKIM(char byte, int i);
char Read_Team(void);


/*---------------------------- Module Variables ---------------------------*/
// everybody needs a state variable, you may need others as well.
// type of state variable should match htat of enum in header file
static TemplateState_t CurrentState;

// with the introduction of Gen2, we need a module level Priority var as well
static uint8_t MyPriority;

char responseByte;
char responseHeader;
char jerseyMask = 0x0F; 
char LiFKIMArray[2] = {0x00}; 

char controlByte; 
char controlByte2;
char controlByte3;
char controlByte4;
char controlByte5;

char tagByte;
char colorMask = BIT0HI; 
char greenSide = 0x3C;
char redSide = 0x2D; 

char locationMask = BIT1HI | BIT2HI; 
char location; 

char TD_Dock1 = 0xB4;
char TD_Dock2 = 0xA5;
char TD_Dock3 = 0x96;
char TD_Dock4 = 0x87;

char TO_Dock1 = 0x78;
char TO_Dock2 = 0x69;
char TO_Dock3 = 0x5A;
char TO_Dock4 = 0x4B; 

int rightCall;
int s; 

char kickMask = 0x0F;
char energyMask = 0x07; 
unsigned char energyLevel; 

char teamChoice;
char greenTeam;
char redTeam; 


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
bool InitPlayerBrainSM ( uint8_t Priority )
{
  ES_Event ThisEvent;

  MyPriority = Priority;
  // put us into the Initial PseudoState
  CurrentState = Wait_Link;
  // post the initial transition event
  
  // init pwm port
  DDRU = 0XFF;  
  
  DDRP &= BIT2LO;
  
  Initialize_PropellerModule();
  Initialize_ServoModule ();
  Steer_Player(0,0);
 
 

  rightCall = 0; 
  
  ThisEvent.EventType = ES_INIT;
  if (ES_PostToService( MyPriority, ThisEvent) == true)
  {
      return true;
  }else
  {
      return false;
  }
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
bool PostPlayerBrainSM( ES_Event ThisEvent )
{
  return ES_PostToService( MyPriority, ThisEvent);
}

void Build_LiFKIM(char byte, int i)
{

	LiFKIMArray[i] = byte; 

}

char Read_Team(void)
{

	teamChoice = BIT2HI & PTP; 
	
	if (teamChoice == 1)
	{
		greenTeam = teamChoice;
		return (greenTeam);
	
	}
	
	else 
	
	{
		redTeam = teamChoice;
		return (redTeam); 
		
	}

}




void Decode_Preamble (char *intro)
{

Build_Address(intro[4], 0);
Build_Address(intro[5], 1); 

}




/******************   Processes the RF Data bytes from incoming message **************/
void Decode_Message(char *data)
{
ES_Event BrainEvent;
ES_Event BrainIIEvent; 
ES_Event BrainIIIEvent;

	 	 switch (data[0])
 	 	{
 	 	 	
			
			case 0x04:
 	 	 		{
 	 	 		  //This is a Reset Message
				//printf("res\n\r");
				  
				  // reset all hardware stuff here
				  
				  
					BrainEvent.EventType = RESET;
					BrainIIEvent.EventType = TIME_OUT;
				  
					
					
					PostPlayerBrainSM(BrainEvent);

					PostPlayerLiFKIM(BrainIIEvent);

					Steer_Player (0, 0);

 	 	 		}
 	 	 	break;
 	 	 	
 	 	 	case 0x02:
 	 	 		{
				
				// This is a Tag Out Message
 	 	 		  
				  BrainEvent.EventType = TAG_OUT;
				  BrainIIEvent.EventType = TAG_CALL; 
				  
				  tagByte = data[1];
				 
				 if ((tagByte & colorMask) == 1)
				 {
					Build_TagOut(greenSide, 0);
					
					printf("gto\n\r"); 
				 
				 }
				 
				 else
				 
				 {
					Build_TagOut(redSide,0);
				 
				 }
				 
				 location = tagByte & locationMask;
				 
				 switch(location)
				 {
					
					// xxxxx 00x - position 1 in zone
					
					case 0x00:
					
						Build_TagOut(TO_Dock1, 1);
						
					break;
					
					
					// xxxxx 01x - position 2 in zone 
					
					case 0x02:
						
						Build_TagOut(TO_Dock2, 1);
						
					break; 
					
					// xxxxx 10x - position 3 in zone
					
					case 0x04:
					
						Build_TagOut(TO_Dock3, 1); 
					
					break; 
					
					
					// xxxxx 11x - position 4 in zone
					
					case 0x06:
					
						Build_TagOut(TO_Dock4, 1); 
					
					break;
					
				 
				 }
				  

						PostPlayerLiFKIM(BrainIIEvent);
						PostPlayerLiFKIM(BrainIIEvent);
						PostPlayerLiFKIM(BrainIIEvent);
						PostPlayerLiFKIM(BrainIIEvent);

				  
				  PostPlayerBrainSM(BrainEvent); 
				  Steer_Player (0, 0);
 	 	 		 
 	 	 		}
 	 	 	break;
 	 	 			
 	 	    case 0x07:
 	 	 		{
 	 	 		  //This is a Tag Detected Message
 	 	 		 //printf("\n\r7");
				 
				 BrainEvent.EventType = TAG_CALL;
				 
				 tagByte = data[1];
				 
				 if ((tagByte & colorMask) == 1)
				 {
					Build_TagDetected(greenSide, 0);
					
					printf("gtd\n\r"); 
				 
				 }
				 
				 else
				 
				 {
					Build_TagDetected(redSide,0);
				 
				 }
				 
				 location = tagByte & locationMask;
				 
				 switch(location)
				 {
					
					// xxxxx 00x - position 1 in zone
					
					case 0x00:
					
						Build_TagDetected(TD_Dock1, 1);
						
					break;
					
					
					// xxxxx 01x - position 2 in zone 
					
					case 0x02:
						
						Build_TagDetected(TD_Dock2, 1);
						
					break; 
					
					// xxxxx 10x - position 3 in zone
					
					case 0x04:
					
						Build_TagDetected(TD_Dock3, 1); 
					
					break; 
					
					
					// xxxxx 11x - position 4 in zone
					
					case 0x06:
					
						Build_TagDetected(TD_Dock4, 1); 
					
					break;
					
				 
				 }


						PostPlayerLiFKIM(BrainEvent);
						PostPlayerLiFKIM(BrainEvent);
						PostPlayerLiFKIM(BrainEvent);
						PostPlayerLiFKIM(BrainEvent);


 	 	 		  
 	 	 		}
 	 	 	break;
 	 	
 			case 0x03:
 	 	 		{
 	 	 		  //This is a Pair Request Message
				  
				  
 	 	 		  printf("rp\n\r");
				  
				  
				  if (Read_Team() == greenTeam)
				  {
				  
					  if ((data[1] & BIT4HI) == 0)
					  
					  {
						//printf("ce\n\r"); 
					  
					  
						BrainEvent.EventType = DENY_PAIR; 
					  
						responseHeader = 0x05;
						responseByte = 0x02; 
						
						Build_Response(responseHeader, 0);
						Build_Response(responseByte, 1); 
						
						PostPlayerBrainSM(BrainEvent); 
						
					  }
				  
				  }
				  
				  if (Read_Team() == redTeam)
				  {
						if ((data[1] & BIT4HI) == 1)
						  
						  {
							//printf("ce\n\r"); 
						  
						  
							BrainEvent.EventType = DENY_PAIR; 
						  
							responseHeader = 0x05;
							responseByte = 0x02; 
							
							Build_Response(responseHeader, 0);
							Build_Response(responseByte, 1); 
							
							PostPlayerBrainSM(BrainEvent); 
							
						  }
					  
				  }
				  
				  else if ((data[1] & jerseyMask) != BIT3HI)
				  {
					//printf("je\n\r");
				  
				  }
				  
				  
				  else if (QueryPlayerBrainSM() == Paired)
				  
				  {
				  
					//printf("pe\n\r");
					
					BrainEvent.EventType = DENY_PAIR;
				  
					responseHeader = 0x05;
					responseByte = 0x04; 
				  
					Build_Response(responseHeader, 0); 
					Build_Response(responseByte, 1); 
					
					PostPlayerBrainSM(BrainEvent); 
				  
				  } 
				  
				  if (Read_Team() == greenTeam)
				  {
					if ((data[1] & BIT4HI) == BIT4HI)
				  
					  {
					  
						printf("mtcg\n\r"); 
						BrainEvent.EventType = GOOD_CALL;
						
		 
					  
						responseHeader = 0x05;
						responseByte = 0x01;
						
						
						Build_Response (responseHeader, 0);
						Build_Response (responseByte, 1); 
						
						PostPlayerBrainSM(BrainEvent); 
						
						rightCall = 1;
						
						
					  }
				  }
				  
				  else if (Read_Team() == redTeam)
				  {
						if ((data[1] & BIT4HI) == BIT4HI)
				  
					  {
					  
						printf("mtcr\n\r"); 
						BrainEvent.EventType = GOOD_CALL;
						
		 
					  
						responseHeader = 0x05;
						responseByte = 0x01;
						
						
						Build_Response (responseHeader, 0);
						Build_Response (responseByte, 1); 
						
						PostPlayerBrainSM(BrainEvent); 
						
						rightCall = 1;
						
						
					  }
				  
				  
				  
				  }
				  
				  
 	 	 		
 	 	 		}
 	 	 	break;

			case 0x01:
 	 	 		{
					
					
					if ((QueryPlayerBrainSM() == Wait_Link) && (rightCall == 1))
					{
						BrainEvent.EventType = ACCEPT_PAIR;
						BrainIIEvent.EventType =  START_ENGINE;
						
						
						PostPlayerBrainSM(BrainEvent);
						PostPlayerLiFKIM(BrainIIEvent);
					}
					
					else
					
					{
				
					BrainIIIEvent.EventType = GET_STATUS;
					
					controlByte = data[1];
					controlByte2 = data[2];
					controlByte3 = data[3];
					controlByte4 = data[4];
					controlByte5 = data[5];
					
					
					responseHeader = 0x06;
					responseByte = LiFKIMArray[0]; 
					
					Build_Response (responseHeader, 0);
					Build_Response (responseByte, 1); 
					
					Steer_Player (controlByte, controlByte2);
					
					if ((controlByte3 & kickMask) != 0)
					{
					
					    Kick(); 
					    
					    printf("3ctrl:%d\n\r",controlByte3);
					
					}
					
					energyLevel = responseByte & energyMask;
					
					Energy_Level(energyLevel); 
					
					
					
					
					//printf("cl\n\r");
					
					//printf("1cl:%d\n\r", controlByte);
					//printf("2cl:%d\n\r",controlByte2);
					//printf("3ctrl:%d\n\r",controlByte3);
					//printf("4ctrl:%d\n\r",controlByte4);
					//printf("5ctrl:%d\n\r",controlByte5);
					
					 
					PostPlayerLiFKIM(BrainIIIEvent);
					}
 	 	 		   
 	 	 		}
 	 	 	break;
 	 	 	
 	 	 	//default:
 	 	 	//printf("gb\n\r");
 	 	 	
 	 	 }
 	 	 
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
ES_Event RunPlayerBrainSM( ES_Event ThisEvent )
{

  ES_Event CommEvent;
  //ES_Event CommIIEvent; 
  TemplateState_t NextState = CurrentState;
  
  

  ES_Event ReturnEvent;
  ReturnEvent.EventType = ES_NO_EVENT; // assume no errors

  switch ( CurrentState )
  {
      case Wait_Link :       // If current state is initial Psedudo State
          
		  switch (ThisEvent.EventType)
		  {
		  
			case DENY_PAIR:
			
				CommEvent.EventType = COACH_CALL;
				PostPlayerTransmitSM(CommEvent); 
				
				NextState = Wait_Link;
			
			
			break;
			
			case GOOD_CALL:
				CommEvent.EventType = COACH_CALL;
				PostPlayerTransmitSM(CommEvent);
				NextState = Wait_Link;
			
			break; 
			
			case ACCEPT_PAIR:
			
				
				CommEvent.EventType = CAN_TRANSMIT;
				PostPlayerTransmitSM(CommEvent); 
				//printf("pairaccepted\n\r"); 

				NextState = Paired;
				rightCall = 0; 
			
			break; 
			
			case RESET:
			  
				
				CommEvent.EventType = TIME_OUT;
				PostPlayerTransmitSM(CommEvent); 
				
				NextState = Wait_Link;
			  
			break; 
			
			case TAG_OUT:
			  
				CommEvent.EventType = TAG_OUT;
				PostPlayerTransmitSM(CommEvent); 
				
				NextState = Wait_Link; 
			  
			break;
		  }

      break;

      case Paired:       // If current state is state one
          switch ( ThisEvent.EventType )
          {
			  
			  case ES_TIMEOUT:
				
				NextState = Wait_Link; 
				
				Steer_Player(0,0); 
			  
			  break; 
			  
			  
			  case ALREADY_PAIRED:

				CommEvent.EventType = ALREADY_PAIRED;
				PostPlayerTransmitSM(CommEvent);

				NextState = Paired;
			  
              break;
			  

			  
			  case RESET:
			  
				CommEvent.EventType = TAG_OUT;
				PostPlayerTransmitSM(CommEvent); 
				
				NextState = Wait_Link;
			  
			  break; 
			  
			  case TAG_OUT:
			  
				CommEvent.EventType = TAG_OUT;
				PostPlayerTransmitSM(CommEvent); 
				
				NextState = Wait_Link; 
			  
			  break;
				
			  

              // repeat cases as required for relevant events
          }                           // end switch on CurrentEvent
      break;
      // repeat state pattern as required for other states

  }
                                   // end switch on Current State
								   
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
TemplateState_t QueryPlayerBrainSM ( void )
{
   return(CurrentState);
}

/***************************************************************************
 private functions
 ***************************************************************************/

