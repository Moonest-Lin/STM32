#include "GPIO.h"
#include "delay.h"

void KEY_Init(void)
{
	RCC_APB2PeriphClockCmd($KeyUp_RCC | $Key0_RCC, ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStruct.GPIO_Pin = $Key0_GPIOPin;	
	GPIO_Init($Key0_GPIOPort, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStruct.GPIO_Pin = $KeyUp_GPIOPin;
	GPIO_Init($KeyUp_GPIOPort, &GPIO_InitStruct);
}

u8 KEY_GetNum(void)
{
	u8 KeyNum = 0;
	if (GPIO_ReadInputDataBit($Key0_GPIOPort,$Key0_GPIOPin))
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit($Key0_GPIOPort,$Key0_GPIOPin));
		Delay_ms(20);
		KeyNum = 1;
	}
	else if (GPIO_ReadInputDataBit($KeyUp_GPIOPort,$KeyUp_GPIOPin))
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit($KeyUp_GPIOPort,$KeyUp_GPIOPin))
		Delay_ms(20);
		KeyNum = 2;
	}
	return KeyNum;
}
