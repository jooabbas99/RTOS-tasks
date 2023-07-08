
#ifndef LED_TASK_H
#define LED_TASK_H

#include "FreeRTOS.h"
#include "GPIO.h"
#include "task.h"
#include "semphr.h"


typedef enum{
	LED_OFF,
	LED_ON
}led_state;
/* configration struct to config the task with wanted pin to toggle and its duration*/
typedef struct{
    pinX_t pin_num;
    SemaphoreHandle_t *semaphore;
}led_task_config;

/*task to toggle the led every 1 sec*/
void ledTask(void *pvParameters);


#endif