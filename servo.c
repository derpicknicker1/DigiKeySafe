#include <avr/io.h>
#include <avr/interrupt.h>
#include "config.h"
#include "servo.h"

uint16_t Pulslength[NUM_SERVOS*2]; // array for all delays

SIGNAL(TIMER1_OVF_vect)
{
	static unsigned char servoindex_half=0;
	switch (servoindex_half)
	{
		#if NUM_SERVOS > 0
			case 0: HIGH_SERVO0; break;
			case 1: LOW_SERVO0; break;
		#endif
		#if NUM_SERVOS > 1
			case 2: HIGH_SERVO1; break;
			case 3: LOW_SERVO1; break;
		#endif
		#if NUM_SERVOS > 2
			case 4: HIGH_SERVO2; break;
			case 5: LOW_SERVO2; break;
		#endif
		#if NUM_SERVOS > 3
			case 6: HIGH_SERVO3; break;
			case 7: LOW_SERVO3; break;
		#endif
		#if NUM_SERVOS > 4
			case 8: HIGH_SERVO4; break;
			case 9: LOW_SERVO4; break;
		#endif
		#if NUM_SERVOS > 5
			case 10: HIGH_SERVO5; break;
			case 11: LOW_SERVO5; break;
		#endif
		#if NUM_SERVOS > 6
			case 12: HIGH_SERVO6; break;
			case 13: LOW_SERVO6; break;
		#endif
		#if NUM_SERVOS > 7
			case 14: HIGH_SERVO7; break;
			case 15: LOW_SERVO7; break;
		#endif
		#if NUM_SERVOS > 8
			case 16: HIGH_SERVO8; break;
			case 17: LOW_SERVO8; break;
		#endif
		#if NUM_SERVOS > 9
			case 18: HIGH_SERVO9; break;
			case 19: LOW_SERVO9; break;
		#endif
	}

	
	TCNT1 =Pulslength[servoindex_half++]; // set time for next interrupt	
	if(servoindex_half==(NUM_SERVOS*2)) servoindex_half=0;	// reset index
}

void servo_set(unsigned char index, unsigned char value)
{
	uint16_t val;
	val=MINPULS+(MAXPULS-MINPULS)/256*value;
	Pulslength[index<<1]=0-val; 
	Pulslength[(index<<1)+1]=0-(TIMER_MAXPULS-val);	
}

void servo_init(void)
{
	TCNT1 = 0-16000;
	TCCR1A=0;
	TCCR1B=0x01;
	TIMSK |= (1 << TOIE2) | (1 << TOIE1);
	for(uint8_t n=0;n<NUM_SERVOS;n++) servo_set(n,128);
}