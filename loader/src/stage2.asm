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
	; Load GDT
	lgdt [gdt_info]
	
	mov eax, cr0
	or eax, 1
	mov cr0, eax

	jmp dword 0x8:start32

	cli
	hlt

%include "rmode/screen.asm"
%include "a20.asm"
%include "gdt.asm"

a20_error_msg db "A20 unlocking error!", 0


;;; PROTECTED MODE ;;;
[BITS 32]

start32:
	cli
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov ss, ax
	mov fs, ax
	mov gs, ax

	hlt

times 512 - (($ - $$) % 512) db 0
