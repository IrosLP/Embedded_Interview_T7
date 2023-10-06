#ifndef _DELAY_TIMER_H
#define _DELAY_TIMER_H
#include "stm32f10x.h"
#include "Slave_SPI.h"

extern uint8_t data_Transmit[6];
extern uint8_t data_Receive[6];

void TIM2_INT_Init();
void TIM2_IRQHandler();
void delayMs(uint32_t ms);

#endif
