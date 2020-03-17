#include <terminal/Output.hpp>
#include <string.hpp>
#include <stdarg.h>

inline unsigned detectBase(char letter) {
    switch (letter) {
    case 'b': return 2;
    case 'o': return 8;
    case 'd': return 10;
    case 'l': return 10;
    case 'x': return 16;
    default: return 10;
    }
}

namespace bfos::terminal {
    void Output::print(const char *format, ...) {
        va_list args;
        va_start(args, format);

        this->vprint(format, args);

        va_end(args);
    }

    void Output::printColor(uint8_t color, const char *format, ...) {
        va_list args;
        va_start(args, format);
        this->vprintColor(color, format, args);
        va_end(args);
    }

    void Output::info(const char *format, ...) {
        va_list args;
        va_start(args, format);
        this->vprintColor(0xA, format, args);
        va_end(args);
    }
    
    void Output::warning(const char *format, ...) {
        va_list args;
        va_start(args, format);
        this->vprintColor(0xE, format, args);
        va_end(args);
    }

    void Output::error(const char *format, ...) {
        va_list args;
        va_start(args, format);
        this->vprintColor(0xC, format, args);
        va_end(args);
    }

    void Output::vprint(const char *format, va_list args) {
        unsigned index = 0;

        while (format[index] != '\0') {
            if (format[index] == '%') {
                index++;
                switch (format[index]) {
                case '%':
                    this->printChar('%');
                    break;
                case 's':
                    this->printString(va_arg(args, char*));
                    break;

                case 'd':
                case 'l':
                case 'b':
                case 'o':
                case 'x':
                    unsigned base = detectBase(format[index]);

                    char buffer[100];
                    long int value = va_arg(args, long int);
                    this->printString(string::fromInt(value, buffer, base));
                    break;
                }
            } else {
                this->printChar(format[index]);
            }

            index++;
        }
    }

    void Output::vprintColor(uint8_t color, const char *format, va_list args) {
        uint16_t oldColor = this->getAttribute();
        this->setAttribute(color);
        this->vprint(format, args);
        this->setAttribute(oldColor);
    } 
}