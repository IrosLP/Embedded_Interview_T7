#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h" 

#include "Master_SPI.h"
#include "Delay_Timer.h"

int main(){
	SPI_Config();
	TIM2_INT_Init();
	
	uint8_t data_Transmit[6] = {0x10, 0x20, 0x30, 0x40, 0x50, 0x60};
	uint8_t data_Receive[6] = {0, 0, 0, 0, 0, 0};
	
	delayMs(3000);
	
	SPI_TransmitReceive(data_Transmit, data_Receive, 6);
	
	return 0;
}
