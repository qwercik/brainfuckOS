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

        va_end(args);
    }
}