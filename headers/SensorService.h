/****************************************************************************
 
  Header file for template service 
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef SensorService_H
#define SensorService_H


#include "ES_Types.h"
#include "ES_Configure.h"
#include "ES_Timers.h"
#include <hidef.h>
#include <mc9s12e128.h>
#include <S12e128bits.h>
#include <Bin_Const.h>
#include <termio.h>
#include <S12eVec.h>
#include <stdio.h>

// Public Function Prototypes

bool InitSensorService ( uint8_t Priority );
bool PostSensorService( ES_Event ThisEvent );
ES_Event RunSensorService( ES_Event ThisEvent );

#define _MS_ *187.5
#define GOAL_CHECK_PERIOD (50_MS_)
#define REFRESH_PERIOD (100_MS_)

#define GOAL_DEBUG


#endif /* SensorService_H */

