#define F_CPU 1000000UL //set clock speed
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int check = 0;

int main(void)
{
	DDRB = 0xFF; //port d as output
	DDRD = 0xFF;
	TCCR1B=3; //set a prescaler
	TCCR1A=0x83; //enable fast PWM mode
	ADMUX = 0x60;
	ADCSRA = 0xE6;

	while (1)
	{
		ADCSRA |= ( 1 << ADSC); //start conversion
		while((ADCSRA & (1 << ADIF))== 0);
		check = ADCH; //temporary variable

		if(check == 0) //minimum
		{
			OCR1A = 15;
			_delay_ms(1000);
		}
		else if(check == 255) //maximum
		{
			OCR1A = 30;
			_delay_ms(1000);
		}
		else;
	}
}
