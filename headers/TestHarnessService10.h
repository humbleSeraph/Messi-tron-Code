/****************************************************************************
 
  Header file for Test Harness Service 10 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestHarnessService10_H
#define TestHarnessService10_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestHarnessService10 ( uint8_t Priority );
bool PostTestHarnessService10( ES_Event ThisEvent );
ES_Event RunTestHarnessService10( ES_Event ThisEvent );


#endif /* TestHarnessService10_H */

