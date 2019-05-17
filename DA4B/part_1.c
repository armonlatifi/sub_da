#define F_CPU 1000000UL //set clock speed
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t value; //volatile variable

ISR(ADC_vect)
{
	value = ADCH;	//read and set pot
}

void delayFunct(void) //enable CTC mode
{
	TCNT1 = 0;
	OCR1A = value;
	TCCR1B |= ( 1<< WGM12) | (1 << CS12) | (1<< CS10);
	TCCR1A |= (1 <<COM1A0);
	while(TIFR1 & ( 1 << OCF1A));

	TIFR1 |= ( 1 << OCF1A);

}

int main(void)
{

	DDRB = 0xFF;
	ADMUX = (0<<REFS1)|
					(1<<REFS0)|
					(0<<ADLAR)|
					(0<<MUX2)|
					(1<<MUX1)|
					(0<<MUX0);
	ADCSRA = (1<<ADEN)| // enable adc
					 (0<<ADSC)|
					 (0<<ADATE)|
					 (0<<ADIF)|
					 (0<<ADIE)|
					 (1<<ADPS2)|
					 (0<<ADPS1)|
					 (1<<ADPS0);

	sei(); //interrupt

	while(1)
	{
		PORTB |= (1<< PORTB0); //stepper
		delayFunct();		//CTC to timer
		PORTB |= (1<< PORTB1);
		delayFunct();
		PORTB |= (1<< PORTB2);
		delayFunct();
		PORTB |= (1<< PORTB3);
		delayFunct();


	}

}
