#pragma once

namespace bfos::interrupts::handlers {
    struct InterruptFrame;

    __attribute__((interrupt)) void divisionByZero(InterruptFrame *frame);
    __attribute__((interrupt)) void generalProtectionFault(InterruptFrame *frame);
}