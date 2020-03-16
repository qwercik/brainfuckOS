#include <string.hpp>
#include <terminal/Output.hpp>

static const char* const DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUWVXYZ";

namespace bfos::string {
    unsigned length(const char *string) {
        unsigned index = 0;
        while (string[index]) {
            index++;
        }

        return index;
    }

    void reverse(char *string, unsigned length) {
        for (unsigned index = 0; index < length / 2; ++index) {
            int temp = string[index];
            string[index] = string[length - 1 - index];
            string[length - 1 - index] = temp;
        }
    }

    char *fromInt(long int value, char *buffer, unsigned base) {
        bool negative = value < 0 && base == 10 ? true : false;
        unsigned long int absoluteValue = value < 0 && base == 10 ? -value : value;

        unsigned index = 0;
        while (absoluteValue > 0) {
            buffer[index++] = DIGITS[absoluteValue % base];
            absoluteValue /= base;
        }

        switch (base) {
        case 2:
            buffer[index++] = 'b';
            buffer[index++] = '0';
            break;
        case 8:
            buffer[index++] = '0';
            break;
        case 16:
            buffer[index++] = 'x';
            buffer[index++] = '0';
            break;
        }

        if (negative) {
            buffer[index++] = '-';
        }

        buffer[index] = '\0';

        reverse(buffer, index);
        return buffer;
    }
}