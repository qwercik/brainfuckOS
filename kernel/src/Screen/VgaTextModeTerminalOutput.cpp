#include <Screen/VgaTextModeTerminalOutput.hpp>

namespace bfos::screen
{
	uint16_t VgaTextModeTerminalOutput::getWidth() const
	{
		return WIDTH;
	}

	uint16_t VgaTextModeTerminalOutput::getHeight() const
	{
		return HEIGHT;
	}

	void VgaTextModeTerminalOutput::putEntity(uint16_t positionX, uint16_t positionY, char character, uint8_t attribute)
	{
		uint32_t offset = positionY * WIDTH + positionX;
		videoMemory[offset] = (attribute << 8) | character;
	}
}
