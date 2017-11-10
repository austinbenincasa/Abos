#include <stdio.h>

#include "../../drivers/include/screen.h"


int putchar(int ic) {
	char c = (char) ic;
	screen_write(&c, sizeof(c));
	return ic;
}
