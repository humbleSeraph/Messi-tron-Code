/****************************************************************************
 
  Header file for Test Harness Service 3 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestHarnessService3_H
#define TestHarnessService3_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestHarnessService3 ( uint8_t Priority );
bool PostTestHarnessService3( ES_Event ThisEvent );
ES_Event RunTestHarnessService3( ES_Event ThisEvent );


#endif /* TestHarnessService3_H */

