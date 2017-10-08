%ifndef A20_ASM
%define A20_ASM

a20_check:
	; If A20 is locked -> 0xFFFF:0x7E0E is the same as 0x0000:0x7CDFE
	; If A20 is locked, ZF is set
	push es

	mov bx, 0xFFFF
	mov es, bx
	mov bx, 0x7E0E

	cmp word [es:bx], 0xAA55

	pop es
	ret

a20_unlock_by_interrupt:
	mov ax, 0x2401
	int 0x15
	ret

%endif
