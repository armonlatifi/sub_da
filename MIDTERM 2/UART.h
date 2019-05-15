#ifndef UART_328P_H
#define UART_328P_H

#ifndef F_CPU
#define F_CPU 16000000UL
#endif



#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>



#define BRGVAL (F_CPU/16/BAUD) - 1
#define BAUD 9600



void init_UART();
int uart_putchar( char c, FILE *stream);
#endif
