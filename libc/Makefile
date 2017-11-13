dirs := string/ stdio/ stdlib/
files := $(foreach dir,$(dirs),$(wildcard $(dir)*.c))


.PHONY: all
all: build

.PHONY: build
build: $(files)
	@echo "Compiing Libc..."
	@$(foreach f, $(files), \
	gcc -c -m32 -std=c99 -ffreestanding -fno-builtin -Os -o  $(addsuffix $(basename $(notdir $f)), ../obj/).o -Wall -Wextra $f;)
	@echo "Finished Compiling Libc"
