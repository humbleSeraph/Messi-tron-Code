#ifndef PropellerModule_H
#define PropellerModule_H 

//Put Function Prototypes Here 	
void Initialize_PropellerModule (void);
//unsigned char Initialize_PropellerModule (void);
void Steer_Player (char , char );
void Initialize_ServoModule (void);
void Set_Servo1 (unsigned char);
void Set_Servo2 (unsigned char);
void Kick(void);
void Energy_Level (unsigned char);
#endif										   