/****************************************************************************
 
  Header file for Test Harness Service 14 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestHarnessService14_H
#define TestHarnessService14_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestHarnessService14 ( uint8_t Priority );
bool PostTestHarnessService14( ES_Event ThisEvent );
ES_Event RunTestHarnessService14( ES_Event ThisEvent );


#endif /* TestHarnessService14_H */

