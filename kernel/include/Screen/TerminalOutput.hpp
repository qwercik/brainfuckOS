#pragma once

#include <types.hpp>

namespace bfos::screen
{
	class TerminalOutput
	{
	public:
		void printChar(char character, uint8_t attribute);
		void printString(const char* string, uint8_t attribute);
		void clearScreen(uint8_t attribute);

		virtual uint16_t getWidth() const = 0;
		virtual uint16_t getHeight() const = 0;

	protected:
		virtual void putEntity(uint16_t positionX, uint16_t positionY, char character, uint8_t attribute) = 0;

	private:
		uint16_t currentPositionX = 0;
		uint16_t currentPositionY = 0;
	};
}
