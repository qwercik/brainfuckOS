%ifndef SCREEN_ASM
%define SCREEN_ASM
; Screen library for x86 real mode

rm_clear_screen:
	mov ax, 3
	int 0x10
	ret

rm_print_string:
	; DS:SI = string to print (terminated with \0)
	mov ah, 0xE
	xor bx, bx

	lodsb
	or al, al
	jz .end
	int 0x10
	jmp rm_print_string
	.end:
		ret

%endif
