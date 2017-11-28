#ifndef PIT_H
#define PIT_H

#include <stdint.h>
#include <kernel/interrupt/interrupt.h>

void timer_phase(int hz);
void timer_handler(struct interrupt_struct *state);
void timer_install(void);
void timer_wait(int ticks);


#endif