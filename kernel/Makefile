CXX = i686-elf-g++
CXXFLAGS = -nostdlib -Iinclude -std=c++14
LD = i686-elf-ld
LDFLAGS = -nostdlib -T link.ld

BUILD_DIR = bin
BINARIES = bin/kernel.o bin/Screen.o bin/Port.o
DEPENDENCIES = src/kernel.cpp include/Screen.hpp include/Screen.cpp include/HAL/Port.hpp src/HAL/Port.cpp
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

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
	rm $(KERNEL_FILE)
