/****************************************************************************
 
  Header file for Test Harness Service 7 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestHarnessService7_H
#define TestHarnessService7_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestHarnessService7 ( uint8_t Priority );
bool PostTestHarnessService7( ES_Event ThisEvent );
ES_Event RunTestHarnessService7( ES_Event ThisEvent );


#endif /* TestHarnessService7_H */

