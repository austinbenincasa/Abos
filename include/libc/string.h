#ifndef STRING_H
#define STRING_H

#include "libc/sys/cdefs.h"
#include <stddef.h>


int memcmp(const void*, const void*, uint16_t);
void* memcpy(void* __restrict, const void* __restrict, uint16_t);
void* memmove(void*, const void*, uint16_t);
void* memset(void*, int, uint16_t);
uint16_t strlen(const char*);


#endif
