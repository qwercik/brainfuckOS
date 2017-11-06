#include <Screen/TerminalOutput.hpp>

namespace bfos::screen
{
	void TerminalOutput::printChar(char character, uint8_t attribute)
	{
		putEntity(currentPositionX, currentPositionY, character, attribute);
		currentPositionX++;
	}

	void TerminalOutput::printString(const char* string, uint8_t attribute)
	{
		for (int characterIndex = 0; string[characterIndex] != '\0'; ++characterIndex)
		{
			printChar(string[characterIndex], attribute);
		}
	}

	void TerminalOutput::clearScreen(uint8_t attribute)
	{
		for (int y = 0; y < getHeight(); ++y)
		{
			for (int x = 0; x < getWidth(); ++x)
			{
				putEntity(x, y, ' ', attribute);
			}
		}
	}
}
