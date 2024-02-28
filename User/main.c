#include "stm32f10x.h"
#include "usart.h"

int main(void)
{
	Serial_Init();
	
	while(1)
	{
		if(Serial_GetRxFlag() == 1)
		{
			Serial_TxPacket[0]=Serial_RxPacket[0];
			Serial_TxPacket[1]=Serial_RxPacket[1];
			Serial_TxPacket[2]=Serial_RxPacket[2];
			Serial_TxPacket[3]=Serial_RxPacket[3];
			Serial_SendPacket();
		}
	}
}
