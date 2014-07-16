/****************************************************************************
 
  Header file for Test Harness Service 8 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestHarnessService8_H
#define TestHarnessService8_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestHarnessService8 ( uint8_t Priority );
bool PostTestHarnessService8( ES_Event ThisEvent );
ES_Event RunTestHarnessService8( ES_Event ThisEvent );


#endif /* TestHarnessService8_H */

