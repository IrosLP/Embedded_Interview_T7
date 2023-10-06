#ifndef _LIBRARY_MASTER_SPI_HARDWARE_H
#define _LIBRARY_MASTER_SPI_HARDWARE_H
#include "stm32f10x.h"
#include "stm32f10x_spi.h"
#include "stm32f10x_rcc.h"

#define PORT1	GPIOA
#define MOSI	GPIO_Pin_7
#define MISO	GPIO_Pin_6
#define SCK		GPIO_Pin_5
#define SS		GPIO_Pin_4

#define PORT2	GPIOC
#define LED		GPIO_Pin_13

void SPI_Config(void);
void SPI_SendReceive(uint8_t *data_Transmit, uint8_t *data_Receive);

#endif
