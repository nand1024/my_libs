#include "delay.h"

static uint32_t counter_sek;
static uint16_t counter_msek;
static uint8_t counter_usek;
static uint8_t trig_start = 0;


void init(init_f_tim_delay func_init_cb){
	func_init_cb();
	trig_start = 1;
}


void counter_s_cb(){
	if(counter_sek)counter_sek--;
}


void counter_ms_cb(){
	if(counter_msek)counter_msek--;
}


void counter_us_cb(){
	if(counter_usek)counter_usek--;
}


void delay_s(uint32_t waitVal){
	if(!trig_start)return;
	counter_sek = waitVal;
	while(counter_sek);
}


void delay_ms(uint16_t waitVal){
	if(!trig_start)return;
	counter_msek = waitVal;
	while(counter_msek);
}


void delay_us(uint8_t waitVal){
	if(!trig_start)return;
	counter_usek = waitVal;
	while(counter_usek);
}
