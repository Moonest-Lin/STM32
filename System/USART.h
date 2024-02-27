#ifndef __USART_H__
#define __USART_H__

void Serial_Init(void);
void Serial_SendByte(u8 Byte);
void Serial_SendArray(u8 *Array);
void Serial_SendString(s8 *String);
void Serial_SendNum(u32 num);

#endif
