/*
 * config.h
 *
 * Created: 08.09.2016 09:10:08
 *  Author: florian
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

#ifndef F_CPU
#define F_CPU			8000000UL
#endif

//UART
#define BAUD			9600UL
#define UART_MAXSTRLEN	10

//TOUCH
#define TOUCH_DDR		DDRA
#define TOUCH_PORT		PORTA

//LEDS
#define LED_DDR			DDRC
#define LED_PORT		PORTC

//SENSE
#define SENSE_1			PD2
#define SENSE_DDR		DDRD
#define SENSE_PORT		PORTD
#define SENSE_PIN		PIND

//SERVO
#define NUM_SERVOS		1
#define MAXPULSFREQ		500 // 2ms => 500HZ
#if NUM_SERVOS > 0
	#define LOW_SERVO0	(PORTC &= ~(1<<PC6))
	#define HIGH_SERVO0	(PORTC |= (1<<PC6))
#endif
#if NUM_SERVOS > 1
	#define LOW_SERVO1
	#define HIGH_SERVO1
#endif
#if NUM_SERVOS > 2
	#define LOW_SERVO2
	#define HIGH_SERVO2
#endif
#if NUM_SERVOS > 3
	#define LOW_SERVO3
	#define HIGH_SERVO3
#endif
#if NUM_SERVOS > 4
	#define LOW_SERVO4
	#define HIGH_SERVO4
#endif
#if NUM_SERVOS > 5
	#define LOW_SERVO5
	#define HIGH_SERVO5
#endif
#if NUM_SERVOS > 6
	#define LOW_SERVO6
	#define HIGH_SERVO6
#endif
#if NUM_SERVOS > 7
	#define LOW_SERVO7
	#define HIGH_SERVO7
#endif
#if NUM_SERVOS > 8
	#define LOW_SERVO8
	#define HIGH_SERVO8
#endif
#if NUM_SERVOS > 9
	#define LOW_SERVO9
	#define HIGH_SERVO9
#endif

//UTIL MACROS
#define sbi(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define cbi(ADDRESS,BIT) (ADDRESS) &= ~(1 << (BIT))

#endif /* CONFIG_H_ */