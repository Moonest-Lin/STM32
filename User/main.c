#include "stm32f10x.h"
#include "LED.h"
#include "CountSensor.h"
#include "delay.h"
#include "usart.h"

u8 Num = 0;

int main(void)
{
	u8 test[4]={'A','B','C','D'};
	s8 ttest[]="TTT888";
	LED_Init();
	CountSensor_Init();
	Serial_Init();
	Serial_SendByte('A');
	Serial_SendArray(test);
	Serial_SendString(ttest);
	Serial_SendNum(12345);
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
