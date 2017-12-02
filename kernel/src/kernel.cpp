#include <Screen/TerminalOutput.hpp>
#include <Screen/VgaTextModeTerminalOutput.hpp>
#include <cppsupport.hpp>

extern "C"
void kmain()
{
	bfos::screen::VgaTextModeTerminalOutput vgaTextModeTerminalOutput;
	bfos::screen::TerminalOutput<uint8_t>* screen = &vgaTextModeTerminalOutput;

	screen->clearScreen(0x07);
	screen->printString("Welcome to brainfuckOS!", 0x07);
}
