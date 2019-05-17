#define F_CPU 16000000UL //set clock speed
#define BAUD_RATE 9600 //set baud rate

#include <util/delay.h>
#include <avr/io.h>

void usart_init ();
void usart_send (unsigned char ch);
int main (void)
{
	usart_init ();

	ADMUX= 0xC8;
	ADCSRA= 0x87;			//enable ADC

	while (1)
	{
		ADCSRA|=(1<<ADSC);	//begin converting
		while((ADCSRA&(1<<ADIF))==0);
		ADCSRA |= (1<<ADIF);

		int a = ADCL;
		a = a | (ADCH<<8);
		a -= 266;
			if(a < 0)
			{
				usart_send('-');
				a *= -1;
			}
		usart_send((a/100)+'0');
		a = a % 100;
		usart_send((a/10)+'0');
		a = a % 10;
		usart_send((a)+'0');
		usart_send('\r');

		_delay_ms(100);
	}
	return 0;
}


void usart_init (void)
{
	UCSR0B = (1<<TXEN0);
	UCSR0C = (1<< UCSZ01)|(1<<UCSZ00);
	UBRR0L = F_CPU/16/BAUD_RATE-1;
}

void usart_send (unsigned char ch)
{
	while (! (UCSR0A & (1<<UDRE0))); 	
	UDR0 = ch;

void usart_print(char* str)
{
	int i = 0;
	while(str[i] != 0)
	usart_send(str[i]);
}
