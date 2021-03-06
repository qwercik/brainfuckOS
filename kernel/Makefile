CXX = i686-elf-g++ 
CXXFLAGS = -Iinclude -std=c++17 -fno-rtti -ffreestanding
LD = i686-elf-ld
LDFLAGS = -T link.ld

BUILD_DIR = bin
BINARIES = bin/kernel.o bin/port.o bin/RawOutput.o bin/Output.o bin/cursor.o bin/string.o bin/panic.o bin/idt.o bin/handlers.o
DEPENDENCIES = src/kernel.cpp include/hal/port.hpp src/hal/port.cpp include/cppsupport.hpp include/terminal/RawOutput.hpp src/terminal/RawOutput.cpp include/terminal/cursor.hpp src/terminal/cursor.cpp include/memory/utils.hpp src/memory/utils.cpp include/string.hpp src/string.cpp include/terminal/Output.hpp src/terminal/Output.cpp include/panic.hpp src/panic.cpp include/interrupts/idt.hpp src/interrupts/idt.cpp include/interrupts/handlers.hpp src/interrupts/handlers.cpp
KERNEL_FILE = kernel.bin

.PHONY: all
all: $(BUILD_DIR) $(KERNEL_FILE)

$(BUILD_DIR):
	mkdir $@

$(KERNEL_FILE): $(BINARIES)
	$(LD) -o $@ $^ $(LDFLAGS)

bin/%.o: src/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

bin/%.o: src/hal/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

bin/%.o: src/terminal/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

bin/%.o: src/memory/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

bin/handlers.o: src/interrupts/handlers.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS) -mgeneral-regs-only

bin/%.o: src/interrupts/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
	rm $(KERNEL_FILE)
