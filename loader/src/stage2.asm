[BITS 16]
[ORG 0x7E00]

start:
	; Unlock A20
	call a20_check
	jnz a20_unlocked

	call a20_unlock_by_interrupt
	call a20_check
	jnz a20_unlocked

	mov si, a20_error_msg
	call rm_print_string

	cli
	hlt

a20_unlocked:
	cli
	hlt

%include "rmode/screen.asm"
%include "rmode/a20.asm"

a20_error_msg db "A20 unlocking error!", 0

times 512 - (($ - $$) % 512) db 0
