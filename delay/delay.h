#ifndef DELAY_H__
	#define DELAY_H__
	#include <stdint.h>
	//
	typedef void(*init_f_tim_delay)(void);
	//

	//init_f_tim_delay - the function of initialization timer
	void init(init_f_tim_delay);

	/*
	 * callback function counters
	 * call this functions from interrupt handler
	 */
	void counter_s_cb();
	void counter_ms_cb();
	void counter_us_cb();

	//
	void delay_s(uint32_t);
	void delay_ms(uint16_t);
	void delay_us(uint8_t);

#endif
