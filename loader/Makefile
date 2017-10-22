ASM = nasm
ASMFLAGS = -i ./

BUILD_DIR = bin
BINARIES = $(BUILD_DIR)/boot.bin $(BUILD_DIR)/stage2.bin
DEPENDENCIES = a20.asm boot.asm elf.asm gdt.asm memory.asm rmode_screen.asm stage2.asm  
LOADER_FILE = loader.bin


.PHONY: all
all: $(BUILD_DIR) $(LOADER_FILE)

$(BUILD_DIR):
	mkdir $@

$(LOADER_FILE): $(BINARIES)
	cat $^ > $@

$(BUILD_DIR)/%.bin: %.asm $(DEPENDENCIES)
	$(ASM) -o $@ $< $(ASMFLAGS)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
	rm $(LOADER_FILE)
