#pragma once

#include <stdint.h>

namespace bfos::interrupts {
    struct InterruptFrame {
        uint32_t ip;
        uint32_t cs;
        uint32_t flags;
        uint32_t sp;
        uint32_t ss;
    } __attribute__((packed));
}