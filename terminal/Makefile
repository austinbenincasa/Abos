OBJ_DIR?=../obj
CC?=gcc
CC_ARGS?=-m32 -std=c99 -ffreestanding -fno-builtin -Os -Wall -Wextra

FILES:=$(wildcard *.c)
OBJS:=$(patsubst %.c,$(OBJ_DIR)/%.o,$(FILES))

.PHONY: all
all: $(OBJS)

$(OBJ_DIR)/%.o: %.c
	@echo "Terminal:\tCompiling $<..."
	@$(CC) -c $(CC_ARGS) -o $@ $<