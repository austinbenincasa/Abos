# Abos
A Basic Operating System for i386 systems

### Requirements
- gcc / ld
- qemu
- nasm
- build-essentials
- Make

### Building Kernel
```bash
austin@computer:~/Abos$ make
```
### Booting Kernel
```bash
austin@computer:~/Abos$ qemu-system-i386 -kernel kernel.elf
```
