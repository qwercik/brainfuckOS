typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

static uint16_t* vmem = reinterpret_cast<uint16_t*>(0xB8000);

void putchar(uint8_t character, uint8_t attribute = 0x07)
{
	*vmem++ = (attribute << 8) | character; 
}

int strlen(char* string)
{
	int length = 0;
	while (string[length++]);
	return --length;
}

void puts(char* string)
{
	for (int i = 0; i < strlen(string); ++i)
	{
		putchar(string[i]);
	}
}

void halt()
{
	for (;;);
}


extern "C"
void kmain()
{
	puts("Hello world!");
	halt();
}
