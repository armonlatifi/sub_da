#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(TIMER0_COMPA_vect)
{
	PORTB = 0xFF;	//set port b to max
	_delay_ms(250);
	PORTB = 0x00;	//clear port b to zero
}


int main(void)
{
	DDRB = 0xFF;	//port b is set to output
	EICRA = 0x03;	//rising edge
	EIMSK = (1 << INT0);
	EIFR = (1 << INTF0);	//clear flag
	sei();			//set interrupts

	while (1)
	{
	}
  
}
