#include <stdint.h>
#include <cppsupport.hpp>
#include <string.hpp>
#include <panic.hpp>
#include <interrupts/idt.hpp>
#include <terminal/Output.hpp>

void sleep(int n) {
	for (int i = 0; i < n; ++i) {

	}
}

extern "C"
void kmain() {
	bfos::interrupts::idt::init();

	bfos::terminal::Output terminal;
	terminal.info("Succesfully booted\n");
	terminal.info("Kernel loaded at %x\n", kmain);
}