#ifndef BLINKLEDTASKS_H
#define BLINKLEDTASKS_H

#include "stm32f10x.h"                  // Device header
#include "FreeRTOS.h"
#include "task.h"

void blinkLedC13Init(void);
void blinkLedB12Init(void);

void blinkLedC13_task(void);
void blinkLedB12_task(void);

#endif
