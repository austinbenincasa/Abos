#include <stdint.h>
#include <kernel/cpu/irq.h>
#include <kernel/cpu/pit.h>
#include <kernel/interrupt/interrupt.h>
#include <kernel/io/port_io.h>
#include <libc/stdio.h>

unsigned long timer_ticks = 0;

void timer_phase(int hz)
{
    int divisor = 1193180 / hz;
    wportb(0x43, 0x36);
    wportb(0x40, divisor & 0xFF);
    wportb(0x40, (divisor >> 8) & 0xFF);
}

void timer_handler(struct interrupt_struct *state)
{
    //increment timer
    timer_ticks++;
    
    //if one second has passed
    if (timer_ticks % 100 == 0)
    {
        //do something with this later
    }
}

void timer_wait(int ticks)
{
    unsigned long eticks;
    eticks = timer_ticks + ticks;
    while(timer_ticks < eticks);
}

void timer_install()
{
    irq_install_handler(0, timer_handler);
    timer_phase(100);
}