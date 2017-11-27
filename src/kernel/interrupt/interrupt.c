#include <stdint.h>
#include <kernel/interrupt/interrupt.h>
#include <libc/stdio.h>
#include <kernel/io/port_io.h>
#include <drivers/keyboard.h>

void interrupt_handler(struct interrupt_struct *state)
{   

    //void (*handler)(struct interrupt_struct *state);

    if (state->error.int_no < 31)
    {
        printf(exception_messages[state->error.int_no]);
        printf(" Exception. System Halted!\n");
        for (;;);
    }
    if (state->error.int_no == 33)
    {
        keyboard_handler();
    }

    /* If the IDT entry that was invoked was greater than 40
    *  (meaning IRQ8 - 15), then we need to send an EOI to
    *  the slave controller */
    if (state->error.int_no >= 40)
    {
        wportb(0xA0, 0x20);
    }

    /* In either case, we need to send an EOI to the master
    *  interrupt controller too */
    wportb(0x20, 0x20);
}