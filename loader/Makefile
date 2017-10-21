ASM = nasm
ASMFLAGS = -i src/
CXX = i686-elf-g++
CXXFLAGS =  

BINARIES = bin/boot.bin bin/stage2.bin bin/kernel

all: floppy.img

floppy.img: $(BINARIES)
	cat $^ > $@

bin/%.bin: src/%.asm
	$(ASM) -o $@ $< $(ASMFLAGS)

bin/kernel: src/kernel.c
	$(CXX) -o $@ $^ -nostdlib

clean:
	rm bin/*
	rm floppy.img

run:
	qemu-system-i386 -fda floppy.img -m 512M
