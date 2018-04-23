#include "stm32f10x.h"                  // Device header
#include "FreeRTOS.h"
#include "task.h"

#include "LCD_20x4.h"

#include "BlinkLedTasks.h"
#include "TIMER_DELAY.h"
#include <stdio.h>

void LCD_task1(void){
		uint8_t counter=0;
		while(1){
				LCD_GotoXY(0,1);
				LCD_PutC(counter+0x30);
				DelayMs(1000);
				counter++;
				if(counter==10)	counter=0;
		}		
}

void LCD_task2(void){
		uint8_t h=0,m=0,s=0;
		LCD_GotoXY(0,2);
		while(1){
				LCD_GotoXY(0,2);
				LCD_PutC(h/10+0x30);
				LCD_PutC(h%10+0x30);
				LCD_PutC(':');
				LCD_PutC(m/10+0x30);
				LCD_PutC(m%10+0x30);
				LCD_PutC(':');
				LCD_PutC(s/10+0x30);
				LCD_PutC(s%10+0x30);
				DelayMs(1000);
				s++;
				if(s==60){
						s=0;
						m++;
						if(m==60){
								m=0;
								h++;
								if(h==24){
										h=0;
								}
						}
				}
		}		
}

int main(void){
		SystemInit();
	  initUsTimer();
		blinkLedC13Init();
		blinkLedC15Init();
		DelayMs(15); //Wait for LCD warm-up
		LCD_Init4BitMode();
		DelayMs(5);
		LCD_GotoXY(0,0);
		LCD_PutS("Hello everybody");
		//xTaskCreate(blinkLedC13_task,NULL,configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY,NULL);
		//xTaskCreate(blinkLedC15_task,NULL,configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY,NULL);
		xTaskCreate(LCD_task1,NULL,configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY,NULL);
		xTaskCreate(LCD_task2,NULL,configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY,NULL);
		vTaskStartScheduler();
		return 0;
}
 
