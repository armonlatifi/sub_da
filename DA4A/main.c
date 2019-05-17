#define F_CPU 8000000UL //set clock speed
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//create flag variable
int check = 0;

int main(void)
{

	DDRD = 0xFF;		//port d set as output
	DDRB = 0xFF;		//port b set as output
	EIMSK = 0x01;
	EIFR = 0x01;
	EICRA = 0x03;
	TCCR1B = 0b00000001;	//no prescaler needed
	TCCR1A = 0x83;


	sei();				//enable interrupts

	ADMUX = 0x60;
	ADCSRA = 0xE6;


	while (1){

		while(!(ADCSRA & (1<<ADIF)));	//poll results
		ADCSRA |=0b00010000;
		OCR1A = ADCH;
	}
	return 0;
}
ISR(INT0_vect) //external interrupt
{
	if(check == 0)
	{
		PORTB |= 1 << PORTB1;
		_delay_ms(1000);
	}
	else
	{
		PORTB &= ~(1<<PORTB1);
		_delay_ms(1000);
	}
	check ^= 1;

}
