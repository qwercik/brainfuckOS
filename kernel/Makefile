CXX = i686-elf-g++ 
CXXFLAGS = -Iinclude -std=c++17 -fno-rtti -ffreestanding
LD = i686-elf-ld
LDFLAGS = -T link.ld

BUILD_DIR = bin
BINARIES = bin/kernel.o bin/port.o bin/Output.o bin/cursor.o
DEPENDENCIES = src/kernel.cpp include/hal/port.hpp src/hal/port.cpp include/cppsupport.hpp include/terminal/Output.hpp src/terminal/Output.cpp include/terminal/cursor.hpp src/terminal/cursor.cpp
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

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
	rm $(KERNEL_FILE)
