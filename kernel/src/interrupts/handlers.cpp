#include <interrupts/handlers.hpp>
#include <panic.hpp>
#include <terminal/Output.hpp>

namespace bfos::interrupts::handlers {
    __attribute__((interrupt)) void divisionByZero(InterruptFrame *frame) {
        bfos::panic("Nie dziel przez zero, ty glupia cholero!");
    }

    __attribute__((interrupt)) void generalProtectionFault(InterruptFrame *frame) {
        bfos::panic("General protection fault");
    }
}