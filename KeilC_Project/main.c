#include "stm32f10x.h"                  // Device header
#include "FreeRTOS.h"
#include "task.h"

#include "LCD_20x4.h"

#include "BlinkLedTasks.h"

int main(void){
		SystemInit();
	  initUsTimer();
		blinkLedC13Init();
		blinkLedC15Init();
		LCD_Init4BitMode();
		DelayMs(5);
		LCD_GotoXY(0,0);
		LCD_PutS("Hello everybody");
		xTaskCreate(blinkLedC13_task,NULL,configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY,NULL);
		xTaskCreate(blinkLedC15_task,NULL,configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY,NULL);
		vTaskStartScheduler();
		return 0;
}
 
