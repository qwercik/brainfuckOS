#include <Screen.hpp>

namespace bfos
{
	Screen::Screen()
	{
	}

	void Screen::printCharacter(char character, uint8_t attribute)
	{
		*videoMemory++ = (attribute << 8) | character;	
	}

	void Screen::printString(const char* string, uint8_t attribute)
	{
		for (int characterIndex = 0; string[characterIndex] != '\0'; ++characterIndex)
		{
			printCharacter(string[characterIndex], attribute);
		}
	}
}
