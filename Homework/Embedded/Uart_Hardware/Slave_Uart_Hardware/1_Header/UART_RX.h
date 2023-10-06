#ifndef _UART_RX_H
#define _UART_RX_H
#include "stm32f10x.h"

#define PORT	GPIOA
#define TX		GPIO_Pin_9
#define RX		GPIO_Pin_10

void UART_RX_Config(void);
void UART_RX(uint8_t *data_Receive);

#endif
