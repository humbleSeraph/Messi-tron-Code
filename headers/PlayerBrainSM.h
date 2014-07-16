/****************************************************************************
 
  Headr file for template Flat Sate Machine 
  based on the Gen2 Events and Services Framework

 ****************************************************************************/

#ifndef PlayerBrainSM_H
#define PlayerBrainSM_H

// Event Definitions
#include "ES_Configure.h" /* gets us event definitions */
#include "ES_Types.h"     /* gets bool type for returns */

// typedefs for the states
// State definitions for use with the query function
typedef enum { Wait_Link, Paired } TemplateState_t ;


// Public Function Prototypes



bool InitPlayerBrainSM ( uint8_t Priority );
bool PostPlayerBrainSM( ES_Event ThisEvent );
ES_Event RunPlayerBrainSM( ES_Event ThisEvent );
TemplateState_t QueryPlayerBrainSM ( void );

void Decode_Message(char *data);
void Decode_Preamble(char *intro); 
TemplateState_t QueryPlayerBrainSM ( void );

void Build_LiFKIM(char byte, int i);


#endif /* FSMTemplate_H */

