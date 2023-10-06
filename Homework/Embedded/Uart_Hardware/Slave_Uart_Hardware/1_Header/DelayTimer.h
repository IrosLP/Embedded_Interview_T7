#ifndef _DELAYTIMER_H
#define _DELAYTIMER_H
#include "stm32f10x.h"

void TIM2_INT_Init(void);
void TIM2_IRQHandler(void);
void delayMs(uint32_t ms);

#endif
