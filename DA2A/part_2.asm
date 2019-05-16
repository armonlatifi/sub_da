start:
	SBI DDRB, 0x4
	CBI DDRC, 0x2
	LDI r16, 0x00
	OUT PORTB, r16

loop_1:
	IN r18, PINC
	CP r16, r18
	BRNE enable
	rjmp loop_1

enable:
	LDI r18, 0xff
	OUT PORTB, r18
	RCALL delay
	rjmp start

delay:
	LDS R29, TCNT1H ;upper bit
	LDS R28, TCNT1L ;lower bit
	CPI R28,0x8B ;compare
	BRSH body
	RJMP delay

body:
	CPI R29,0x1A
	BRSH done
	RJMP delay
