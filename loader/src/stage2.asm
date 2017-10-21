[BITS 16]
[ORG 0x7E00]

start:
	; Unlock A20 line 
	call a20_check
	jnz a20_unlocked

	call a20_unlock_by_interrupt
	call a20_check
	jnz a20_unlocked
	

	; If couldn't unlock A20, display error
	mov si, a20_error_msg
	call rmode_print_string

	cli
	hlt

a20_unlocked:
	cli
	
	; Load GDT
	lgdt [gdt_info]
	
	mov eax, cr0
	or eax, 1
	mov cr0, eax

	; Jump to protected mode with reload CS segment
	jmp dword 0x8:start32
	hlt

%include "rmode_screen.asm"
%include "a20.asm"
%include "gdt.asm"

a20_error_msg db "A20 unlocking error!", 0


;;; PROTECTED MODE ;;;
[BITS 32]

start32:
	; Set up segment registers
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov ss, ax
	mov fs, ax
	mov gs, ax
	
	; Set up stack
	mov esp, 0x6C00

	mov esi, kernel_start 
	call load_kernel_elf

	; Run kernel :)
	call eax

	cli 
	hlt

%include "elf.asm"

; Align to full 512B
times 512 - (($ - $$) % 512) db 0

; Kernel is combined with loader immediately, so kernel starts after stage 2
kernel_start: 
