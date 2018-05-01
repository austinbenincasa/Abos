#ifndef PORT_IO_H
#define PORT_IO_H

#include <stdint.h>

extern uint8_t rportb(uint16_t);
extern void wportb(uint16_t, uint8_t);

#endif
