#include <stdint.h>

void screen_init(void);
void screen_setcolor(uint8_t color);
void screen_putentryat(unsigned char c, uint8_t color, uint16_t x, uint16_t y);
void screen_putchar(char c);
void screen_write(const char* data, uint8_t size);
void screen_writestring(const char* data);
void screen_setcolor_default();