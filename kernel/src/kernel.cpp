#include <cppsupport.hpp>
#include <terminal/RawOutput.hpp>

void sleep(int n) {
	for (int i = 0; i < n; ++i) {

	}
}

extern "C"
void kmain() {
	bfos::terminal::RawOutput terminal;
	terminal.setAttribute(0xF);
	terminal.printString("Welcome to brainfuckOS \b");
}
