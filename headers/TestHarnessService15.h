/****************************************************************************
 
  Header file for Test Harness Service 15 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestHarnessService15_H
#define TestHarnessService15_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestHarnessService15 ( uint8_t Priority );
bool PostTestHarnessService15( ES_Event ThisEvent );
ES_Event RunTestHarnessService15( ES_Event ThisEvent );


#endif /* TestHarnessService15_H */

