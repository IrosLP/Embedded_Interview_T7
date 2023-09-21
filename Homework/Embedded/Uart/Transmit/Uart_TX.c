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

void transmit(uint8_t data){
    int count=0;
    GPIO_ResetBits(PORT, TX);
    delay(200);
    for(int i=0; i<8; i++){
        if(data & (1<<i)){
            GPIO_SetBits(PORT, TX);
            count++;
        }  
        else    
            GPIO_ResetBits(PORT, TX);
        delay(200);
    }
		
    if(count%2) GPIO_SetBits(PORT, TX);
    else    GPIO_ResetBits(PORT, TX);
    delay(200);
		
    GPIO_SetBits(PORT, TX);
    delay(200);
}

int main(){
    uint8_t data = 0x96; //1010 1011

    config();
    uartInit();
		delay(3000);
    transmit(data);

    return 0;
}