//Propeller Control Module for ME218c Project
//Performs PWM Setup and Sets Propeller Speed on E128

#include <hidef.h>
#include <mc9s12e128.h>
#include <S12e128bits.h>
#include <Bin_Const.h>
#include <termio.h>
#include <stdio.h>


#include "PropellerModule.h"

//Max_PWM can be from 0 to 100
#define Max_PWM 100

//Adding history variables for smoothing out PWM
static unsigned char OldLeft = 0;
static unsigned char OldRight = 0;

void Set_Speed (unsigned char DutyLeft,unsigned char DutyRight);

void Initialize_PropellerModule (void)
{
	//Perform PWM Setup for Channel 5 & 4 (PU5,PU4)
	//PWM Frequency = 100Hz PreScalar = 128 Scalar = 10
	
	PWMCLK |= (_S12_PCLK5 | _S12_PCLK4);	
	
	//Set Polarity = 1
	
	PWMPOL |= (_S12_PPOL5 | _S12_PPOL4); 	
		
	PWMPRCLK |= (_S12_PCKA0 | _S12_PCKA1 | _S12_PCKA2);
	
	PWMSCLA = 10;
	
	PWMPER5 = 100;
	
	PWMPER4 = 100;
	
	//Enable the PWM Sub-System
	PWME |= (_S12_PWME5 | _S12_PWME4);
	
	//Initialize with Zero Duty Cycle
	PWMDTY5 = 0;
	PWMDTY4 = 0;
	


}


void Initialize_ServoModule (void)
{
	//Module to Setup PWM Channel 2 & 3 for servo control AT 50 Hz
	PWMCLK |= (_S12_PCLK2 | _S12_PCLK3);
	PWMPOL |= (_S12_PPOL2 | _S12_PPOL3);
	PWMPRCLK |= (_S12_PCKB0 | _S12_PCKB1 | _S12_PCKB2);
	PWMSCLB = 20;
	PWMPER2 = 100;
	PWMPER3 = 100;
	//Enable the PWM Sub-System
	PWME |= (_S12_PWME2 | _S12_PWME3);
	
	//Test Commands
	Set_Servo1(5);
	Set_Servo2(8);
	
}



void Set_Speed (unsigned char DutyLeft,unsigned char DutyRight)
{
	//Sets PWM Duty Cycle for both Propellers
	//Acceptable value is from 0 to 100
	
	//Added Patch for Moving average filter to make PWM smooth
	
	if((DutyLeft==0)&&(DutyRight==0))
	{
		PWMDTY5 = 0;
		PWMDTY4 = 0;
	}
	else
	{
	
		//DutyLeft = (0.9 * OldLeft) + (0.1 * DutyLeft);
	//	DutyRight = (0.9 * OldRight) + (0.1 * DutyRight);
	
		if (DutyLeft>Max_PWM)
		DutyLeft = Max_PWM;
		
		if (DutyRight>Max_PWM)
		DutyRight = Max_PWM;
		
		PWMDTY5 = DutyLeft;
		PWMDTY4 = DutyRight;
		
		OldLeft = DutyLeft;
		OldRight = DutyRight;
	}
}

void Steer_Player (char Translation, char Rotation)
{
	
	unsigned char DutyLeft, DutyRight;
	
	unsigned int T;
	signed int R;
	
	
	

//	Scaling values to 0 to 100
	if (Translation<0)
	Translation =  -1*Translation;
	
	
	T=(Translation*(Max_PWM))/128;
	R=(Rotation*(Max_PWM))/128;

	
	//Computing Individual Duty Cycles
    if (Rotation<0)
    	{   
    	 	 R = -1*R;
    	 	 DutyLeft = T + R;
   			 DutyRight = T - R;
   			 if (T<R)
   			 DutyRight = 0;
     	}
    else
    	{
    		 DutyRight = T + R;
    		 DutyLeft = T - R;
    		 if (T<R)
    		 DutyLeft = 0;
    	}
    	
    		  	 
        
    //Setting the DutyCycles
    Set_Speed(DutyLeft,DutyRight);
    
    
    

}

void Set_Servo1 (unsigned char Duty)
{
	//Expects a value for Duty from 0 - 100
	if (Duty>100)
	Duty = 100;
	
	PWMDTY2 = Duty;

 
}


void Set_Servo2 (unsigned char Duty)
{	
	//Expects a value for Duty from 0 - 100
	if (Duty>100)
	Duty = 100;
	
	PWMDTY3 = Duty;

 
}

void Kick (void)
{
	unsigned int i=0,j=0;
	
	Set_Servo1(25);
	
	for (i=0;i<65535;i++)
	{for (j=0;j<5;j++)
	;}
	
	
	Set_Servo1(5);


}


void Energy_Level(unsigned char level)
{
	unsigned char duty=0;
	
	if (level>=7)
	level = 7;
	
	duty = (level*3) + 5;
	Set_Servo2(duty);

	

}




