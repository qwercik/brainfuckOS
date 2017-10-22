ASM = nasm
ASMFLAGS = -i src/
CXX = i686-elf-g++
CXXFLAGS =  

BINARIES = bin/boot.bin bin/stage2.bin bin/kernel

all: loader.img

loader.img: $(BINARIES)
	cat $^ > $@
	./utils/fix-sectors-amount.py loader.img
	./utils/align-to-full-sector.py loader.img

bin/%.bin: src/%.asm
	$(ASM) -o $@ $< $(ASMFLAGS)

bin/kernel: src/kernel.c
	$(CXX) -o $@ $^ -nostdlib

clean:
	rm bin/*
	rm loader.img

run:
	qemu-system-i386 -fda loader.img -m 512M
