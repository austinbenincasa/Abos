#ifndef SCREEN_H
#define SCREEN_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "vga.h"
#include "../../libc/include/string.h"
#include "../../kernel/io/port_io.h"


void screen_init(void);
void screen_setcolor(uint8_t color);
void screen_putentryat(unsigned char c, uint8_t color, uint16_t x, uint16_t y);
void screen_putchar(char c);
void screen_write(const char* data, uint8_t size);
void screen_writestring(const char* data);
void screen_setcolor_default(void);
void enable_cursor(uint8_t cursor_start, uint8_t cursor_end);
void update_cursor(int x, int y);
void screen_flush(void);
uint16_t screen_get_row(void);
uint16_t screen_get_col(void);

#endif