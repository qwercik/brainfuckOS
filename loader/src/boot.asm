[BITS 16]
[ORG 0x7C00]

jmp word 0x0000:start
start:
	cli
	hlt
	jmp $

times 510 - ($ - $$) db 0
dw 0xAA55

