#pragma once

#include <stdint.h>

namespace bfos::terminal {
    using SizeUnit = uint16_t;
    using Attribute = uint8_t;

    const int WIDTH = 80;
    const int HEIGHT = 25;

    class RawOutput {
    public:
        void printChar(char character);
        void printString(const char *string);
        
        void clearScreen();
        
        void setAttribute(Attribute attribute);
        void setCurrentPosition(SizeUnit positionX, SizeUnit positionY);

        inline void putEntity(SizeUnit positionX, SizeUnit positionY, char character, Attribute attribute);
    
    private:
        SizeUnit positionX = 0;
        SizeUnit positionY = 0;
        Attribute attribute = 0x07;

        uint16_t * const videoMemory = reinterpret_cast<uint16_t*>(0xB8000);
    };
}