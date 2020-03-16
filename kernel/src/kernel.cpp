#include <stdint.h>
#include <cppsupport.hpp>
#include <terminal/RawOutput.hpp>

void sleep(int n) {
	for (int i = 0; i < n; ++i) {

	}
}

void reverseString(char *string, unsigned length) {
	for (unsigned index = 0; index <= length / 2; ++index) {
		int temp = string[index];
		string[index] = string[length - 1 - index];
		string[length - 1 - index] = temp;
	}
}

char* intToString(long int value, char *buffer) {
	bool negative = value > 0 ? false : true;
	value = value > 0 ? value : -value;

	unsigned index = 0;
	while (value > 0) {
		buffer[index++] = '0' + value % 10;
		value /= 10;
	}

	if (negative) {
		buffer[index++] = '-';
	}

	buffer[index] = '\0';

	reverseString(buffer, index);
	return buffer;
}

extern "C"
void kmain() {
	bfos::terminal::RawOutput terminal;
	terminal.setAttribute(0xF);
	terminal.printString("Welcome to brainfuckOS\n");
	terminal.printString("Moja ulubiona liczba to ");

	char buffer[100];
	intToString(-112997, buffer);
	terminal.printString(buffer);
}
