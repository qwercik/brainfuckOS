#pragma once

#include <stdint.h>

namespace bfos::interrupts {
    // Order is important of course!
    struct InterruptFrame {
        uint32_t edi, esi;
        uint32_t ebp, esp;
        uint32_t ebx, edx, ecx, eax;
        uint32_t eflags;
        uint16_t cs, ss, ds, es, fs, gs;
    } __attribute__((packed));
}