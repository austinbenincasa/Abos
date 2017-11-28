#include <stdint.h>
#include <kernel/interrupt/interrupt.h>
#include <libc/stdio.h>
#include <kernel/io/port_io.h>
#include <kernel/cpu/isr.h>
#include <kernel/cpu/irq.h>

extern irq_handlers[];
extern isr_handlers[];

void interrupt_handler(struct interrupt_struct *state)
{   

    void (*handler)(struct interrupt_struct *state);

    if (state->error.int_no < 31)
    {
        int isr = state->error.int_no;
        handler = isr_handlers[isr];
        if (handler)
        {
            handler(state);
        }
        else{
            printf(exception_messages[state->error.int_no]);
            printf(" Exception. System Halted!\n");
            for (;;);
        }
    }
    if (state->error.int_no > 31)
    {
        int irq = state->error.int_no - 32;
        handler = irq_handlers[irq];
        if (handler)
        {
            handler(state);
        }
    }

    if (state->error.int_no >= 40)
    {
        wportb(0xA0, 0x20);
    }

    //EOI to the master)
    wportb(0x20, 0x20);
}