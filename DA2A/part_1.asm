start:
.org 0


	LDI R16,4
	SBI DDRB, 0x2
	LDI R17,0
	out PORTB,R17
	LDI R20,5
	STS TCCR1B,R20 ;set prescaler to 1024
	LDI R18, 0


begin:
	RCALL delay
	EOR R17,R16 ;led enable
	out PORTB,R17
	RCALL delay_2
	EOR R17,R16 ;led enable
	out PORTB,R17
	RJMP begin

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

delay_2:
	LDS R29, TCNT1H ;upper bit
	LDS R28, TCNT1L ;lower bit
	CPI R28,0xB2 ;compare
	BRSH body_2
	RJMP delay_2

body_2:
	CPI R29,0x11
	BRSH done
	RJMP delay_2

done:
	LDI R20,0x00
	STS TCNT1H,R20
	LDI R20,0x00
	STS TCNT1L,R20
	RET
