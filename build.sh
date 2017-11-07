nasm -f elf32 entry.asm -o entry.o
gcc -c -m32 -std=c99 -ffreestanding -fno-builtin -Os -o 'kernel.o' -Wall -Wextra kernel.c
ld -m elf_i386 -nostdlib -T linker.ld -o 'kernel.elf' entry.o kernel.o
cp kernel.elf iso/boot/
rm *.o
qemu-system-i386 -kernel kernel.elf