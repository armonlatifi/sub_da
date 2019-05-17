#define F_CPU 16000000UL //set clock frequency
#define BAUD 9600 //set baud rate

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

void USART_tx_string( char* data); //prints string
void USART_init( void ); //USART_init function
void USART_send(char val); //send function
char outs[20];  //character array
char str[] = "Hello World!";
volatile float tmp = 27.23;


int main(void)
{
	TCCR1B = 5; //prescaler --> 1024
	TIMSK1 = (1<<TOIE1);
	TCNT1 = 49911;

	USART_init();
	sei();//interrupt enable


	while(1)
	{
	}
}

ISR(TIMER1_OVF_vect)
{
	USART_tx_string(str);
	USART_tx_string("\n"); //takes care of line feed
	USART_send('7');
	USART_tx_string("\n"); //takes care of line feed

	//printing time
	snprintf(outs,sizeof(outs),"%f\r\n", tmp);
	USART_tx_string(outs);
	USART_tx_string("\n"); //takes care of line feed
	TCNT1 = 49911; //reset
}

void USART_init( void )
{
	UBRR0H = 0; //take care of lower bits
	UBRR0L = F_CPU/16/BAUD - 1; //
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
}

//sending data to serial port
void USART_tx_string(char *data)
{
	while((*data != '\0'))
	{
		while(!(UCSR0A & (1<<UDRE0)));
			UDR0 = *data;
				data++;
	}
}

void USART_send(char val)
{
//wait
	while(!(UCSR0A & (1<<UDRE0)));
	 UDR0 = val;
}
