#ifndef CommInterface_H
#define CommInterface_H 

/*
//Enum for Message Type
typedef enum 
	 { 	RESET,
	 	TAG_OUT,
	 	TAG_DETECT,
	 	PLAYER_STATUS,
	 	REQ_PAIR,
	 	PAIR_RESP,
	 	CTRL
	 	} MessageType;
*/	 	
typedef enum
	{	R_Idle_State,
		R_LengthMSB_State,
		R_LengthLSB_State,
		R_API_State,
		R_AddrMSB_State,
		R_AddrLSB_State,
		R_SigStr_State,
		R_Options_State,
		R_CMD_State,
		R_RF1_State,
		R_FID_State,
		R_STATUS_State
	} R_State;


typedef enum
	{	X_Idle_State,		
		X_StartDelim_State,	
		X_LengthMSB_State,	
		X_LengthLSB_State,	
		X_API_State,			
		X_FID_State,			
		X_AddrMSB_State,
	    X_AddrLSB_State,		
        X_Options_State	,	
        X_CMD_State	,		
        X_RF1_State,			
        X_RF2_State,			
        X_RF3_State,			
        X_RF4_State,			 
        X_RF5_State,			
		X_Checksum_State,
	} X_State;		 	
/*

typedef enum
	{	IDLE,
		PAIR,
		TAG
*/
//Put Function Prototypes Here 	
unsigned char Encode_Message (unsigned char type);


#endif										   