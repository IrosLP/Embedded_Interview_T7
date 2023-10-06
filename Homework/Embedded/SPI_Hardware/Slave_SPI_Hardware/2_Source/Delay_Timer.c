#include "Delay_Timer.h"

uint32_t milliSec = 0;

void TIM2_INT_Init(){
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_Prescaler = 3600;
	TIM_TimeBaseInitStruct.TIM_Period = 19;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);//khoi tao Timer
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//khoi tao ngat
	TIM_Cmd(TIM2, ENABLE);//bat dau dem timer

	//Tao do uu tien cho timer (do uu tien lon hon se dc chay truoc)
	NVIC_InitTypeDef NVIC_InitStruct;//cau hinh do uu tien
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;//cho Timer
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;//do uu tien chinh
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;//do uu tien phu
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;//bat do uu tien cho timer nay
	NVIC_Init(&NVIC_InitStruct);//khoi tao do uu tien
}

void TIM2_IRQHandler() {
	if(TIM_GetITStatus(TIM2, TIM_IT_Update)){
		milliSec++;
		if(GPIO_ReadInputDataBit(PORT1, SS) == 0)		
			SPI_SendReceive(data_Transmit, data_Receive);
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}

void delayMs (uint32_t ms) {
	milliSec = 0;
	while (milliSec < ms) {};
}


