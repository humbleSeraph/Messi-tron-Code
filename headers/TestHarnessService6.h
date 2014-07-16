/****************************************************************************
 
  Header file for Test Harness Service 6 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestHarnessService6_H
#define TestHarnessService6_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestHarnessService6 ( uint8_t Priority );
bool PostTestHarnessService6( ES_Event ThisEvent );
ES_Event RunTestHarnessService6( ES_Event ThisEvent );


#endif /* TestHarnessService6_H */

