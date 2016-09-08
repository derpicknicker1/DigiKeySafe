/*
 * IntelliKeySafe
 *
 * Created: 06.09.2016 08:55:10
 * Author : Florian Schütte
 */ 
#include "config.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <stdio.h>
#include <stdint.h>
#include <util/delay.h>
#include "uart.h"
#include "servo.h"
#include "touch.h"
#include "leds.h"
#include "sense.h"

extern char uart_string[UART_MAXSTRLEN + 1];

void sleep_now() {
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sleep_enable();
	sleep_mode();
	sleep_disable();
}

void init(void)
{
	//servo_init();
	uart_init();
	touch_init();
	leds_init();
	sense_init();
	sei();
	//sbi(PORTC,PC7);						// pullup PC7
}

int main( void )
{
	init();
	//unsigned char servo[NUM_SERVOS];
	//for(uint8_t n=0;n<NUM_SERVOS;n++) servo_set(n,servo[n]);
	//servo[0] += 10;
	int values[5] = {0,0,0,0,0};
	int ref[5] = {0,0,0,0,0};
	for(int i=0; i<5; i++)				// read reference values
		ref[i] = touch_read(i,100);
	while( 1 ) {
		leds_toggle(7);
		for(int i = 0;i <5;i++){
			values[i] = touch_read(i,100) - ref[i];
			printf("%d, ",values[i]);
			leds_set(i,(values[i]>10)?ON:OFF);
		}
		uart_puts("\r\n");
		//sleep_now();
		//if ( !(PINC & (1<<PINC7)) )
			//PORTC |= 0x1F;
		_delay_ms(1000);		
	}
}




