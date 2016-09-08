/*
 * leds.c
 *
 * Created: 08.09.2016 09:53:59
 *  Author: florian
 */
#include <avr/io.h>
#include "config.h"
#include "leds.h"


void leds_init(void)
{
	LED_DDR = 0xFF;
	LED_PORT = 0x00;
}

void leds_set(unsigned char led, unsigned char state)
{
	if(state)
		sbi(LED_PORT,led);
	else
		cbi(LED_PORT,led);
}

void leds_all(unsigned char mode)
{
	if(mode)
		LED_PORT = 0xFF;
	else
		LED_PORT = 0x00;
}
