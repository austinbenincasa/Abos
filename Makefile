include Makefile.inc

.PHONY: drivers libc terminal kernel clean all

all: obj/ drivers libc terminal kernel

obj/:
	@mkdir -p obj/

drivers:
	$(MAKE) -C drivers/

libc:
	$(MAKE) -C libc/

terminal:
	$(MAKE) -C terminal/

kernel:
	$(MAKE) -C kernel/

clean:
	rm -rf obj/
	$(MAKE) -C kernel/ clean