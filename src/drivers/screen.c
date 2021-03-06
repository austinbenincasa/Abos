#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <drivers/screen.h>
#include <drivers/vga.h>
#include <libc/string.h>
#include <kernel/io/port_io.h>


static const uint16_t VGA_WIDTH = 80;
static const uint16_t VGA_HEIGHT = 25;

//start of the VGA memory space
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static int16_t screen_row;
static int16_t screen_column;
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

void screen_setcolor_default(void) {
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
		if(screen_row == VGA_HEIGHT)
		{
			screen_row = 24;
			screen_scroll();
		}
	}
	else if(uc == '\b')
    {
		//weird unsigned int compare
		if(!(0 <= screen_column--))
		{
			if(!(0 <= screen_row--))
			{
				screen_putentryat(' ', screen_color, screen_column, screen_row);
				screen_column = 0;    
				screen_row = 0;
			}
			else
			{
				screen_putentryat(' ', screen_color, screen_column, screen_row);
				screen_column = VGA_WIDTH - 1;
			}
		}
		else
		{
			screen_putentryat(' ', screen_color, screen_column, screen_row);
		}
	}
	else
	{
		screen_putentryat(uc, screen_color, screen_column, screen_row);
		if (++screen_column == VGA_WIDTH) 
		{
			screen_column = 0;
			if (++screen_row == VGA_HEIGHT)
			{
				screen_row = 24;
				screen_scroll();
			}
		}
	}
	update_cursor(screen_column, screen_row);
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

void enable_cursor(uint8_t cursor_start, uint8_t cursor_end)
{
	wportb(0x3D4, 0x0A);
	wportb(0x3D5, (rportb(0x3D5) & 0xC0) | cursor_start);
 
	wportb(0x3D4, 0x0B);
	wportb(0x3D5, (rportb(0x3E0) & 0xE0) | cursor_end);
}

void update_cursor(int x, int y)
{
	uint16_t pos = y * VGA_WIDTH + x;
	wportb(0x3D4, 0x0F);
	wportb(0x3D5, (uint8_t) (pos & 0xFF));
	wportb(0x3D4, 0x0E);
	wportb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void screen_set_row(uint16_t row)
{
	screen_row = row;
	update_cursor(screen_column, screen_row);
}

void screen_set_column(uint16_t col)
{
	screen_column = col;
	update_cursor(screen_column, screen_row);
}

void screen_flush(void)
{
	for (uint16_t y = 0; y < VGA_HEIGHT; y++) {
		for (uint16_t x = 0; x < VGA_WIDTH; x++) {
			const uint16_t index = y * VGA_WIDTH + x;
			screen_buffer[index] = vga_entry(' ', screen_color);
		}
	}
}

void screen_scroll(void)
{
	uint16_t row;
	for (uint16_t y = 0; y < VGA_HEIGHT; y++) {
		row = y + 1;
		for (uint16_t x = 0; x < VGA_WIDTH; x++)
		{
			const uint16_t top_index = y * VGA_WIDTH + x;
			const uint16_t bottom_index = row * VGA_WIDTH + x;
			screen_buffer[top_index] = screen_buffer[bottom_index];
		}
	}
	for (uint16_t x = 0; x < VGA_WIDTH; x++)
	{
		const uint16_t index = VGA_HEIGHT * VGA_WIDTH + x;
		screen_buffer[index] = vga_entry(' ', screen_color);	
	}
}

uint16_t screen_get_row(void)
{
	return screen_row;
}

uint16_t screen_get_col(void)
{
	return screen_column;
}

