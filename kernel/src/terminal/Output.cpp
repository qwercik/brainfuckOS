#include <terminal/Output.hpp>
#include <string.hpp>
#include <stdarg.h>

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
                    char buffer[100];
                    long int value = va_arg(args, long int);
                    this->printString(string::fromInt(value, buffer));
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