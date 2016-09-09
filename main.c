/*
 * IntelliKeySafe
 *
 * Created: 06.09.2016 08:55:10
 * Author : Florian Schütte
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <stdio.h>
#include <stdint.h>
#include "config.h"
#include "uart.h"
#include "servo.h"
#include "touch.h"
#include "leds.h"
#include "sense.h"
#include "TWI_Slave.h"

extern char uart_string[UART_MAXSTRLEN + 1];

void sleep_now() {
	set_sleep_mode(SLEEP_MODE_IDLE);
	servo_set_int(OFF);
	sleep_enable();
	sleep_mode();
	sleep_disable();
	servo_set_int(ON);
}

void sense_isr_handle(void)
{
	if(sense_is_high(SENSE_1))
		leds_set(7,ON);
	else
		leds_set(7,OFF);
}

void init(void)
{
	servo_init();
	//uart_init();
	touch_init();
	leds_init();
	sense_init(sense_isr_handle);
	//TWIS_Init (15, 100000);
	sei();
}

int main( void )
{
	init();
	//unsigned char servo[NUM_SERVOS];
	//for(uint8_t n=0;n<NUM_SERVOS;n++) servo_set(n,servo[n]);
	//servo[0] += 10;
	int values[TOUCH_CH_NUM];
	
	while( 1 ) {
		for(int i = 0;i < TOUCH_CH_NUM;i++){
			values[i] = touch_read(i,100) - touch_ref(i);
			printf("%d, ",values[i]);
			leds_set(i,(values[i]>10)?ON:OFF);
		}
		uart_puts("\r\n");
		sleep_now();
	}
}




