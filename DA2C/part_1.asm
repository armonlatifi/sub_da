.org 0
	LDI R16, 32
	SBI DDRB, 5			;set port b to output
	LDI R17, 0
	OUT PORTB, R17 ;initialize
	LDI R20, 5
	STS TCCR0B, R20		;prescaler --> 1024
	LDI R20, 0xF3
	STS OCR0A, R20

loop_1:
	RCALL d_loop			;delay loop
	EOR R17, R16
	OUT PORTB, R17		;set port b to output
	RJMP loop_1

d_loop:
	LDS R19, TCNT0
	CPI R19, 0xF3		;equality check
	BRSH done
	RJMP d_loop			;jump back

done:
	LDI R20, 0x00
	STS TCNT0, R20		;reset counter to 0
	RET
