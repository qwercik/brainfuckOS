#include <stdint.h>
#include <cppsupport.hpp>
#include <string.hpp>
#include <terminal/Output.hpp>

void sleep(int n) {
	for (int i = 0; i < n; ++i) {

	}
}


extern "C"
void kmain() {
	const char* name = "Eryk Andrzejewski";

	bfos::terminal::Output terminal;
	terminal.print("Welcome to brainfuckOS %d, %d, %d\n", 997, 112, 1410);
	terminal.info("Info\n");
	terminal.warning("Warning\n");
	terminal.error("Error: kmain() addr: %x\n", kmain);
}
