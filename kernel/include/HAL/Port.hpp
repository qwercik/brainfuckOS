#pragma once

#include <types.hpp>

namespace bfos::hal
{
	class Port
	{
	public:	
		Port(uint16_t portNumber);
		
		void sendByte(uint8_t byte);
		void sendWord(uint16_t word);
		void sendDword(uint32_t dword);

		uint8_t receiveByte() const;
		uint16_t receiveWord() const;
		uint32_t receiveDword() const;

	private:
		uint16_t portNumber;
	};
}
