ASM = nasm
ASMFLAGS = -i src/

all: loader.bin
BINARIES = bin/boot.bin bin/stage2.bin 

loader.bin: $(BINARIES) 
	cat $^ > $@

bin/%.bin: src/%.asm
	$(ASM) -o $@ $< $(ASMFLAGS)

clean:
	rm loader.bin

run:
	qemu-system-i386 -fda loader.bin
