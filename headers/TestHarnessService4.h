/****************************************************************************
 
  Header file for Test Harness Service 4 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestHarnessService4_H
#define TestHarnessService4_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestHarnessService4 ( uint8_t Priority );
bool PostTestHarnessService4( ES_Event ThisEvent );
ES_Event RunTestHarnessService4( ES_Event ThisEvent );


#endif /* TestHarnessService4_H */

