#include "stm32f10x.h"
#include "OLED.h"

int main(void)
{
	OLED_Init();
	OLED_ShowChar(1,1,'A');
	OLED_ShowString(1,3,"Hello");
	OLED_ShowHexNum(4,1,20,2);
	OLED_ShowNum(3,1,666,4);
	while(1)
	{
	}
}
