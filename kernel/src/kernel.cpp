#include <cppsupport.hpp>
#include <terminal/Output.hpp>

extern "C"
void kmain() {
	bfos::terminal::Output terminal;
	terminal.setAttribute(0x03);
	terminal.printString("Hello, world!\n");
}
