#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(TIMER0_OVF_vect)	//interrupt
{
	PORTB ^= 0xFF;		//port b is output
	TCNT0 = 65292l;		//reset
}

int main(void)
{
	DDRB = 0xFF;			//port b set to high
	TIMSK0 = (1 << TOIE0);
	TCCR0B = 0x05;			//prescaler --> 1024
	TCNT0 = 65292;
	sei();
	while(1)
	{
	}
}
