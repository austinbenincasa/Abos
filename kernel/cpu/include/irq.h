#ifndef IRQ_H
#define IRQ_H

#include "../../interrupt/include/interrupt.h"

void irq_install_handler(int irq, void (*handler)(struct interrupt_struct *state));
void irq_uninstall_handler(int irq);
void irqs_install(void);

#endif