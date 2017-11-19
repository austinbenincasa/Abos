include Makefile.inc

.PHONY: all

all: kernel.elf

FILES:=$(shell find . -type f -name '*.c')
OBJS:=$(patsubst ./%.c,obj/%.o,$(FILES))
FILES_2:=$(shell find . -type f -name '*.asm')
OBJS_2:=$(patsubst ./%.asm,obj/%.o,$(FILES_2))
FILES:=$(FILES) $(FILES_2)
OBJS:=$(OBJS) $(OBJS_2)

obj/%.o: ./%.asm
	@echo "Assembling\t$^..."
	@mkdir -p $(@D)
	@$(ASM) $(ASM_ARGS) $^ -o $@

obj/%.o: ./%.c
	@echo "Compiling\t$^..."
	@mkdir -p $(@D)
	@$(CC) -c $(CC_ARGS) -o $@ $^


kernel.elf: $(OBJS)
	@echo "Linking Kernel..."
	@ld -m elf_i386 -nostdlib -T kernel/linker.ld -o $@ $^
	@echo "Finished Linking Kernel"
	@echo "Successfully created kernel.elf"

clean:
	rm -rf obj/ kernel.elf