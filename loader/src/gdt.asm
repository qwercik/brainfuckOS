gdt_info:
	dw gdt_end - gdt_start - 1
	dd gdt_start

gdt_start:
	dq 0 ; Null descriptor

	; Code descriptor
	dw 0xFFFF ; Limit (0-15 bits)
	dw 0x0000 ; Base (0-15 bits)
	db 0x00 ; Base (16-23 bits)
	db 10011010b ; Access byte -> http://wiki.osdev.org/images/1/1b/Gdt_bits.png
	db 11001111b ; Flag and Limit (16-19 bits) byte -> http://wiki.osdev.org/images/1/1b/Gdt_bits.png
	db 0x00 ; Base (24-31 bits)

	; Data descriptor
	dw 0xFFFF ; Limit (0-15 bits)
	dw 0x0000 ; Base (0-15 bits)
	db 0x00 ; Base (16-23 bits)
	db 10010010b; Access byte -> http://wiki.osdev.org/images/1/1b/Gdt_bits.png
	db 11001111b; Flag and Limit (16-19 bits) byte -> http://wiki.osdev.org/images/1/1b/Gdt_bits.png
	db 0x00 ; Base (24-31 bits)
gdt_end:

