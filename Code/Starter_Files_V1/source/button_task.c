#include "button_task.h"



void button_task(void *pvParameters){

	pinState_t btn_state;
	uint8_t sec_counter =0;
	for(;;){
		btn_state = GPIO_read(PORT_0, ((button_task_config *)pvParameters)->pin_num);
		if(btn_state == PIN_IS_HIGH){

			while(btn_state == PIN_IS_HIGH){
				vTaskDelay(1000);
				sec_counter++;
				btn_state = GPIO_read(PORT_0, ((button_task_config *)pvParameters)->pin_num);
			}
			if(sec_counter>4){
				*(((button_task_config *)pvParameters)->led_delay)= 100;
			}else if((sec_counter>2) && (sec_counter<4)){
				*(((button_task_config *)pvParameters)->led_delay)= 400;
			}else if(sec_counter<2){
				*(((button_task_config *)pvParameters)->led_delay)= 0;
			}else{

			}

			sec_counter = 0;

		}
		vTaskDelay(200);
	}

}