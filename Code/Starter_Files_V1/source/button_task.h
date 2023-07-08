#ifndef button_TASK_H
#define button_TASK_H
#include "FreeRTOS.h"
#include "GPIO.h"
#include "task.h"
#include "semphr.h"
/* configration struct to config the task with wanted pin to toggle and its duration*/
typedef struct{
    pinX_t pin_num;	
	SemaphoreHandle_t *semaphore; /*pointer to semaphore*/
}button_task_config;


/*task to toggle the led every 1 sec*/
void button_task(void *pvParameters);

#endif