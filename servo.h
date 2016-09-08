/*
 * servo.h
 *
 * Created: 07.09.2016 20:11:13
 *  Author: post
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#define MAXPULSFREQ 500 // 2ms => 500HZ

#define TIMER_MAXPULS F_CPU/MAXPULSFREQ // Timer1 value for a 2ms Puls

#define MINPULS TIMER_MAXPULS/4  // min pulslength = 0.5ms
#define MAXPULS TIMER_MAXPULS // max pulslength=2ms

#define LOW_SERVO0 PORTC&=~(1<<6)
#define HIGH_SERVO0 PORTC|=(1<<6)

#define LOW_SERVO1
#define HIGH_SERVO1

#define LOW_SERVO2
#define HIGH_SERVO2

#define LOW_SERVO3
#define HIGH_SERVO3

#define LOW_SERVO4
#define HIGH_SERVO4

#define LOW_SERVO5
#define HIGH_SERVO5

#define LOW_SERVO6
#define HIGH_SERVO6

#define LOW_SERVO7
#define HIGH_SERVO7

#define LOW_SERVO8
#define HIGH_SERVO8

#define LOW_SERVO9
#define HIGH_SERVO9

void servo_set(unsigned char index, unsigned char value);
void servo_init(void);

#endif /* SERVO_H_ */