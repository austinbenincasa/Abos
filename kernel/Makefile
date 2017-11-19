dirs := cpu/
files := $(foreach dir,$(dirs),$(wildcard $(dir)*.c))

.PHONY: all build link clean
all: $(files) build link

build: $(files)
	@echo "Compiling Kernel..."
	@nasm -f elf32 entry.asm -o '../obj/entry.o'
	@nasm -f elf32 idt-gdt.asm -o '../obj/idt-gdt.o'
	@nasm -f elf32 io.asm -o '../obj/io.o'
	@$(foreach f, $(files), \
	gcc -c -m32 -std=c99 -ffreestanding -fno-builtin -Os -o  $(addsuffix $(basename $(notdir $f)), ../obj/).o -Wall -Wextra $f;)
	@gcc -c -m32 -std=c99 -ffreestanding -fno-builtin -Os -o '../obj/kernel.o' -Wall -Wextra kernel.c
	@echo "Finished Compiling Kernel"

link: linker.ld
	@echo "Linking Kernel..."
	@ld -m elf_i386 -nostdlib -T linker.ld -o '../kernel.elf' ../obj/*.o ../obj/*/*.o
	@echo "Finished Linking Kernel"
	@echo "Successfully created kernel.elf"

clean:
	@echo "Kernel:\tCleaning..."