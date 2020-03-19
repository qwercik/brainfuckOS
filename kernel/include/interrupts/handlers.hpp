#pragma once

#include <stdint.h>
#include <interrupts/InterruptFrame.hpp>

#define WRAP_HANDLER(name) \
    __asm__( \
        ".global " #name "HandlerWrapper \n" \
        #name "HandlerWrapper: \n\t" \
        "cld\n\t" \
        "pushal\n\t" \
        "call " #name "\n\t" \
        "popal\n\t" \
        "iret" \
    );

#define HANDLER_DECLARATION(name) \
    void name##HandlerWrapper();


namespace bfos::interrupts::handlers {
    extern "C" {
        HANDLER_DECLARATION(divisionByZero);
        void divisionByZero(void*);

        HANDLER_DECLARATION(generalProtectionFault);
        void generalProtectionFault(void*);
    }
}

