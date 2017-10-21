%ifndef MEMORY_ASM
%define MEMORY_ASM

memset:	
	; EDI - destination
	; ECX - bytes counter
	; AX - value
	cld
	rep stosb
	ret

zeromem:
	; EDI - destination
	; ECX - bytes
	xor eax, eax
	call memset
	ret

memcpy:
	; EDI - destination
	; ESI - source
	; ECX - bytes
	cld
	rep movsb
	ret

%endif
