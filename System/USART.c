#include "GPIO.h"

void Serial_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_APB2PeriphClockCmd($USART_GPIORCC, ENABLE);

	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin = $USART_GPIOPin;	
	GPIO_Init($USART_GPIOPort, &GPIO_InitStruct);
	
	USART_InitTypeDef USART_InitStruture;
	USART_InitStruture.USART_BaudRate = 115200;
	USART_InitStruture.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruture.USART_Mode = USART_Mode_Tx;
	USART_InitStruture.USART_Parity = USART_Parity_No;
	USART_InitStruture.USART_StopBits = USART_StopBits_1;
	USART_InitStruture.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStruture);
	
	USART_Cmd(USART1, ENABLE);
}

void Serial_SendByte(u8 Byte)
{
	USART_SendData(USART1,Byte);
	while (USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
}

void Serial_SendArray(u8 *Array)
{
	u16 i;
	for(i=0;i<sizeof(Array)/sizeof(Array[0]);i++)
	{
		Serial_SendByte(Array[i]);
	}
}

void Serial_SendString(s8 *String)
{
	u8 i;
	for(i=0;String[i]!=0;i++)
	{
		Serial_SendByte(String[i]);
	}
}

void Serial_SendNum(u32 num)
{
	u32 label=10;
	while(num>label)
		label *= 10;
	label /= 10;
	while(label>0)
	{
		Serial_SendByte(num/label%10+'0');
		label /= 10;
	}
}
