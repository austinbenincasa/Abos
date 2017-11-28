#ifndef PIC_H
#define PIC_H


// Master PIC
#define PIC1_COM 0x20
#define PIC1_DATA 0x21

// Slave PIC
#define PIC2_COM 0xA0
#define PIC2_DATA 0xA1


#define PIB_EOI 0x20

#include <stdint.h>
#include <kernel/io/port_io.h>

void init_pic(void);

#endif