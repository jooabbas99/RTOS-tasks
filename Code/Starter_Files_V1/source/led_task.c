
#include "led_task.h"


void ledTask(void *pvParameters)
{
	led_state prev_state = LED_OFF;
	GPIO_write(PORT_0, ((led_task_config *)pvParameters)->pin_num, PIN_IS_LOW);
	for( ; ; ){
				if( xSemaphoreTake( *(((led_task_config *)pvParameters)->semaphore), ( TickType_t ) 0) == pdTRUE ){
					 if(prev_state == LED_OFF){
						 GPIO_write(PORT_0, ((led_task_config *)pvParameters)->pin_num, PIN_IS_HIGH);
						 prev_state = LED_ON;
					 }else{
						 GPIO_write(PORT_0, ((led_task_config *)pvParameters)->pin_num, PIN_IS_LOW);
						 prev_state = LED_OFF;
					 }
				}
					vTaskDelay(25);
	}
}