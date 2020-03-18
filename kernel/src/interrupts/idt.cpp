#include <interrupts/idt.hpp>
#include <interrupts/handlers.hpp>

namespace bfos::interrupts::idt {
    static Idt idtArray[256];

    void init() {
        setEntry(0, handlers::divisionByZero);

        load();
    }

    void setEntry(unsigned id, void (*handler)()) {
        uint32_t handlerAddress = (uint32_t)handler;
        idtArray[id] = {
            handlerAddress & 0xFFFF, // Low handler address
            0x0008, // Code segment selector
            0x00, // Zero
            0x8E, //10001110
            (handlerAddress >> 16) & 0xFFFF
        };
    }

    void load() {
        IdtPointer pointer = {
            sizeof(idtArray) - 1,
            (uint32_t)idtArray
        };

        __asm__ __volatile__ ("lidt %0" : : "m"(pointer));
    }
}