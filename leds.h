/*
 * leds.h
 *
 * Created: 08.09.2016 09:53:48
 *  Author: florian
 */ 


#ifndef LEDS_H_
#define LEDS_H_
 
#define leds_toggle(bit)		{LED_PORT ^= (1 << bit);}
#define leds_is_high(bit)	(LED_PIN & (1 << bit))
#define leds_is_low(bit)     (!(LED_PIN & (1 << bit)))

void leds_init(void);
void leds_set(unsigned char led, unsigned char state);
void leds_all(unsigned char mode);

#endif /* LEDS_H_ */