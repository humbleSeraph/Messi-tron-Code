/****************************************************************************
 
  Header file for Test Harness Service 13 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestHarnessService13_H
#define TestHarnessService13_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestHarnessService13 ( uint8_t Priority );
bool PostTestHarnessService13( ES_Event ThisEvent );
ES_Event RunTestHarnessService13( ES_Event ThisEvent );


#endif /* TestHarnessService13_H */

