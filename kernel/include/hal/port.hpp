#pragma once

#include <stdint.h>

namespace bfos::hal::port {
	void sendByte(uint16_t portNumber, uint8_t byte);
	void sendWord(uint16_t portNumber, uint16_t word);
	void sendDword(uint16_t portNumber, uint32_t dword);

	uint8_t receiveByte(uint16_t portNumber);
	uint16_t receiveWord(uint16_t portNumber);
	uint32_t receiveDword(uint16_t portNumber);
}
