#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#define SCK		GPIO_Pin_6
#define MOSI	GPIO_Pin_7
#define SS		GPIO_Pin_8
#define PORT	GPIOB

void config(void);
//void check(void);
uint8_t receive(void);

int main(){
	uint8_t data = 0x00;
	config();
	while(1){
		data = receive();
	}
	return 0;
}

void config(){
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		
	gpio.GPIO_Pin = SCK | MOSI;
	gpio.GPIO_Mode = GPIO_Mode_IPD;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT, &gpio);
	
	gpio.GPIO_Pin = SS;
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT, &gpio);
}

uint8_t receive(){
	uint8_t data = 0x00;
	while(GPIO_ReadInputDataBit(PORT, SS) == 1);
	for(uint8_t i=0; i<8; i++){
		while(GPIO_ReadInputDataBit(PORT, SCK) == 0);
		if(GPIO_ReadInputDataBit(PORT, MOSI))	data |= (0x01<<i);
		while(GPIO_ReadInputDataBit(PORT, SCK) == 1);
	}
	while(GPIO_ReadInputDataBit(PORT, SS) == 0);
	return data;
}
