#ifndef ISR_H
#define ISR_H

#include <kernel/cpu/idt.h>
#include <kernel/interrupt/interrupt.h>

void isr_install_handler(int irs, void (*handler)(struct interrupt_struct *state));
void isr_uninstall_handler(int irs);
void isrs_install(void);


#endif