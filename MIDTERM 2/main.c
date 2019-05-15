#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "i2c_MASTER.h"
#include "UART.h"
#include "APDS.h"

char results[256];
FILE str_uart = FDEV_SETUP_STREAM(uart_putchar, NULL , _FDEV_SETUP_WRITE);

int main(void)
{
	//need to set up our variables
	uint16_t red = 0, green = 0, blue = 0;
	//call i2c init
	i2c_init();
	//call uart init
	init_UART();
	stdout = &str_uart;
	//initialize apds function
	apds_init();
	//hit with 2000ms delay
 	_delay_ms(2000);
	printf("AT\r\n");
	//hit with 5000ms delay
	_delay_ms(5000);
	printf("AT+CWMODE=1\r\n");
	//hit with 5000ms delay
	_delay_ms(5000);
	printf("AT+CWJAP=\"XXXXX\",\"XXXXX\"\r\n");

    while (1)
    {
		//hit with 5000ms delay
		_delay_ms(5000);
		printf("AT+CIPMUX=0\r\n");
		//hit with 5000ms delay
		_delay_ms(5000);
		printf("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");
		//hit with 5000ms delay
		_delay_ms(5000);
		readColor(&red, &green, &blue);
		printf("AT+CIPSEND=104\r\n");
		printf("GET https://api.thingspeak.com/update?api_key=1V8WUUJNEHZGA9L7&field1=%05u&field2=%05u&field3=%05u\r\n", red, green, blue); //send to thinkspeak
		//hit with 5000ms delay
		_delay_ms(3000);
    }
}
