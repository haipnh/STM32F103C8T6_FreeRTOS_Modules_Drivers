#include "stm32f10x.h"                  // Device header
#include "FreeRTOS.h"
#include "task.h"

#include "BlinkLedTasks.h"

int main(void){
		SystemInit();
		blinkLedC13Init();
		blinkLedB12Init();
		xTaskCreate(blinkLedC13_task,NULL,configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY,NULL);
		xTaskCreate(blinkLedB12_task,NULL,configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY,NULL);
		vTaskStartScheduler();
		return 0;
}
