/*
 * touch.h
 *
 * Created: 07.09.2016 21:23:42
 *  Author: post
 */ 


#ifndef TOUCH_H_
#define TOUCH_H_

#define sbi(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define cbi(ADDRESS,BIT) (ADDRESS) &= ~(1 << (BIT))

void touch_init(void);
int touch_read( uint8_t ADCChannel, uint16_t samples);

#endif /* TOUCH_H_ */