#include "DelayTimer.h"
#include "UART_RX.h"

uint8_t data_Receive[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

int main(){
	UART_RX_Config();
	TIM2_INT_Init();
		
	delayMs(5000);
	
	return 0;
}
