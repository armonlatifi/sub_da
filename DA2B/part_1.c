#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>


int main(void)
{
	DDRB = 1<<2;
	PORTD = 1<<2;
	DDRC = 0x00;
	EICRA = 0x02;

	EIMSK =(1<<INT0);
	sei();

    while (1)
    {
		PORTB = (1<<2);
		_delay_ms(12500);
    }
}

ISR(INT0_vect)
{
	PORTB ^= (1<<2);
	_delay_ms(12500);
}
