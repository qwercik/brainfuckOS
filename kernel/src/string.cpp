#include <string.hpp>

namespace bfos::string {
    void reverse(char *string, unsigned length) {
        for (unsigned index = 0; index <= length / 2; ++index) {
            int temp = string[index];
            string[index] = string[length - 1 - index];
            string[length - 1 - index] = temp;
        }
    }

    char *fromInt(long int value, char *buffer) {
        bool negative = value > 0 ? false : true;
        value = value > 0 ? value : -value;

        unsigned index = 0;
        while (value > 0) {
            buffer[index++] = '0' + value % 10;
            value /= 10;
        }

        if (negative) {
            buffer[index++] = '-';
        }

        buffer[index] = '\0';

        reverse(buffer, index);
        return buffer;
    }
}