#pragma once

#include <stdint.h>
#include <interrupts/handlers.hpp>
#include <interrupts/InterruptFrame.hpp>

namespace bfos::interrupts {
    struct Idt {
        uint16_t offsetLow;
        uint16_t segmentSelector;
        uint8_t unused;
        uint8_t attributes;
        uint16_t offsetHigh;
    } __attribute__((packed));

    struct IdtPointer {
        uint16_t limit;
        uint32_t base;
    } __attribute__((packed));

    namespace idt {
        void init();

        void setEntry(unsigned id, void (*handler)());
        void load();
    }
}