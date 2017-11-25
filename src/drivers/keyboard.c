#include <drivers/keyboard_map.h>
#include <drivers/keyboard.h>
#include <kernel/io/port_io.h>

extern unsigned char keyboard_map[128];

void keyboard_init(void)
{
    /* 0xFD is 11111101 - enables only IRQ1 (keyboard)*/
    wportb(0x21 , 0xFD);
}

void keyboard_handler(void)
{
    unsigned char status;
    signed char keycode;

    /* Acknowledgment */
    status = rportb(0x64);
    /* Lowest bit of status will be set if buffer is not empty */
    if (status & 0x01) {
        keycode = rportb(0x60);
        /* Only alert characters on keydown event that have
         * a non-zero mapping */
        if(keycode >= 0 && keyboard_map[keycode]) {
            putchar(keyboard_map[keycode]);
            //call kernel event
        }
    }

    /* enable interrupts again */
    wportb(0x20, 0x20);
} 