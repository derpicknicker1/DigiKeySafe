/*
 * softart.h
 *
 * Created: 07.09.2016 19:36:17
 *  Author: post
 */ 


#ifndef SOFTART_H_
#define SOFTART_H_

#define 	uartsw_rx_buffer_size   0x20
//uart receive buffer size in bytes.
#define 	uartsw_invert
//define to invert polarity of rx/tx signals
#define 	uartsw_tx_port   portd
//uart transmit port.
#define 	uartsw_tx_ddr   ddrd
//UART Transmit DDR.
#define 	UARTSW_TX_PIN   PD5
//UART Transmit Pin.
#define 	UARTSW_RX_PORT   PORTD
//UART Receive Port.
#define 	UARTSW_RX_DDR   DDRD
//UART Receive DDR.
#define 	UARTSW_RX_PORTIN   PIND
//UART Receive Port Input.
#define 	UARTSW_RX_PIN   PD6
//UART Receive Pin.




#endif /* SOFTART_H_ */