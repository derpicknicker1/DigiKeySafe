/*
 * touch.c
 *
 * Created: 07.09.2016 21:23:33
 *  Author: post
 */ 
 #include <avr/io.h>
 #include "config.h"
 #include "touch.h"

 static int touch_refs[TOUCH_CH_NUM];

 void touch_init(void){
 	ADCSRA = (1<<ADPS2) | (1<<ADPS0);	// Set prescaler (125kHz)
 	sbi(ADCSRA, ADEN);					// enable ADC
	for(int i=0; i<TOUCH_CH_NUM; i++)				// read reference values
		touch_refs[i] = touch_read(i,100);
 }

 int touch_ref(uint8_t channel)
 {
	return touch_refs[channel];
 }

 int touch_read( uint8_t ADCChannel, uint16_t samples)
 {
	 long value = 0;
	 for(uint16_t i=0; i<samples; i++)
	 {
		 cbi(TOUCH_DDR,ADCChannel);			// Input+Pullup
		 sbi(TOUCH_PORT,ADCChannel);
		 ADMUX |=   0b11111;			// Single-ended GND
		 sbi(ADCSRA,ADSC);				// Dummy Conversion
		 while(!(ADCSRA & (1<<ADIF)));
		 sbi(ADCSRA,ADIF);
		 cbi(TOUCH_PORT,ADCChannel);			// Disable Pullup
		 ADMUX = (ADMUX & ~(0x1F)) | (ADCChannel & 0x1F); // Read Channel Value
		 sbi(ADCSRA,ADSC);
		 while (ADCSRA & (1<<ADSC) );
		 value += ADCW;
	 }
	 return value / samples;
 }

 /*##########################
  # USE DIGI PIN FOR TOUCH #
  ##########################*/
/* uint8_t touch_measure_RC(uint8_t ADCChannel) {
	uint8_t cnt = 0;
	PORTC &= ~(1 << ADCChannel);
	DDRC |= (1 << ADCChannel);
	DDRC &= ~(1 << ADCChannel);
	while (!( PINC & (1<<ADCChannel))) 
	{
		PORTC |= (1 << ADCChannel);  // pulse as short as possible
		PORTC &= ~(1 << ADCChannel);
		++cnt;
	}
	return cnt;
}*/