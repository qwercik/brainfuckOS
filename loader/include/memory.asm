%ifndef MEMORY_ASM
%define MEMORY_ASM

memset:	
	; EDI - destination
	; ECX - bytes counter
	; AX - value
	push edi
	push ecx
	push eax
	cld
	rep stosb
	pop eax
	pop ecx
	pop edi
	ret

zeromem:
	; EDI - destination
	; ECX - bytes
	push edi
	push ecx
	xor eax, eax
	call memset
	pop ecx
	pop edi
	ret

memcpy:
	; EDI - destination
	; ESI - source
	; ECX - bytes
	push edi
	push esi
	push ecx
	cld
	rep movsb
	pop ecx
	pop esi
	pop edi
	ret

%endif
