#include <avr/io.h>
#define F_CPU 16000000UL //set clock speed
#include <util/delay.h>

int main(void){
	DDRB |= (1<<PB2); //port b as output
	while(1){
		PORTB |= (1<<PB2); //enable led
		_delay_ms(290);
		PORTB &= ~(1<<PB2); //disable led
		_delay_ms(435);
	}
	return 1;
}
