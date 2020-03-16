#pragma once

#include <terminal/RawOutput.hpp>

namespace bfos::terminal {
    class Output : public RawOutput {
    public:
        void print(const char *format, ...);
    };
}