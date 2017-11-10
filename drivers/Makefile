.PHONY: all
all: build

.PHONY: build
build:
	@echo "Compiling Drivers..."
	@gcc -c -m32 -std=c99 -ffreestanding -fno-builtin -Os -o '../obj/screen.o' -Wall -Wextra screen.c
	@echo "Finished Compiling Drivers"