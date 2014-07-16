/****************************************************************************
 
  Header fie for template service 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef PlayerLIFKIM_H
#define PlayerLIFKIM_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitPlayerLiFKIM ( uint8_t Priority );
bool PostPlayerLiFKIM( ES_Event ThisEvent );
ES_Event RunPlayerLiFKIM( ES_Event ThisEvent );

void Build_TagDetected(char byte, int i);
void Build_TagOut (char byte, int i); 


#endif /* ServTemplate_H */

