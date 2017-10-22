%ifndef ELF_ASM
%define ELF_ASM

load_kernel_elf:
	; Params:
	; ESI - kernel ELF address
	; Return (EAX) - entry point address

	; EDI = Address of current program header entry
	mov edi, dword [esi + 0x1C]
	add edi, esi
	
	; ECX = Program headers counter
	movzx ecx, word [esi + 0x2C]
	
	.program_header_loop:
		; Check if entry type is PT_LOAD (0x00000001)
		; If not, go to next entry
		mov eax, dword [edi]
		cmp eax, 1
		jne .next_entry

		; Backup registers
		push ecx
		push edi
		
		; ECX = size of segment in memory
		mov ecx, dword [edi + 0x14]
		
		; EDI = address of segment in memory
		mov edi, dword [edi + 0x8] 
		
		call zeromem

		
		; Restore old EDI value
		pop edi
		push edi

		
		; ECX = bytes to copy
		mov ecx, dword [edi + 0x10]
		
		; ESI = segment offset in file
		add esi, dword [edi + 0x4]
		
		; EDI = memory address of segment
		mov edi, dword [edi + 0x8]

		
		call memcpy

		; Restore registers
		pop edi
		pop ecx
		
		.next_entry:
			add edi, 32

	loop .program_header_loop

	mov eax, dword [esi + 0x18]
	ret

%include "memory.asm"

%endif
