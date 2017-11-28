#include <terminal/terminal.h>
#include <kernel/cpu/pic.h>
#include <kernel/cpu/idt.h>
#include <kernel/cpu/gdt.h>
#include <kernel/cpu/isr.h>
#include <kernel/cpu/irq.h>
#include <kernel/cpu/pit.h>


void boot(void)
{   
    init_gdt();
    init_pic();
    idt_load_table();
    isrs_install();
    irqs_install();
    timer_install();
    keyboard_init();
    screen_init();
}

int __attribute__((noreturn)) kmain() {
    boot();
    init_terminal();
    while(1);
}