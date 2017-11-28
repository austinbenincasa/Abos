#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>
#include <stdbool.h>
#include <libc/stdio.h>
#include <kernel/interrupt/interrupt.h>

#define K_MAJOR_VERSION "0"
#define K_MINOR_VERSION "1"

void init_terminal();
void terminal_prompt(void);
void keyboard_input(struct interrupt_struct *state);
void run_command(void);
void terminal_header(void);


#endif
