#include "stm32f10x.h"
#include "LED.h"
#include "CountSensor.h"
#include "delay.h"

u8 Num = 0;

int main(void)
{
	LED_Init();
	CountSensor_Init();
	
	while(1)
	{
		Num = CountSensor_GetCount();
		if(Num%2==1)
		{
		LED_Reversal(0);
		LED_Reversal(1);
		}
	}
}
