[BITS 16]
[ORG 0x7E00]

start:
	mov si, hello_msg
	call print_string
	cli
	hlt

%include "rmode/screen.asm"

hello_msg db "No siema :D", 0

times 512 - (($ - $$) % 512) db 0
