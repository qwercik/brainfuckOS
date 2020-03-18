#include <panic.hpp>
#include <string.hpp>
#include <terminal/Output.hpp>

namespace bfos {
    void centerPrint(terminal::Output& terminal, const char *message) {
        for (unsigned index = 0; index < (terminal::WIDTH - string::length(message)) / 2; ++index) {
            terminal.printChar(' ');
        }

        terminal.printString(message);
    }

    void panic(const char *message) {
        terminal::Output terminal;
        terminal.setAttribute(0x1F); // White text on Blue screen
        terminal.clearScreen();
        
        const int LINES = 3;
        for (unsigned index = 0; index < (terminal::HEIGHT - LINES) / 2; ++index) {
            terminal.printChar('\n');
        }

        centerPrint(terminal, "An error ocurred");
        terminal.printString("\n\n");
        centerPrint(terminal, message);

        while (true);
    }
}