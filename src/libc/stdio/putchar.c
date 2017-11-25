#include <libc/stdio.h>

#include <drivers/screen.h>


int putchar(int ic) {
	char c = (char) ic;
	screen_write(&c, sizeof(c));
	return ic;
}
