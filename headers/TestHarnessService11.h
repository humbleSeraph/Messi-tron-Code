/****************************************************************************
 
  Header file for Test Harness Service 11 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestHarnessService11_H
#define TestHarnessService11_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestHarnessService11 ( uint8_t Priority );
bool PostTestHarnessService11( ES_Event ThisEvent );
ES_Event RunTestHarnessService11( ES_Event ThisEvent );


#endif /* TestHarnessService11_H */

