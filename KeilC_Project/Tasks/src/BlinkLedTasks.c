#include "BlinkLedTasks.h"

void blinkLedC13Init()
{
		 GPIO_InitTypeDef  blinkLed;
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
		 blinkLed.GPIO_Pin = GPIO_Pin_13;   
		 blinkLed.GPIO_Mode = GPIO_Mode_Out_PP;
		 blinkLed.GPIO_Speed = GPIO_Speed_50MHz;
		 GPIO_Init(GPIOC, &blinkLed);
}

void blinkLedB12Init()
{
		 GPIO_InitTypeDef  blinkLed;
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
		 blinkLed.GPIO_Pin = GPIO_Pin_12;   
		 blinkLed.GPIO_Mode = GPIO_Mode_Out_PP;
		 blinkLed.GPIO_Speed = GPIO_Speed_50MHz;
		 GPIO_Init(GPIOB, &blinkLed);
}

void blinkLedC13_task(){
		while(1){
				GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);
				vTaskDelay(1000);
				GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_SET);
				vTaskDelay(1000);
		}
		vTaskDelete(NULL);
}

void blinkLedB12_task(){
		while(1){
				GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_RESET);
				vTaskDelay(100);
				GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_SET);
				vTaskDelay(100);
		}
		vTaskDelete(NULL);
}
