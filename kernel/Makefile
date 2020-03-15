CXX = i686-elf-g++ 
CXXFLAGS = -Iinclude -std=c++17 -fno-rtti -ffreestanding
LD = i686-elf-ld
LDFLAGS = -T link.ld

BUILD_DIR = bin
BINARIES = bin/kernel.o bin/Port.o bin/VgaTextModeTerminalOutput.o
DEPENDENCIES = src/kernel.cpp include/HAL/Port.hpp src/HAL/Port.cpp include/Screen/TerminalOutput.hpp include/Screen/VgaTextModeTerminalOutput.hpp src/Screen/VgaTextModeTerminalOutput.cpp include/cppsupport.hpp
KERNEL_FILE = kernel.bin

.PHONY: all
all: $(BUILD_DIR) $(KERNEL_FILE)

$(BUILD_DIR):
	mkdir $@

$(KERNEL_FILE): $(BINARIES)
	$(LD) -o $@ $^ $(LDFLAGS)

bin/%.o: src/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

bin/%.o: src/HAL/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

bin/%.o: src/Screen/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
	rm $(KERNEL_FILE)
