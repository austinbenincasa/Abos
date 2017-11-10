# Abos
A Basic Operating System

### Requirements
- gcc / ld
- qemu
- nasm
- build-essentials

### Building Kernel
```bash
austin@computer:~/Abos$ ./build
```
### Booting Kernel
```bash
austin@computer:~/Abos$ qemu-system-i386 -kernel kernel.elf
```
