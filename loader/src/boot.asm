[BITS 16]
[ORG 0x7C00]

; Reload CS
jmp word 0x0000:start

start:
	; Set up segment registers
	xor ax, ax
	mov ds, ax
	
	; We want to read next sectors into 0x07E0:0x0000 (ES:BX)
	mov ax, 0x07E0
	mov es, ax 

	; Set up stack (0x500 - 0x1500)
	; Stack size: 4 KiB
	mov ax, 0x0150
	mov ss, ax
	mov sp, 0x1000
	

	call rmode_clear_screen


	; Reading next sectors into memory
	mov ah, 2
	
	; The flag below will be replaced with mov al, <sectors_to_read> and two nop instructions
	dd 0x00C0FFEE
	
	xor ch, ch
	mov cl, 2
	xor dh, dh
	xor bx, bx
	int 0x13	
	jc disk_error
	

	; Jump to stage 2
	jmp 0x0000:0x7E00 


disk_error:
	mov si, disk_error_msg
	call rmode_print_string
	cli
	hlt

disk_error_msg db "Disk reading error!", 0


%include "rmode_screen.asm"


%if ($ - $$) > 510
	%error "Too much code in bootsector! You have to fit in in 512 bytes excluding boot signature."
%endif

; Fill the rest of bootsector with zeros and add boot signature 0xAA55
times 510 - ($ - $$) db 0
dw 0xAA55

