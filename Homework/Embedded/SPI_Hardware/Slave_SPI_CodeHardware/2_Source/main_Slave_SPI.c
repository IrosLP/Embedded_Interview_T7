#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"

#include "Slave_SPI.h"
#include "Delay_Timer.h"

uint8_t data_Transmit[6] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
uint8_t data_Receive[6] = {0, 0, 0, 0, 0, 0};

int main(void){
	SPI_Config();
	TIM2_INT_Init();
	
	delayMs(6000);

	return 0;
}
