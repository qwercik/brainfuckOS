CXX = i686-elf-g++
CXXFLAGS = -nostdlib
LD = i686-elf-ld
LDFLAGS = -nostdlib

BUILD_DIR = bin
BINARIES = bin/kernel.o
DEPENDENCIES = kernel.cpp 
KERNEL_FILE = kernel.bin

.PHONY: all
all: $(BUILD_DIR) $(KERNEL_FILE)

$(BUILD_DIR):
	mkdir $@

$(KERNEL_FILE): $(BINARIES)
	$(LD) -o $@ $^ $(LDFLAGS)

bin/%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
	rm $(KERNEL_FILE)
