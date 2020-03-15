#include <hal/port.hpp>

namespace bfos::hal::port {
	void sendByte(uint16_t portNumber, uint8_t byte) {
		__asm__ __volatile__ ("outb %1, %0" : : "dN" (portNumber), "a" (byte));
	}

	void sendWord(uint16_t portNumber, uint16_t word) {
		__asm__ __volatile__ ("outw %1, %0" : : "dN" (portNumber), "a" (word));
	}

	void sendDword(uint16_t portNumber, uint32_t dword) {
		__asm__ __volatile__ ("outl %1, %0" : : "dN" (portNumber), "a" (dword));
	}

	uint8_t receiveByte(uint16_t portNumber) {
		uint8_t byte;
		__asm__ __volatile__ ("inb %1, %0" : "=a" (byte) : "dN" (portNumber));
		return byte;
	}


	uint16_t receiveWord(uint16_t portNumber) {
		uint16_t word;
		__asm__ __volatile__ ("inw %1, %0" : "=a" (word) : "dN" (portNumber));
		return word;
	}

	uint32_t receiveDword(uint16_t portNumber) {
		uint32_t dword;
		__asm__ __volatile__ ("inl %1, %0" : "=a" (dword) : "dN" (portNumber));
		return dword;
	}
}
