typedef unsigned short uint16_t;

void _start()
{
	uint16_t* vmem = (uint16_t*)0xB8000;
	*vmem = 0x4141;
	*(vmem + 1) = 0x4242;

	for (;;);
}
