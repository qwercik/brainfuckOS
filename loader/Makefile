ASM = nasm
ASMFLAGS = -i src/

all: loader.bin

loader.bin: src/boot.asm
	$(ASM) -o $@ $^ $(ASMFLAGS)

clean:
	rm loader.bin

run:
	qemu-system-i386 -fda loader.bin
