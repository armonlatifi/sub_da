.ORG 0x00
	JMP main_loop_1
.ORG 0x06
	JMP ex0_ISR

main_loop_1:
	LDI R20, HIGH(RAMEND)
	OUT SPH, R20			;high addy
	LDI R20, LOW(RAMEND)
	OUT SPL, R20			;low addy
	SBI DDRB, 5				;port b set to output

	LDI R17, 0
	LDI R20, (1 << INT0)
	OUT EIMSK, R20			;flag for interrupt
	SEI

here:
	JMP here

ex0_ISR:
	LDI R20, (1 << INTF0)	;clear
	LDI R16, 32
	EOR R17, R16
	OUT PORTB, R17			;port b is output
	LDI R18, 0xF3

loop_1:
	SUBI R18, 1
	CPI R18, 0x00			;check with zero
	BRNE loop_1
	LDI R20, 0x00
	STS TCNT0, R20
	RETI
