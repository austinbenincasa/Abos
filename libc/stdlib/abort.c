#include "../include/stdio.h"
#include "../include/stdlib.h"

void abort(void) {
	printf("kernel: panic: abort()\n");
}
