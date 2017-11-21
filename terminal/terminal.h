#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

void init_terminal(uint16_t row);
void terminal_loop(void);
void run_command(void);

#endif
