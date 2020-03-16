#include <terminal/RawOutput.hpp>
#include <terminal/cursor.hpp>
#include <hal/port.hpp>
#include <memory/utils.hpp>

namespace bfos::terminal {
    void RawOutput::printChar(char character) {
        switch (character) {
        case '\n':
            this->positionY++;
            this->positionX = 0;
            break;

        case '\r':
            this->positionX = 0;
            break;
        
        case '\b':
            if (this->positionX == 0 && this->positionY != 0) {
                this->positionX = WIDTH - 1;
                this->positionY = HEIGHT - 1;
            } else {
                this->positionX--;
            }
            break;
        
        default:
            this->putEntity(this->positionX, this->positionY, character, this->attribute);
            this->positionX++;
        }

        // Break line
        if (this->positionX == WIDTH) {
            this->positionX = 0;
            this->positionY++;
        }
        
        // Scroll screen
        if (this->positionY == HEIGHT) {
            // Move all lines (excluding the first one) up
            memory::utils::copy(
                videoMemory + WIDTH,
                videoMemory,
                WIDTH * (HEIGHT - 1)
            );

            // Make the last line blank
            memory::utils::set(
                videoMemory + WIDTH * (HEIGHT - 1),
                static_cast<uint16_t>((this->attribute << 8) | ' '),
                WIDTH
            );

            this->positionY -= 1;
        }
    

        cursor::setPosition(positionX, positionY);
    }

    void RawOutput::printString(const char *string) {
        int index = 0;
        while (string[index] != '\0') {
            this->printChar(string[index]);
            index++;
        }
    }

    void RawOutput::clearScreen() {
        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                this->putEntity(x, y, ' ', this->attribute);
            }
        }
    }

    void RawOutput::setAttribute(Attribute attribute) {
        this->attribute = attribute;
    }

    void RawOutput::setCurrentPosition(SizeUnit positionX, SizeUnit positionY) {
        this->positionX = positionX;
        this->positionY = positionY;
    }

    inline void RawOutput::putEntity(SizeUnit positionX, SizeUnit positionY, char character, Attribute attribute) {
        this->videoMemory[positionY * WIDTH + positionX] = (attribute << 8) | character;
    }
}