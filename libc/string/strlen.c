#include "../include/string.h"

uint16_t strlen(const char* str) {
	uint16_t len = 0;
	while (str[len])
		len++;
	return len;
}
