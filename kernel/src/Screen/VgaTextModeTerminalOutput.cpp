#include <Screen/VgaTextModeTerminalOutput.hpp>

namespace bfos::screen
{
	uint16_t VgaTextMode::getWidth() const
	{
		return WIDTH;
	}

	uint16_t VgaTextMode::getHeight() const
	{
		return HEIGHT;
	}

	void VgaTextMode::putEntity(uint16_t positionX, uint16_t positionY, char character, uint8_t attribute)
	{
		uint32_t offset = positionY * WIDTH + positionX;
		videoMemory[offset] = (attribute << 8) | character;
	}
}
