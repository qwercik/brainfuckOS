#include <cppsupport.hpp>
#include <terminal/RawOutput.hpp>

void sleep(int n) {
	for (int i = 0; i < n; ++i) {

	}
}

extern "C"
void kmain() {
	const uint16_t ATTRIBUTES[] = {0x01, 0x03, 0x07, 0xF};

	bfos::terminal::RawOutput terminal;
	terminal.setAttribute(0x03);

	for (int i = 0; i < 100; ++i) {
		terminal.setAttribute(ATTRIBUTES[i % 4]);
		terminal.printChar('0' + i % 10);
		terminal.printString(" Hello, world!\n");
		sleep(50000000);
	}
}
