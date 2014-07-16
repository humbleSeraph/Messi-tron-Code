/****************************************************************************
 
  Header file for Test Harness Service 2 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestHarnessService2_H
#define TestHarnessService2_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestHarnessService2 ( uint8_t Priority );
bool PostTestHarnessService2( ES_Event ThisEvent );
ES_Event RunTestHarnessService2( ES_Event ThisEvent );


#endif /* TestHarnessService2_H */

