OBJ_DIR?=../obj
CC?=gcc
CC_ARGS?=-m32 -std=c99 -ffreestanding -fno-builtin -Os -Wall -Wextra

DIRS:=string/ stdio/ stdlib/
FILES:=$(foreach dir,$(DIRS),$(wildcard $(dir)*.c))
OBJS:=$(patsubst %.c,$(OBJ_DIR)/%.o,$(FILES))

.PHONY: all
all: $(OBJS)

$(OBJ_DIR)/%.o: %.c
	@echo "Libc:\tCompiling $<..."
	@mkdir -p $(@D)
	@$(CC) -c $(CC_ARGS) -o $@ $<