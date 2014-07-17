/****************************************************************************
 
  Header fie for template Flat Sate Machine 
  based on the Gen2 Events and Services Framework

 ****************************************************************************/

#ifndef PlayerSM_H
#define PlayerSM_H

// Event Definitions
#include "ES_Configure.h" /* gets us event definitions */
#include "ES_Types.h"     /* gets bool type for returns */

// typedefs for the states
// State definitions for use with the query function
  	typedef enum { Send_Delim, Send_LengthByte_MSB, Send_LengthByte_LSB,
  	Send_APIiD, Send_FrameID, Send_DestAddress_MSB, Send_DestAddress_LSB, Send_Options,
  	Send_DataOut, CheckSum, Read_Delim, Read_LengthByte_MSB, Read_LengthByte_LSB,
  	Read_APIiD, Read_FrameID, Read_Status, Read_TransmitResult_CheckSum, Read_SourceAdd_MSB,
  	Read_SourceAdd_LSB, Read_SignalStrength, Read_Receive_Options, Read_Data, Read_IP_CheckSum } TemplateState_t ;


// Public Function Prototypes

  	bool InitPlayerSM ( uint8_t Priority );
  	bool PostPlayerSM( ES_Event ThisEvent );
  	ES_Event RunPlayerSM( ES_Event ThisEvent );
  	TemplateState_t QueryPlayerSM ( void );


#endif /* PlayerSM_H */

