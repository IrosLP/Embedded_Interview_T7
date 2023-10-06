#ifndef _DELAY_TIMER_H
#define _DELAY_TIMER_H
#include "stm32f10x.h"

//uint32_t milliSec = 0;

void TIM2_INT_Init();
void TIM2_IRQHandler();
void delayMs (uint32_t ms);

#endif
