#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "UART.h"

void init_UART(void){
	uint16_t baud_rate = BRGVAL; //baud rate needs to be set
	UBRR0H = baud_rate >> 8;
	UBRR0L = baud_rate & 0xFF;


	//enable transmitter
	//enable receiver
	UCSR0B = ( 1 <<RXEN0)|( 1 <<TXEN0);
	UCSR0C = (3 <<UCSZ00);
}

int uart_putchar(char c, FILE *stream){
	while ( !( UCSR0A & ( 1 <<UDRE0)) ); //is buffer empty?
	UDR0 = c;
	return 0;
}
