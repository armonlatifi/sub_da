#include <avr/io.h>
#define F_CPU 16000000UL //set clock speed
#include <util/delay.h>

int main(void)
{
	DDRB |= (1<<2); //port b is output

	DDRC &= (0<<2);
	PORTC |= (1<<2);
	while(1){
		if(PINC & 0x2){
			_delay_ms(1250); //wait
			PORTB |= (1<<PB2); //turn led off

		}
		else
			PORTB &= ~(1<<PB2); //enable led
	}
	return 0;
}
