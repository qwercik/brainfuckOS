%ifndef SCREEN_ASM
%define SCREEN_ASM

clear_screen:
	mov ax, 3
	int 0x10
	ret

print_char:
	; AL = character to print
	mov ah, 0xE
	xor bx, bx
	int 0x10
	ret

print_string:
	;

%endif
