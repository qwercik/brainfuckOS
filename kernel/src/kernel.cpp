#include <Screen/TerminalOutput.hpp>
#include <Screen/VgaTextModeTerminalOutput.hpp>
#include <cppsupport.hpp>

extern "C"
void kmain()
{
	bfos::screen::VgaTextModeTerminalOutput vgaTextModeTerminalOutput;
	bfos::screen::TerminalOutput* screen = &vgaTextModeTerminalOutput;

	screen->clearScreen(0x07);
	screen->printString("Welcome to brainfuckOS!", 0x07);
}
