#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <libc/stdio.h>
#include <kernel/io/port_io.h>

void keyboard_init(void);
void keyboard_handler(void);

#endif