#include "Slave_SPI.h"

void SPI_Config(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1 | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE); /*cap xung clock cho cac port nay*/
	
	GPIO_InitTypeDef GPIO_InitStruct;
	SPI_InitTypeDef SPI_InitStruct;
	
	GPIO_InitStruct.GPIO_Pin = MOSI | MISO | SCK;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT1, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = SS;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT1, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = LED;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(PORT2, &GPIO_InitStruct);
	
	SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex; /*chon che do 2 line nhan truyen cung luc*/
	SPI_InitStruct.SPI_Mode = SPI_Mode_Slave; /*chon lam master/slave*/
	SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b; /*chon size data 8/16 bit du lieu cho 1 lan truyen*/
	SPI_InitStruct.SPI_CPOL = SPI_CPOL_High; /*CPOL = 1 (Master va Slave phair giong nhau)*/
	SPI_InitStruct.SPI_CPHA = SPI_CPHA_2Edge; /*CPHA = 1 (Master va Slave phair giong nhau)*/
	SPI_InitStruct.SPI_NSS = SPI_NSS_Soft; /*chon che do software/hardware cho chan SS*/
	SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128; /*tan so truyen (chia cho 256). Ben slave phai co bo chia tan so be hon master (tan so slave => tan so master)*/
	SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB; /*chon bit MSB gui truoc (Slave cung phai chon MSB nhan truoc)*/
	SPI_Init(SPI1, &SPI_InitStruct);
	 
	SPI_Cmd(SPI1, ENABLE);
}

void SPI_SendReceive(uint8_t *data_Transmit, uint8_t *data_Receive){
	SPI_I2S_SendData(SPI1, data_Transmit[0]);
	
	uint8_t i = 1;
	for(; i<9; i++){
		while(!SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE));
		SPI_I2S_SendData(SPI1, data_Transmit[i]);
		
		while(!SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE));
		data_Receive[i-1] = SPI_I2S_ReceiveData(SPI1);
		
		if(GPIO_ReadInputDataBit(PORT1, SS)) break;
	}
	while(!SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE));
	data_Receive[i] = SPI_I2S_ReceiveData(SPI1);
}
