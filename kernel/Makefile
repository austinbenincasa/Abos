.PHONY: all
all: build link

.PHONY: build
build:
	@echo "Compiling Kernel..."
	@gcc -c -m32 -std=c99 -ffreestanding -fno-builtin -Os -o '../obj/kernel.o' -Wall -Wextra kernel.c
	@echo "Finished Compiling Kernel"

.PHONY: link
link: linker.ld
	@echo "Linking Kernel..."
	@nasm -f elf32 entry.asm -o '../obj/entry.o'
	@ld -m elf_i386 -nostdlib -T linker.ld -o '../kernel.elf' ../obj/*.o
	@echo "Finished Linking Kernel"
	@echo "Successfully created kernel.elf"
.PHONY: clean
clean:
	@rm -rf ../obj