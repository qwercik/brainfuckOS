#pragma once

namespace bfos::string {
    unsigned length(const char *string);
    void reverse(char *string, unsigned length);
    char *fromInt(long int value, char *buffer, unsigned base);
}