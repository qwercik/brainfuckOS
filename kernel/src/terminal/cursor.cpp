#include <terminal/cursor.hpp>
#include <hal/port.hpp>

namespace bfos::terminal::cursor {
    void setPosition(uint16_t positionX, uint16_t positionY) {
        const uint16_t WIDTH = 80;
        auto offset = positionY * WIDTH + positionX;

        namespace port = bfos::hal::port;
        port::sendByte(0x3D4, 0x0F);
        port::sendByte(0x3D5, offset & 0xFF);
        port::sendByte(0x3D4, 0x0E);
        port::sendByte(0x3D5, (offset >> 8) & 0xFF);
    }
}