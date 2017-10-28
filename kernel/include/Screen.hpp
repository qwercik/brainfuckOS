#pragma once

#include <types.hpp>

namespace bfos
{
	class Screen
	{
	public:
		Screen();
		void printCharacter(char character, uint8_t attribute = 0x07);
		void printString(const char*, uint8_t attribute = 0x07);

	private:
		uint16_t* videoMemory = reinterpret_cast<uint16_t*>(0xB8000);
	};
}
