#include <interrupts/handlers.hpp>
#include <panic.hpp>

namespace bfos::interrupts::handlers {
    void divisionByZero() {
        bfos::panic("Nie dziel przez zero, ty glupia cholero!");
    }
}