/*
 * servo.h
 *
 * Created: 07.09.2016 20:11:13
 *  Author: post
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#define TIMER_MAXPULS F_CPU/MAXPULSFREQ // Timer1 value for a 2ms Puls

#define MINPULS TIMER_MAXPULS/4  // min pulslength = 0.5ms
#define MAXPULS TIMER_MAXPULS // max pulslength=2ms

void servo_set(unsigned char index, unsigned char value);
void servo_init(void);

#endif /* SERVO_H_ */