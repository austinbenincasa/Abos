.PHONY: all
all: build

.PHONY: build
build:
	@echo "Compiling Terminal..."
	@gcc -c -m32 -std=c99 -ffreestanding -fno-builtin -Os -o '../obj/terminal.o' -Wall -Wextra terminal.c
	@echo "Finished Compiling Terminal"