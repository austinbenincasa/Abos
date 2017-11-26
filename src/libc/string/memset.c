#include <libc/string.h>

void* memset(void* bufptr, int value, uint16_t size) {
	unsigned char* buf = (unsigned char*) bufptr;
	for (uint16_t i = 0; i < size; i++)
		buf[i] = (unsigned char) value;
	return bufptr;
}
