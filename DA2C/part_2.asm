.ORG 0x00
	JMP MAIN
.ORG 0x20
	JMP ISR_loop

MAIN:
	LDI R20, HIGH(RAMEND)
	OUT SPH, R20			;high address
	LDI R20, LOW(RAMEND)
	OUT SPL, R20			;low address
	LDI R17, 0
	SBI DDRB, 5				;port b is output
	LDI R20, 13
	STS TCCR0B, R20			;prescaler --> 1024
	LDI R20, 71
	STS OCR0A, R20			;top value
	LDI R20, (1 << TOIE0)
	OUT TIFR0, R20
	SEI						;interrupt

begin:
	RJMP begin

ISR_loop:
	LDI R20, (1 << TOIE0)	;flag bit
	OUT TIFR0, R20			;clear the flag
	LDI R16, 32

	EOR R17, R16
	OUT PORTB, R17			;port be is output
	LDI R18, 0xF3			;loop

loop_1:
	SUBI R18, 1
	CPI R18, 0				;R18 = 0
	BRNE loop_1		

	LDI R20, 0x00
	STS TCNT0, R20
	RETI
