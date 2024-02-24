#include "stm32f10x.h"
#include "LED.h"
#include "IntTimer.h"

u8 Num = 0;

int main(void)
{
	LED_Init();
	INTTIMER_Init();
	void KEY_Init(void);
	
	while(1)
	{
		LED_Set(0,Num%2);
		LED_Set(1,(1+Num)%2);
	}
}

void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		Num++;
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
