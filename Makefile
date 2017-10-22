BINARIES = loader/loader.bin kernel/kernel.bin
FLOPPY_FILE = floppy.img

all: $(FLOPPY_FILE)

$(FLOPPY_FILE): $(BINARIES)
	cat $^ > $@
	./utils/fix-sectors-amount.py $@
	./utils/align-to-full-sector.py $@

loader/loader.bin:
	make -C loader/

kernel/kernel.bin:
	make -C kernel/


.PHONY: clean
clean:
	rm $(FLOPPY_FILE) 
	make -C loader/ clean
	make -C kernel/ clean

.PHONY: run
run:
	qemu-system-i386 -fda $(FLOPPY_FILE) -m 512M
