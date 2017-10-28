#include <Screen.hpp>

extern "C"
void kmain()
{
	bfos::Screen screen;
	screen.printString("Welcome to brainfuckOS!", 0x02);
}
