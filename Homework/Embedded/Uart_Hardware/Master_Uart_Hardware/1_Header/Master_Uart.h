#ifndef _USARTHARDWARE_H
#define _USARTHARDWARE_H
#include "stm32f10x.h"

#define PORT	GPIOA
#define TX		GPIO_Pin_9
#define RX		GPIO_Pin_10

void UART_Config(void);
void UART_TX(uint8_t *data_Transmit, uint8_t length);

#endif
