#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>
#include <stdbool.h>
#include <libc/stdio.h>
#include <kernel/interrupt/interrupt.h>

void init_terminal(uint16_t row);
void terminal_prompt(void);
void keyboard_input();
void run_command(void);

#endif
