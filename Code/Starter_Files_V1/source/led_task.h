
#ifndef LED_TASK_H
#define LED_TASK_H

#include "FreeRTOS.h"
#include "GPIO.h"
#include "task.h"


/*task to toggle the led every 1 sec*/
void ledTask(void *pvParameters);
#endif