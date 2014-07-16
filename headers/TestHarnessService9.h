/****************************************************************************
 
  Header file for Test Harness Service 9 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestHarnessService9_H
#define TestHarnessService9_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestHarnessService9 ( uint8_t Priority );
bool PostTestHarnessService9( ES_Event ThisEvent );
ES_Event RunTestHarnessService9( ES_Event ThisEvent );


#endif /* TestHarnessService9_H */

