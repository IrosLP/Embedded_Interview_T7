#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#define SCK		GPIO_Pin_6
#define MOSI	GPIO_Pin_7
#define SS		GPIO_Pin_8
#define PORT	GPIOB

void delay(int ms);
void config(void);
void spiInit(void);
void clock(void);
void transmit(uint8_t data);

int main(){
	uint8_t data = 0x50; //10010110
	
	config();
	spiInit();
	delay(3000);
	transmit(data);
	
	return 0;
}

void delay(int ms){
	for(int i=0; i<ms; i++)
		for(int j=0; j<4500; j++);
}

void config(){
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	gpio.GPIO_Pin = SCK | MOSI | SS;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT, &gpio);
}

void spiInit(){
	GPIO_ResetBits(PORT, SCK);
	GPIO_ResetBits(PORT, MOSI);
	GPIO_SetBits(PORT, SS);
}

void transmit(uint8_t data){
	GPIO_ResetBits(PORT, SS);
	for(uint8_t i=0; i<8 ; i++){
		if(data & (0x01 << i))	GPIO_SetBits(PORT, MOSI);
		else GPIO_ResetBits(PORT, MOSI);
		clock();
	}
	GPIO_ResetBits(PORT, MOSI);
	GPIO_ResetBits(PORT, SCK);
	GPIO_SetBits(PORT, SS);
}

void clock(){
	GPIO_ResetBits(PORT, SCK);
	delay(500);
	GPIO_SetBits(PORT, SCK);
	delay(500);
}
