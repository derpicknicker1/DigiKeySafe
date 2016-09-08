#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include "config.h"
#include "uart.h"

static volatile uint8_t uart_str_complete = 0;     // 1 .. String komplett empfangen
static volatile uint8_t uart_str_count = 0;
volatile char uart_string[UART_MAXSTRLEN + 1] = "";
static FILE mystdout = FDEV_SETUP_STREAM( uart_putc, NULL, _FDEV_SETUP_WRITE );

void uart_init(void)
{
	UBRRH = UBRR_VAL >> 8;
	UBRRL = UBRR_VAL &0xFF;
	UCSRB |= (1<<TXEN) | (1<<RXEN) | (1<<RXCIE);
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);  // Asynchron 8N1 
	stdout = &mystdout;
}

int uart_putc(unsigned char c, FILE *stream)
{
	if( c == '\n' )
		uart_putc( '\r', stream );
	while (!(UCSRA & (1<<UDRE)));
	UDR = c;
	return 0;
}

void uart_puts (char *s)
{
	while (*s)  
		uart_putc(*s++,0);
}

void uart_puti(signed int val){
	char buff[10]="";
	itoa(val,buff,10);
	uart_puts(buff);
}

void uart_res_string(void){
	uart_str_count = 0;
	uart_str_complete = 0;
	uart_string[0] = '\0';
}

uint8_t uart_complete(void){
	return uart_str_complete;
}

uint8_t uart_count(void){
	return uart_str_count;
}

ISR(USART_RXC_vect)
{
	unsigned char nextChar;
	nextChar = UDR;
	if( uart_str_complete == 0 ) {
		if( nextChar != '\n' &&	nextChar != '\r' &&	uart_str_count < UART_MAXSTRLEN ) 
			uart_string[uart_str_count++] = nextChar;
		else {
			uart_string[uart_str_count] = '\0';
			uart_str_complete = 1;
		}
	}
}
