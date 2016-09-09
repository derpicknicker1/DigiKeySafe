/*
 * sense.h
 *
 * Created: 08.09.2016 11:09:24
 *  Author: florian
 */ 


#ifndef SENSE_H_
#define SENSE_H_

#define sense_is_high(bit)	(SENSE_PIN & (1 << bit))
#define sense_is_low(bit)	(!(SENSE_PIN & (1 << bit)))

void sense_init(void (*func)());

#endif /* SENSE_H_ */