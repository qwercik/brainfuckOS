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
	terminal.setAttribute(0xF);
	terminal.print("Welcome to brainfuckOS\n");
	terminal.print("My favourite number is %d%% My name is %s", 997, name);
}
