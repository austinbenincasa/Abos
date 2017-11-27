bits 32
global loader
global stack_ptr

extern kmain

MODULEALIGN equ 1<<0
MEMINFO equ 1<<1
FLAGS equ MODULEALIGN | MEMINFO
MAGIC equ 0x1BADB002
CHECKSUM equ -(MAGIC + FLAGS)

section .mbheader
align 4
MultiBootHeader:
  dd MAGIC
  dd FLAGS
  dd CHECKSUM

section .text

STACKSIZE equ 0x4000

loader:
  mov esp, stack+STACKSIZE
  cli
  call kmain

hang:
  hlt
  jmp hang

section .bss
align 4
stack:
  resb STACKSIZE
stack_ptr: