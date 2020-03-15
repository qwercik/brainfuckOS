#pragma once

#include <Screen/TerminalOutput.hpp>
#include <stdint.h>

namespace bfos::screen
{
	class VgaTextModeTerminalOutput : public TerminalOutput<uint8_t>
	{
	public:
		const uint16_t WIDTH = 80;
		const uint16_t HEIGHT = 25;

		uint16_t getWidth() const override;
		uint16_t getHeight() const override;
	
	protected:
		void putEntity(uint16_t positionX, uint16_t positionY, char character, uint8_t attribute) override;

	private:
		uint16_t* videoMemory = reinterpret_cast<uint16_t*>(0xB8000);
	};
}
