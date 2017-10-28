#include <HAL/Port.hpp>

namespace bfos::hal
{
	Port::Port(uint16_t portNumber) :
	portNumber(portNumber)
	{
	}

	void Port::sendByte(uint8_t byte)
	{
		__asm__ __volatile__ ("outb %1, %0" : : "dN" (portNumber), "a" (byte));
	}

	void Port::sendWord(uint16_t word)
	{
		__asm__ __volatile__ ("outw %1, %0" : : "dN" (portNumber), "a" (word));
	}

	void Port::sendDword(uint32_t dword)
	{
		__asm__ __volatile__ ("outl %1, %0" : : "dN" (portNumber), "a" (dword));
	}

	uint8_t Port::receiveByte() const
	{
		uint8_t byte;
		__asm__ __volatile__ ("inb %1, %0" : "=a" (byte) : "dN" (portNumber));
		return byte;
	}


	uint16_t Port::receiveWord() const
	{
		uint16_t word;
		__asm__ __volatile__ ("inw %1, %0" : "=a" (word) : "dN" (portNumber));
		return word;
	}

	uint32_t Port::receiveDword() const
	{
		uint32_t dword;
		__asm__ __volatile__ ("inl %1, %0" : "=a" (dword) : "dN" (portNumber));
		return dword;
	}
}
