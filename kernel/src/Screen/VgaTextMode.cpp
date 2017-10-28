#include <Screen/VgaTextMode.hpp>

namespace bfos::screen
{
	VgaTextMode::VgaTextMode()
	{
	}

	void VgaTextMode::printChar(char character)
	{
		*videoMemory++ = (0x07 << 8) | character;		
	}

	void VgaTextMode::printString(const char* string)
	{
		for (int characterIndex = 0; string[characterIndex] != '\0'; ++characterIndex)
		{
			printChar(string[characterIndex]);
		}
	}

	void VgaTextMode::clearScreen() 
	{
		for (int i = 0; i < 80 * 25; ++i)
		{
			videoMemory[i] = (0x07 << 8) | ' ';
		}
	}
}
