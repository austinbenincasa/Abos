TOP:=$(shell pwd)
OBJ_DIR=$(TOP)/obj

CC?=gcc
CC_ARGS?=-m32 -isystem $(TOP)/libc/include -std=c99 -ffreestanding -fno-builtin -Os -Wall -Wextra

ASM?=nasm
ASM_ARGS?=-f elf32

export TOP
export OBJ_DIR
export CC
export CC_ARGS