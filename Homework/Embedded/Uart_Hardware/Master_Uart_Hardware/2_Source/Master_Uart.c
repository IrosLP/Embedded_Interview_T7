#include "Master_Uart.h"

void UART_Config(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);
	
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
	USART_InitStruct.USART_Mode 								= USART_Mode_Tx;
	USART_InitStruct.USART_Parity 							= USART_Parity_Even;
	USART_Init(USART1, &USART_InitStruct);
	USART_Cmd(USART1, ENABLE);
}

void UART_TX(uint8_t *data_Transmit, uint8_t length){
	//USART_Cmd(USART1, ENABLE);
	for(uint8_t i=0; i<length; i++){
		while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == 0);
		USART_SendData(USART1, data_Transmit[i]);
	}
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == 0) ;
	//USART_Cmd(USART1, DISABLE);
}
