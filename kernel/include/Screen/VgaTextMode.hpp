#pragma once

#include <Screen/TerminalOutput.hpp>
#include <types.hpp>

namespace bfos::screen
{
	class VgaTextMode : public TerminalOutput
	{
	public:
		VgaTextMode();
		void printChar(char character) override;
		void printString(const char* string) override;
		void clearScreen() override;

	private:
		uint16_t* videoMemory = reinterpret_cast<uint16_t*>(0xB8000);
	};
}
