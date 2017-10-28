ASM = nasm
ASMFLAGS = -i include/

BUILD_DIR = bin
BINARIES = $(BUILD_DIR)/boot.bin $(BUILD_DIR)/stage2.bin
DEPENDENCIES = include/a20.asm include/elf.asm include/gdt.asm include/memory.asm include/rmode_screen.asm
LOADER_FILE = loader.bin

.PHONY: all
all: $(BUILD_DIR) $(LOADER_FILE)

$(BUILD_DIR):
	mkdir $@

$(LOADER_FILE): $(BINARIES)
	cat $^ > $@

$(BUILD_DIR)/%.bin: src/%.asm $(DEPENDENCIES)
	$(ASM) -o $@ $< $(ASMFLAGS)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
	rm $(LOADER_FILE)
