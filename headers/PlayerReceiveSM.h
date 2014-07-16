/****************************************************************************
 
  Header fie for template Flat Sate Machine 
  based on the Gen2 Events and Services Framework

 ****************************************************************************/

#ifndef PlayerReceiveSM_H
#define PlayerReceiveSM_H

// Event Definitions
#include "ES_Configure.h" /* gets us event definitions */
#include "ES_Types.h"     /* gets bool type for returns */

// typedefs for the states
// State definitions for use with the query function
  	typedef enum { Read_Delim  } TemplateState_t ;


// Public Function Prototypes

  	bool InitPlayerReceiveSM ( uint8_t Priority );
  	bool PostPlayerReceiveSM( ES_Event ThisEvent );
  	ES_Event RunPlayerReceiveSM( ES_Event ThisEvent );
  	TemplateState_t QueryPlayerReceiveSM ( void );


#endif /* PlayerSM_H */

