;
; DA1.asm
; PART B
; Created: 2/21/2019 11:30:01 AM
; Author : Armon Latifi
;

.org 0x0000
LDI R0, O           ;clear R0 by loading in zero
LDI XL, 0x00        ;the lower 8 bits of begin address, 0x0200
                    ;are loaded into XL (x-low)
LDI XH,	0x02        ;the upper 8 bits of begin address, 0x0200
                    ;are loaded into XH (x-high)
LDI YL, 0x00        ;the lower 8 bits of the next begin address, 0x0400
                    ;are loaded into YL (y-low)
LDI YH, 0x04        ;the upper 8 bits of the next begin address, 0x0400
                    ;are loaded into YH (y-high)
LDI ZL, 0x00        ;the lower 8 bits of the next begin address, 0x0600
                    ;are loaded into ZL (z-low)
LDI ZH, 0x06        ;the upper 8 bits of the next begin address, 0x0600
                    ;are loaded into ZH (z-high)

LDI R22, 3          ;set R22 as constant 3, for divisibility check
LDI R24, 0          ;set R24 as addc, initialize
LDI R21, 10         ;set R21 as 10, to ensure numerically greater than 10
LDI R20, 99         ;set R20 as constant 99, for the number of numbers

begin:

	INC R21           ;increment R21 while values are being assigned to X
	ST X+, R21        ;store value into X
	MOV R23, R21
	JMP divthree

cont:

	DEC R20           ;99 values, decrement as each is processed
	BRNE begin        ;if 99 values have not been processed, loop back
	JMP end           ;if 99 values have been processed, end program

divthree:

	SUBI R23, 3       ;begin divisibility check by subtracting three
	BRLT divfalse     ;if less then 0 then go to not divisible

	CPI R23, 0        ;check and see if value in R23 is equal to zero
	BRNE divthree     ;if greater than 3, and nonzero, loop back up for more
                    ;subtraction

	JMP divtrue       ;if equal to zero, value must be divisible by 3

divtrue:

	ST Y+, R21        ;store divisible value into y
	ADD R16, R21      ;add the index of the value

	ADC R17, R24      ;add along with the carry
	JMP cont

divfalse:

	ST Z+, R21        ;store indivisible value into z
	ADD R18, R21      ;add index of the value
	ADC R19, R24      ;add along with the carry
	JMP cont

end:
