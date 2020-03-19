#include <interrupts/handlers.hpp>
#include <interrupts/InterruptFrame.hpp>
#include <panic.hpp>
#include <terminal/Output.hpp>

namespace bfos::interrupts::handlers {
    extern "C" {
        WRAP_HANDLER(divisionByZero);
        void divisionByZero(InterruptFrame registers) {
            terminal::Output terminal;
            terminal.setAttribute(0xF0);
            terminal.clearScreen();
            terminal.print("Addr: %x\n", divisionByZeroHandlerWrapper);
            terminal.print("EAX = %x\n", registers.eax);
            terminal.print("EBX = %x\n", registers.ebx);
            terminal.print("ECX = %x\n", registers.ecx);
            terminal.print("EDX = %x\n", registers.edx);
            terminal.print("EFLAGS = %x\n", registers.eflags);
            terminal.print("CS = %x\n", registers.cs);
            terminal.print("DS = %x\n", registers.ds);
            terminal.print("ES = %x\n", registers.es);
            terminal.print("SS = %x\n", registers.ss);
            terminal.print("FS = %x\n", registers.fs);
            terminal.print("GS = %x\n", registers.gs);

            while (true);
        }

        WRAP_HANDLER(generalProtectionFault);
        void generalProtectionFault(InterruptFrame registers) {
            bfos::panic("General protection fault");
        }
    }
}