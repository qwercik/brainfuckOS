#include <Screen/TerminalOutput.hpp>

namespace bfos::screen
{
	void TerminalOutput::printChar(char character)
	{
		putEntity(currentPositionX, currentPositionY, character, attribute);
		currentPositionX++;
	}

	void TerminalOutput::printString(const char* string)
	{
		for (int characterIndex = 0; string[characterIndex] != '\0'; ++characterIndex)
		{
			printChar(string[characterIndex]);
		}
	}

	void TerminalOutput::clearScreen()
	{
		for (int y = 0; y < getHeight(); ++y)
		{
			for (int x = 0; x < getWidth(); ++x)
			{
				putEntity(x, y, ' ', attribute);
			}
		}
	}

	void TerminalOutput::setAttribute(uint8_t attribute)
	{
		this->attribute = attribute;
	}
}
