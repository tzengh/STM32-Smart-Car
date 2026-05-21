#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "SmartCar.h"
#include "Serial.h"
#include "HCSR04.h"
#include "Servo.h"
#include "LineWalking.h"
#include "Buzzer.h"
#include "DHT11.h"
uint8_t RxData,Num;
uint8_t Servo_Flag;
int main(void)
{
	HCSR04_Init();
	OLED_Init();	
	SmartCar_Init();
	Serial_Init();
	Servo_Init();
	LineWalking_Init();
	Buzzer_Init();
	DHT11_Init();
	Servo_SetAngle(90);
	OLED_ShowString(1,1,"Distance:");
	OLED_ShowString(2,4,"CM");
	OLED_ShowString(3,1,"Status:");
	Delay_ms(310);
	while(1)
	{
		
		if(Serial_GetRxFlag()==1)
		{
			RxData=Serial_GetRxData();
			Servo_Flag=1;
		}
		
		if(RxData==0x40)
		{
			Num=1;
			OLED_ShowString(1,1,"            ");
			OLED_ShowString(3,1,"Status:   ");
			OLED_ShowString(4,1,"Move_Forward    ");
			OLED_ShowString(2,1,"          ");
		}
		if(RxData==0x41)
		{
			Num=2;	
			OLED_ShowString(1,1,"            ");
			OLED_ShowString(3,1,"Status:   ");
			OLED_ShowString(4,1,"Move_Backward   ");
			OLED_ShowString(2,1,"          ");
		}
		if(RxData==0x42)
		{
			Num=3;
			OLED_ShowString(1,1,"            ");
			OLED_ShowString(3,1,"Status:   ");
			OLED_ShowString(4,1,"Stop            ");
			OLED_ShowString(2,1,"          ");
		}
		if(RxData==0x43)
		{
			Num=4;
			OLED_ShowString(1,1,"            ");
			OLED_ShowString(3,1,"Status:   ");
			OLED_ShowString(4,1,"Turn_Lef        ");
			OLED_ShowString(2,1,"         ");
		}
		if(RxData==0x44)
		{
			Num=5; 
			OLED_ShowString(1,1,"            ");
			OLED_ShowString(3,1,"Status:   ");
			OLED_ShowString(4,1,"Turn_Right      ");
			OLED_ShowString(2,1,"         ");
		}
		if(RxData==0x45)
		{
			Num=6;
			OLED_ShowString(1,1,"            ");
			OLED_ShowString(3,1,"Status:   ");
			OLED_ShowString(4,1,"Rotation_Right  ");
			OLED_ShowString(2,1,"         ");
		}
		if(RxData==0x46)
		{
			Num=7;
			OLED_ShowString(1,1,"            ");
			OLED_ShowString(3,1,"Status:   ");
			OLED_ShowString(4,1,"Rotation_Left   ");
			OLED_ShowString(2,1,"         ");
		}
		if(RxData==0x47)
		{
			Num=8;
			OLED_ShowString(1,1,"            ");
			OLED_ShowString(3,1,"Status:   ");
			OLED_ShowString(4,1,"LineWalking     ");
			OLED_ShowString(2,1,"         ");
		}
		if(RxData==0x48)
		{
			Num=9;
			OLED_ShowString(1,1,"Distance:   ");
			OLED_ShowString(2,4,"CM");
			OLED_ShowString(3,1,"Status:   ");
			OLED_ShowString(4,1,"bizhang         ");

		}	
		if(RxData==0x49)
		{
			Num=10;
			OLED_ShowString(1,1,"Distance:    ");
			OLED_ShowString(2,4,"CM");
			OLED_ShowString(3,1,"Status:   ");
      OLED_ShowString(4,1,"gensui          ");
		}
		if(RxData==0x50)
		{
			Num=11;
		}
		if(RxData==0x51)
		{
			Num=12;
			OLED_ShowString(1,1,"            ");
			OLED_ShowString(3,1,"Status:   ");
			OLED_ShowString(4,1,"Cammer down    ");
			OLED_ShowString(2,1,"         ");
		}
		if(RxData==0x52)
		{
			
			Num=13;
			OLED_ShowString(1,1,"            ");
			OLED_ShowString(3,1,"Status:   ");
			OLED_ShowString(4,1,"Cammer  up    ");
			OLED_ShowString(2,1,"         ");
			
		}
		switch(Num)
		{
			case 1:Move_Forward();
		  break;
			case 2:Move_Backward();
		  break;
			case 3:Car_Stop();
		  break;
			case 4:Turn_Left(40);
		  break;
			case 5:Turn_Right(40);
		  break;
			case 6:Clockwise_Rotation();
		  break;
			case 7:CounterClockwise_Rotation();
		  break;
			case 8:LineWalking();
		  break;
			case 9:AvoidObstacle();
		  break;
			case 10:Following();
		  break;
			case 11:DHT11_Value();
			break;	
			case 12:Servo_SetAngle_Plus();
			break;
			case 13:Servo_SetAngle_Mins();
			break;
			default:
			break;
		}
	}
		
}
	
	


