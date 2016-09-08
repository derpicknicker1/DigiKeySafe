/*
 * uart.h
 *
 * Created: 06.09.2016 21:13:49
 *  Author: post
 */ 


#ifndef UART_H_
#define UART_H_

#define UBRR_VAL ((F_CPU+BAUD*8)/(BAUD*16)-1)   
#define BAUD_REAL (F_CPU/(16*(UBRR_VAL+1)))  
#define BAUD_ERROR ((BAUD_REAL*1000)/BAUD)

#if ((BAUD_ERROR<990) || (BAUD_ERROR>1010))
#error Systematischer Fehler der Baudrate groesser 1% und damit zu hoch!
#endif

void uart_init(void);
int uart_putc(unsigned char c, FILE *stream);
void uart_puts (char *s);
void uart_puti(signed int val);
void uart_res_string(void);
uint8_t uart_complete(void);
uint8_t uart_count(void);

#endif /* UART_H_ */