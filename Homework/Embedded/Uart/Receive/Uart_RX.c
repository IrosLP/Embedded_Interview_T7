#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#define TX      GPIO_Pin_6
#define RX      GPIO_Pin_7
#define PORT    GPIOB

void delay(int ms){
	for(int i=0; i<ms; i++)
		for(int j=0; j<4500; j++);
}

void config(){
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	gpio.GPIO_Pin = TX;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT, &gpio);
	
	gpio.GPIO_Pin = RX;
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PORT, &gpio);
}

void uartInit(){
    GPIO_SetBits(PORT, TX);
}

uint8_t receive(){
	
  uint8_t data = 0x00; //0000 0000
  int count = 0;
	again:
	while(GPIO_ReadInputDataBit(PORT, RX));
	delay(300);
	for(int i=0; i<8; i++){
		if(GPIO_ReadInputDataBit(PORT, RX)){
			data |= (1<<i);
			count++;
		}
		delay(200);
	}
	if((GPIO_ReadInputDataBit(PORT, RX) == 0 && count%2 == 0)
	 ||(GPIO_ReadInputDataBit(PORT, RX) == 1 && count%2 == 1));
	else goto again;
	delay(200);
	if(GPIO_ReadInputDataBit(PORT, RX));
	else goto again;
  return data;
}

int main(){
    uint8_t data = 0x00;
		
    config();
    uartInit();
		while(1){
			data = receive();
		}

    return 0;
}