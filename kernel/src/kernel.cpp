#include <stdint.h>
#include <cppsupport.hpp>
#include <string.hpp>
#include <terminal/RawOutput.hpp>

void sleep(int n) {
	for (int i = 0; i < n; ++i) {

	}
}

extern "C"
void kmain() {
	bfos::terminal::RawOutput terminal;
	terminal.setAttribute(0xF);
	terminal.printString("Welcome to brainfuckOS\n");
	terminal.printString("Moja ulubiona liczba to ");

	char buffer[100];
	terminal.printString(bfos::string::fromInt(-112997, buffer));
}
