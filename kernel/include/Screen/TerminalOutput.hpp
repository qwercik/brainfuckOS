#pragma once

#include <cstdint>

namespace bfos::screen
{
	template <class CharacterAttribute>
	class TerminalOutput
	{
	public:
		void printChar(char character, CharacterAttribute attribute)
		{
			putEntity(currentPositionX, currentPositionY, character, attribute);
			currentPositionX++;
		}

		void printString(const char* string, CharacterAttribute attribute)
		{
			for (int characterIndex = 0; string[characterIndex] != '\0'; ++characterIndex)
			{
				printChar(string[characterIndex], attribute);
			}
		}

		void clearScreen(CharacterAttribute attribute)
		{
			for (int y = 0; y < getHeight(); ++y)
			{
				for (int x = 0; x < getWidth(); ++x)
				{
					putEntity(x, y, ' ', attribute);
				}
			}
		}

		virtual uint16_t getWidth() const = 0;
		virtual uint16_t getHeight() const = 0;

	protected:
		virtual void putEntity(uint16_t positionX, uint16_t positionY, char character, CharacterAttribute attribute) = 0;

	private:
		uint16_t currentPositionX = 0;
		uint16_t currentPositionY = 0;
	};
}
