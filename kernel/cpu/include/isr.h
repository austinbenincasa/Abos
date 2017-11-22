#ifndef ISR_H
#define ISR_H

#include "../../interrupt/include/interrupt.h"


void isr_install_handler(int isr, void (*handler)(struct interrupt_struct *state));
void isr_uninstall_handler(int isr);
void isrs_install(void);

#endif
