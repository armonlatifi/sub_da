#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRB = 32;		//port b is output
	TCCR0B = 13;	//prescaler --> 1024
	TCNT0 = 0;
	OCR0A = 0x00F3;	//top value

	while (1)
	{
		if((TIFR0 & 0b00000001) == 0b00000001) //overflow condition
		{
			PORTB = 0xFF;		//port b is high
			_delay_ms(250);
			TCNT0 = 0;
		}
		else
		PORTB = 0x00;	
	}
}
