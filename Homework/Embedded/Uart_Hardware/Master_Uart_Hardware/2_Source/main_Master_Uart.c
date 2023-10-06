#include "DelayTimer.h"
#include "Master_Uart.h"

int main(){
	UART_Config(); 
	TIM2_INT_Init();
	
	uint8_t data_Transmit[6] = {0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F};
	
	delayMs(2000);
	UART_TX(data_Transmit, 6);
	
	return 0;
}
