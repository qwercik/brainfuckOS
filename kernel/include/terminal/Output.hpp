#pragma once

#include <terminal/RawOutput.hpp>
#include <stdarg.h>

namespace bfos::terminal {
    class Output : public RawOutput {
    public:
        void print(const char *format, ...);

        void printColor(uint8_t color, const char *format, ...);
        
        void info(const char *format, ...);
        void warning(const char *format, ...);
        void error(const char *format, ...);

    private:
        void vprint(const char *format, va_list args);
        void vprintColor(uint8_t color, const char *format, va_list args);
    };
}