/****************************************************************************
 
  Header file for Test Harness Service 12 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestHarnessService12_H
#define TestHarnessService12_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestHarnessService12 ( uint8_t Priority );
bool PostTestHarnessService12( ES_Event ThisEvent );
ES_Event RunTestHarnessService12( ES_Event ThisEvent );


#endif /* TestHarnessService12_H */

