;
; DA1.asm
; PART A
; Created: 2/16/2019 12:32:58 PM
; Author : Armon Latifi
;

.org 0x0000

start:
    LDI R25, 0x11 ;in the high part of the 16-bit multiplicand, store 17
	LDI R24, 0x00 ;in the low part of the 16-bit multiplicand, store 0
	LDI R22, 0x10 ;8-bit multiplier is loaded with value 16

	;at this point, 16-bit multiplicand value --> 4352
	;likewise, 8-bit multiplier value --> 16
	;theoretically, result should be 4352 x 16 = 69632
	
	LDI R26, 0	  ;initialize R26 to zero as the carry
	MOV R17, R22  ;iteration is stored
	INC R17		  ;increment then compare to breq
	LDI R18, 0	  ;initialize R18
	LDI R19, 0	  ;initialize R19
	LDI R20, 0	  ;initialize R20
	CPI R22, 0	  ;compare R22 to zero, because if it is zero, then the answer would be zero, 
				  ;which is already loaded into R20:R19:R18
	BREQ done	  ;if R22 equals zero, operation is finished

multiply:
	DEC R17		  ;decrement the iteration
	BREQ DONE	  ;if equal to zero, jump to done
	ADD R18, R24  ;add the low part of the 16-bit multiplicand with R18
	ADC R19, R25  ;add the high part of the 16-bit multiplicand with R19, carry if needed
	ADC R20, R26  ;add the second potential carry bit to R20
	JMP multiply  ;loop back to multiply

done: