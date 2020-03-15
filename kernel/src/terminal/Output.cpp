#include <terminal/Output.hpp>
#include <terminal/cursor.hpp>
#include <hal/port.hpp>

namespace bfos::terminal {
    void Output::printChar(char character) {
        switch (character) {
        case '\n':
            this->positionY++;
            this->positionX = 0;
            break;

        case '\r':
            this->positionX = 0;
            break;
        
        default:
            this->putEntity(this->positionX, this->positionY, character, this->attribute);
            this->positionX++;
        }

        
        if (this->positionX == this->getWidth()) {
            this->positionX = 0;
            this->positionY++;

            if (this->positionY == this->getHeight()) {
                // Move all lines (excluding the first one) up
                for (int y = 1; y < this->getHeight(); ++y) {
                    for (int x = 0; x < this->getWidth(); ++x) {
                        char character = this->getEntity(x, y);
                        this->putEntity(x, y - 1, character, this->attribute);
                    }
                }
            }
        }

        cursor::setPosition(positionX, positionY);
    }

    void Output::printString(const char *string) {
        int index = 0;
        while (string[index] != '\0') {
            this->printChar(string[index]);
            index++;
        }
    }

    void Output::clearScreen() {
        for (int y = 0; y < this->getHeight(); ++y) {
            for (int x = 0; x < this->getWidth(); ++x) {
                this->putEntity(x, y, ' ', this->attribute);
            }
        }
    }

    void Output::setAttribute(Attribute attribute) {
        this->attribute = attribute;
    }

    void Output::setCurrentPosition(SizeUnit positionX, SizeUnit positionY) {
        this->positionX = positionX;
        this->positionY = positionY;
    }

    SizeUnit Output::getWidth() const {
        return 80;
    }

    SizeUnit Output::getHeight() const {
        return 40;
    }

    void Output::putEntity(SizeUnit positionX, SizeUnit positionY, char character, Attribute attribute) {
        this->videoMemory[positionY * this->getWidth() + positionX] = (attribute << 8) | character;
    }

    char Output::getEntity(SizeUnit positionX, SizeUnit positionY) const {
        return this->videoMemory[positionY * this->getWidth() + positionX] & 0xFF;
    }
}