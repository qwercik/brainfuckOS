#include <Screen/TerminalOutput.hpp>
#include <Screen/VgaTextMode.hpp>
#include <cppsupport.hpp>

extern "C"
void kmain()
{
	bfos::screen::VgaTextMode vgaTextMode;
	bfos::screen::TerminalOutput* screen = &vgaTextMode;
	screen->clearScreen();
	screen->printString("Welcome to brainfuckOS!");
}
