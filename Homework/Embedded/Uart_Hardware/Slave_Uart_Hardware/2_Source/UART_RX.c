#include "UART_RX.h"

//USART_StructInit(USART_InitTypeDef* USART_InitStruct)

void UART_RX_Config(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = TX;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin = RX;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT, &GPIO_InitStruct);
	
	USART_InitStruct.USART_BaudRate 						= 9600; //PKCL2
	USART_InitStruct.USART_WordLength 					= USART_WordLength_9b;
	USART_InitStruct.USART_StopBits 						= USART_StopBits_2;
	USART_InitStruct.USART_HardwareFlowControl 	= USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode 								= USART_Mode_Rx;
	USART_InitStruct.USART_Parity 							= USART_Parity_Even;
	USART_Init(USART1, &USART_InitStruct);
	USART_Cmd(USART1, ENABLE);
}

void UART_RX(uint8_t *data_Receive){
	//USART_FLAG_TC
	//USART_FLAG_TXE
	/*uint8_t i=0;
	while(1){
		while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == 0);
		data_Receive[i] = USART_ReceiveData(USART1);
		i++;
		USART_ClearFlag(USART1, USART_FLAG_RXNE);
	}*/
	//while(GPIO_ReadInputDataBit(PORT, RX) == 1);
	uint8_t i=0;
	while(1){
		while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == 0);
		data_Receive[i] = USART_ReceiveData(USART1);
		USART_ClearFlag(USART1, USART_FLAG_RXNE);
		if(i==5) break;
		i++;
	}
}
