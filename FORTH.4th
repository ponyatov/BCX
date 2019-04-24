\ reference FORTH for bcx interpreter

ZERO:
		call INIT
		nop
STOP:
		bye
		ret
		lit 0x1234
		lit 0xDead lit 0xBeaf
		lit 0b1101 \ dec:13
INIT:
		nop
		jmp STOP

\ .vm

.save FORTH.bc

