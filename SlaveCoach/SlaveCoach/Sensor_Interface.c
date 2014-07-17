//Sensor Interfacing module for Coach (Team 8)

#include "Sensor_Interface.h"

__CONFIG(CP_OFF & WDTE_OFF & MCLRE_ON & FOSC_HS);

//#define NominalAcceleration 100


static unsigned char NominalAccelerationLeft = 0;
static unsigned char NominalAccelerationRight = 0;
static unsigned char LeftThrust = 0;
static unsigned char RightThrust = 0;
static unsigned char LeftCrossingFlag = 0;
static unsigned char RightCrossingFlag = 0;

static unsigned char LeftZCR = 0;
static unsigned char RightZCR = 0;

void main (void)
{	
	//Initialize the Sensor Interface
	Initialize_Sensors();
		
	while(1)
		{
			Read_Thrust();
			if (RightThrust>NominalAccelerationRight)
				{
					if (RightCrossingFlag == 1)
						{
							RightCrossingFlag = 0;
							RightZCR++;
						}
				
				}
			else
				{	
					if (RightCrossingFlag == 0)
						{
							RightCrossingFlag = 1;
							RightZCR++;
						}
					
				}
			//PORTC = RightZCR;
			if (LeftThrust>NominalAccelerationLeft)
				{
					if (LeftCrossingFlag == 1)
						{
							LeftCrossingFlag = 0;
							LeftZCR++;
						}
				
				}
			else
				{	
					if (LeftCrossingFlag == 0)
						{
							LeftCrossingFlag = 1;
							LeftZCR++;
						}
					
				}
			PORTC = LeftZCR;
		}


}

void Initialize_Sensors(void)
{	
	//Setting up RA0 & RA1 for ADC
	ANSEL = 0b00000011;
	ANSELH = 0x00;
	TRISA = 0xFF;
	//Clock Divisor = 32
	ADCON1 = BIT5HI;
	//ADFM = 0 for Left Justified
	

	//Setup NominalAcceleration (Self Calibration Process)
	//First Read RA0
	ADCON0 = (BIT1HI|BIT0HI);
	
	while (ADCON0 & BIT1HI)
	;

	NominalAccelerationLeft = ADRESH;

	//Second Read RA1
	ADCON0 = (BIT2HI|BIT1HI|BIT0HI);
	
	while (ADCON0 & BIT1HI)
	;

	NominalAccelerationRight = ADRESH;
	

	//Debug PORT
	TRISC = 0x00;
	TRISB = 0X00;
}



void Read_Thrust(void)
{	
	//Reads the Accelerometer Values and updates the module level variables
	//First Read RA0
	ADCON0 = (BIT1HI|BIT0HI);
	


	while (ADCON0 & BIT1HI)
	;

	LeftThrust = ADRESH;

	//Second Read RA1
	ADCON0 = (BIT2HI|BIT1HI|BIT0HI);
	
	while (ADCON0 & BIT1HI)
	;

	RightThrust = ADRESH;



}