#pragma once

#include <stdint.h>
#include <interrupts/InterruptFrame.hpp>

#define WRAP_HANDLER(name) \
    __asm__( \
        ".global " #name "HandlerWrapper \n" \
        #name "HandlerWrapper: \n\t" \
        "cld\n\t" \
        "pushw %gs\n\t" \
        "pushw %fs\n\t" \
        "pushw %es\n\t" \
        "pushw %ds\n\t" \
        "pushw %ss\n\t" \
        "pushw %cs\n\t" \
        "pushfl\n\t" \
        "pushal\n\t" \
        "call " #name "\n\t" \
        "popal\n\t" \
        "popfl\n\t" \
        "add $4, %esp\n\t" \
        "popw %ds\n\t" \
        "popw %es\n\t" \
        "popw %fs\n\t" \
        "popw %gs\n\t" \
        "iret" \
    );

#define HANDLER_DECLARATION(name) \
    void name##HandlerWrapper();


namespace bfos::interrupts::handlers {
    extern "C" {
        HANDLER_DECLARATION(divisionByZero);
        void divisionByZero(InterruptFrame registers);

        HANDLER_DECLARATION(generalProtectionFault);
        void generalProtectionFault(InterruptFrame registers);
    }
}

