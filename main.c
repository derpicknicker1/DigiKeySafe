/*
 * IntelliKeySafe
 *
 * Created: 06.09.2016 08:55:10
 * Author : Florian Schütte
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <stdio.h>
#include "uart.h"
#include "servo.h"
#include "touch.h"
#include <util/delay.h>

extern char uart_string[UART_MAXSTRLEN + 1];

void sleep_now() {
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sleep_enable();
	sleep_mode();
	sleep_disable();
}


void init(void)
{
	servo_init();
	uart_init();
	touch_init();
	sei();
	DDRC = 0x1F;						// PORTD 0..4=output, 5..7=input 
	sbi(PORTC,PC7);						// pullup PC7
}

int main( void )
{
	init();
	//unsigned char servo[1]={0};
	int values[5] = {0,0,0,0,0};
	int ref[5] = {0,0,0,0,0};
	for(int i=0; i<5; i++)				// read reference values
		ref[i] = touch_read(i,100);
	while( 1 ) {
		PORTC &= 0xE0;
		for(int i = 0;i <5;i++){
			values[i] = touch_read(i,500) - ref[i];
			printf("%d, ",values[i]);
			if(values[i]>10)
				sbi(PORTC,i);
		}
		uart_puts("\r\n");
		//sleep_now();
		if ( !(PINC & (1<<PINC7)) )
			PORTC |= 0x1F;
		_delay_ms(1000);		
		//for(uint8_t n=0;n<sizeof(servo);n++) servo_set(n,servo[n]);
		//servo[0] += 10;
	}
}




