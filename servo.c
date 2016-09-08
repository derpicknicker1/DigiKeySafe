#include <avr/io.h>
#include <avr/interrupt.h>
#include "servo.h"

uint16_t Pulslength[20]; // array for all delays

SIGNAL(TIMER1_OVF_vect)
{
	static unsigned char servoindex_half=0;
	switch (servoindex_half)
	{
		case 0: HIGH_SERVO0; break;
		case 1: LOW_SERVO0; break;
//		case 2: HIGH_SERVO1; break;
//		case 3: LOW_SERVO1; break;
//		case 4: HIGH_SERVO2; break;
//		case 5: LOW_SERVO2; break;
//		case 6: HIGH_SERVO3; break;
//		case 7: LOW_SERVO3; break;
//		case 8: HIGH_SERVO4; break;
//		case 9: LOW_SERVO4; break;
//		case 10: HIGH_SERVO5; break;
//		case 11: LOW_SERVO5; break;
//		case 12: HIGH_SERVO6; break;
//		case 13: LOW_SERVO6; break;
//		case 14: HIGH_SERVO7; break;
//		case 15: LOW_SERVO7; break;
//		case 16: HIGH_SERVO8; break;
//		case 17: LOW_SERVO8; break;
//		case 18: HIGH_SERVO9; break;
//		case 19: LOW_SERVO9; break;
	}

	
	TCNT1 =Pulslength[servoindex_half++]; // set time for next interrupt	
	if(servoindex_half==20)servoindex_half=0;	// reset index
}

void servo_set(unsigned char index, unsigned char value)
{
	uint16_t wert;
	wert=MINPULS+(MAXPULS-MINPULS)/256*value;
	Pulslength[index<<1]=0-wert; 
	Pulslength[(index<<1)+1]=0-(TIMER_MAXPULS-wert);	
}

void servo_init(void)
{
	TCNT1 = 0-16000;
	TCCR1A=0;
	TCCR1B=0x01;
	TIMSK |= (1 << TOIE2) | (1 << TOIE1);
	for(uint8_t n=0;n<10;n++) servo_set(n,128);
}