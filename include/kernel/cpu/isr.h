#ifndef ISR_H
#define ISR_H

#include <kernel/cpu/idt.h>
#include <kernel/interrupt/interrupt.h>

//installs a irq handler
void irs_install_handler(int irs, void (*handler)(struct interrupt_struct *state));

//uninstalled a irq handler
void irs_uninstall_handler(int irs);

void isrs_install(void);


#endif