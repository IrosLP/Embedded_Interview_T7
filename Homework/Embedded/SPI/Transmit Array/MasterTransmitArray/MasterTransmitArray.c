//#include "stm32f10x.h"
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
void transmitArray(uint8_t array[], uint8_t length);

int main(){
	uint8_t array[] = {0x91, 0x23, 0x37, 0x14, 0x65, 0x69, 0xF7, 0xA8, 0xB9, 0xCD};
	
	config();
	spiInit();
	delay(3000);
	transmitArray(array, 10);
	
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

void transmitArray(uint8_t array[], uint8_t length){
	for(uint8_t i=0; i < length ; i++){
		transmit(array[i]);
		if(i != length-1) delay(200);
	}
}

void clock(){
	GPIO_ResetBits(PORT, SCK);
	delay(100);
	GPIO_SetBits(PORT, SCK);
	delay(100);
}

