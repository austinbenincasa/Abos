#include <drivers/keyboard_map.h>
#include <drivers/keyboard.h>
#include <kernel/io/port_io.h>

extern unsigned char keyboard_map[128];

void keyboard_init(void)
{
    //enables irq 1
    wportb(0x21 , 0xFD);
}

unsigned char keyboard_handler(void)
{
    unsigned char status;
    signed char keycode;

    status = rportb(0x64);
    if (status & 0x01) {
        keycode = rportb(0x60);
        if(keycode >= 0 && keyboard_map[keycode]) {
            return keyboard_map[keycode];
        }
    }
    ///enable interrupts again
    wportb(0x20, 0x20);
    return 0;
} 