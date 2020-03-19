#include <interrupts/handlers.hpp>
#include <interrupts/InterruptFrame.hpp>
#include <panic.hpp>
#include <terminal/Output.hpp>

namespace bfos::interrupts::handlers {
    extern "C" {
        WRAP_HANDLER(divisionByZero);
        void divisionByZero(void *frame) {
            terminal::Output terminal;
            terminal.setAttribute(0xF0);
            terminal.clearScreen();
            terminal.print("Division by zero");

            while (true);
        }

        WRAP_HANDLER(generalProtectionFault);
        void generalProtectionFault(void *frame) {
            bfos::panic("General protection fault");
        }
    }
}