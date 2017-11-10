#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "../libc/include/string.h"
#include "include/screen.h"

#include "include/vga.h"

static const uint16_t VGA_WIDTH = 80;
static const uint16_t VGA_HEIGHT = 25;

//start of the VGA memory space
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static uint16_t screen_row;
static uint16_t screen_column;
static uint8_t screen_color;
static uint16_t* screen_buffer;

void screen_init(void) {
	screen_row = 0;
	screen_column = 0;
	screen_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	screen_buffer = VGA_MEMORY;
	for (uint16_t y = 0; y < VGA_HEIGHT; y++) {
		for (uint16_t x = 0; x < VGA_WIDTH; x++) {
			const uint16_t index = y * VGA_WIDTH + x;
			screen_buffer[index] = vga_entry(' ', screen_color);
		}
	}
}

void screen_setcolor_default() {
	screen_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
}

void screen_setcolor(uint8_t color) {
	screen_color = color;
}

void screen_putentryat(unsigned char c, uint8_t color, uint16_t x, uint16_t y) {
	const uint16_t index = y * VGA_WIDTH + x;
	screen_buffer[index] = vga_entry(c, color);
}

void screen_putchar(char c) {
	unsigned char uc = c;
	if(uc == '\n')
    {
        screen_column = 0;   
        screen_row += 1;
	}
	else
	{
		screen_putentryat(uc, screen_color, screen_column, screen_row);
		if (++screen_column == VGA_WIDTH) 
		{
			screen_column = 0;
			if (++screen_row == VGA_HEIGHT)
			{
				screen_row = 0;
			}
		}
	}
}

void screen_write(const char* data, uint8_t size) {
	for (uint16_t i = 0; i < size; i++)
	{
		screen_putchar(data[i]);
	}
}
void screen_writestring(const char* data) {
	screen_write(data, strlen(data));
}
