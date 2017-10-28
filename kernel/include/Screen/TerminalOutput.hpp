#pragma once

namespace bfos::screen
{
	class TerminalOutput
	{
	public:
		virtual void printChar(char character) = 0;
		virtual void printString(const char* string) = 0;
		virtual void clearScreen() = 0;
	};
}
