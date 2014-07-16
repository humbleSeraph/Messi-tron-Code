/****************************************************************************
 
  Header file for Test Harness Service 5 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestHarnessService5_H
#define TestHarnessService5_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestHarnessService5 ( uint8_t Priority );
bool PostTestHarnessService5( ES_Event ThisEvent );
ES_Event RunTestHarnessService5( ES_Event ThisEvent );


#endif /* TestHarnessService5_H */

