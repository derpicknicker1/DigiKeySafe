/*
 * magSense.c
 *
 * Created: 08.09.2016 11:09:03
 *  Author: florian
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "config.h"
#include "sense.h"
#include "leds.h"

void sense_init(void)
{
	SENSE_DDR &= ~(1 << SENSE_1);
	SENSE_PORT |= (1 << SENSE_1);
	MCUCR |= (1 << ISC00);
	GICR |= (1 << INT0);
}

ISR(INT0_vect){
	leds_toggle(5);
}