#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "../../libc/include/stdio.h"
#include "../../kernel/libk/io/port_io.h"

void keyboard_init(void);
void keyboard_handler(void);

#endif