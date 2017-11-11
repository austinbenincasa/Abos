.PHONY: all
all: build

.PHONY: build
build:
	@echo "Compiling Drivers..."
	@gcc -c -m32 -std=c99 -ffreestanding -fno-builtin -Os -o '../obj/screen.o' -Wall -Wextra screen.c
	@gcc -c -m32 -std=c99 -ffreestanding -fno-builtin -Os -o '../obj/keyboard.o' -Wall -Wextra keyboard.c
	@echo "Finished Compiling Drivers"