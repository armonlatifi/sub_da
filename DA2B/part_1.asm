
start:
.include <m328pdef.inc>
.ORG 0 ;reset
	JMP main
.ORG 0x02
	JMP ex0_isr

main:
	LDI R20,HIGH(RAMEND)
	OUT SPH,R20
	LDI R20,LOW(RAMEND)
	OUT SPL,R20 ;initialize stack
	LDI R20,0x2 ;make INT0 falling edge triggered
	STS EICRA,R20
	SBI DDRB,2 ;set port b as output
	SBI PORTD,2 ;pull-up activated
	LDI R20,1<<INT0
	OUT EIMSK,R20
	SEI ;enable interrupts

ex0_isr:
	IN R21,PORTB
	LDI R22,(1<<2)
	EOR R21,R22
	OUT PORTB,R21
	RETI
