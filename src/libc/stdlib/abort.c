#include <libc/stdio.h>
#include <libc/stdlib.h>

void abort(void) {
	printf("kernel: panic: abort()\n");
}
