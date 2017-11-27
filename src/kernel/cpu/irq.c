#include <kernel/cpu/irq.h>
#include <kernel/cpu/idt.h>
#include <kernel/interrupt/interrupt.h>


extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();


//holds function pointers to the irq handlers
void *irq_handlers[16] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

//installs a irq handler
void irq_install_handler(int irq, void (*handler)(struct interrupt_struct *state))
{
    irq_handlers[irq] = handler;
}

//uninstalled a irq handler
void irq_uninstall_handler(int irq)
{
    irq_handlers[irq] = 0;
}

void irqs_install()
{
    //load intel interrupts
    idt_load_entry(32, (unsigned)irq0, 0x08, 0x8E);
    idt_load_entry(33, (unsigned)irq1, 0x08, 0x8E);
    idt_load_entry(34, (unsigned)irq2, 0x08, 0x8E);
    idt_load_entry(35, (unsigned)irq3, 0x08, 0x8E);
    idt_load_entry(36, (unsigned)irq4, 0x08, 0x8E);
    idt_load_entry(37, (unsigned)irq5, 0x08, 0x8E);
    idt_load_entry(38, (unsigned)irq6, 0x08, 0x8E);
    idt_load_entry(39, (unsigned)irq7, 0x08, 0x8E);
    idt_load_entry(40, (unsigned)irq8, 0x08, 0x8E);
    idt_load_entry(41, (unsigned)irq9, 0x08, 0x8E);
    idt_load_entry(42, (unsigned)irq10, 0x08, 0x8E);
    idt_load_entry(43, (unsigned)irq11, 0x08, 0x8E);
    idt_load_entry(44, (unsigned)irq12, 0x08, 0x8E);
    idt_load_entry(45, (unsigned)irq13, 0x08, 0x8E);
    idt_load_entry(46, (unsigned)irq14, 0x08, 0x8E);
    idt_load_entry(47, (unsigned)irq15, 0x08, 0x8E);
}