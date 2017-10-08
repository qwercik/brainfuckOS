[BITS 16]
[ORG 0x7C00]

; Reload CS
jmp word 0x0000:start

start:
	; Set up data segment registers
	xor ax, ax
	mov ds, ax
	mov ax, 0x0150 
	mov es, ax ; We want to read next sectors into 0x0150:0x0000

	; Set up stack (0x500 - 0x1500)
	; Stack size: 4 KiB
	mov ax, 0x0150
	mov ss, ax
	mov sp, 0x1000
	
	call clear_screen
	
	; Reading next sectors into memory
	mov ah, 2
	mov al, 1 ; Sectors amount
	xor ch, ch
	mov cl, 2
	xor dh, dh
	xor bx, bx ; Sectors will be loaded into ES:BX -> 0x0150:0x0000
	int 0x13	
	jc disk_error

	cli
	hlt

disk_error:
	mov si, disk_error_msg
	call print_string
	cli
	hlt

%include "rmode/screen.asm"

disk_error_msg db "Disk error!", 0

times 510 - ($ - $$) db 0
dw 0xAA55

