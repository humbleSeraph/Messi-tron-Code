/****************************************************************************
 
  Header file for Test Harness Service 1 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestHarnessService1_H
#define TestHarnessService1_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestHarnessService1 ( uint8_t Priority );
bool PostTestHarnessService1( ES_Event ThisEvent );
ES_Event RunTestHarnessService1( ES_Event ThisEvent );


#endif /* ServTemplate_H */

