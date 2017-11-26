#include "include/isr.h"
#include "include/idt.h"
#include "../interrupt/include/interrupt.h"


extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

void *isr_handlers[32] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

//installs a irq handler
void isr_install_handler(int isr, void (*handler)(struct interrupt_struct *state))
{
    isr_handlers[isr] = handler;
}

//uninstalled a irq handler
void isr_uninstall_handler(int isr)
{
    isr_handlers[isr] = 0;
}

void isrs_install()
{
    //load intel interrupts
    idt_load_entry(0, (unsigned)isr0, 0x08, 0x8E);
    idt_load_entry(1, (unsigned)isr1, 0x08, 0x8E);
    idt_load_entry(2, (unsigned)isr2, 0x08, 0x8E);
    idt_load_entry(3, (unsigned)isr3, 0x08, 0x8E);
    idt_load_entry(4, (unsigned)isr4, 0x08, 0x8E);
    idt_load_entry(5, (unsigned)isr5, 0x08, 0x8E);
    idt_load_entry(6, (unsigned)isr6, 0x08, 0x8E);
    idt_load_entry(7, (unsigned)isr7, 0x08, 0x8E);
    idt_load_entry(8, (unsigned)isr8, 0x08, 0x8E);
    idt_load_entry(9, (unsigned)isr9, 0x08, 0x8E);
    idt_load_entry(10, (unsigned)isr10, 0x08, 0x8E);
    idt_load_entry(11, (unsigned)isr11, 0x08, 0x8E);
    idt_load_entry(12, (unsigned)isr12, 0x08, 0x8E);
    idt_load_entry(13, (unsigned)isr13, 0x08, 0x8E);
    idt_load_entry(14, (unsigned)isr14, 0x08, 0x8E);
    idt_load_entry(15, (unsigned)isr15, 0x08, 0x8E);
    idt_load_entry(16, (unsigned)isr16, 0x08, 0x8E);
    idt_load_entry(17, (unsigned)isr17, 0x08, 0x8E);
    idt_load_entry(18, (unsigned)isr18, 0x08, 0x8E);
    idt_load_entry(19, (unsigned)isr19, 0x08, 0x8E);
    idt_load_entry(20, (unsigned)isr20, 0x08, 0x8E);
    idt_load_entry(21, (unsigned)isr21, 0x08, 0x8E);
    idt_load_entry(22, (unsigned)isr22, 0x08, 0x8E);
    idt_load_entry(23, (unsigned)isr23, 0x08, 0x8E);
    idt_load_entry(24, (unsigned)isr24, 0x08, 0x8E);
    idt_load_entry(25, (unsigned)isr25, 0x08, 0x8E);
    idt_load_entry(26, (unsigned)isr26, 0x08, 0x8E);
    idt_load_entry(27, (unsigned)isr27, 0x08, 0x8E);
    idt_load_entry(28, (unsigned)isr28, 0x08, 0x8E);
    idt_load_entry(29, (unsigned)isr29, 0x08, 0x8E);    
    idt_load_entry(30, (unsigned)isr30, 0x08, 0x8E);
    idt_load_entry(31, (unsigned)isr31, 0x08, 0x8E);
}