#ifndef PIC_H
#define PIC_H


// Master PIC
#define PIC1_COM 0x20
#define PIC1_DATA 0x21

// Slave PIC
#define PIC2_COM 0xA0
#define PIC2_DATA 0xA1

#define PIC_INIT 0x11 //ICW1
#define PIC_OFFSET 0x20 //ICW2

#define ICW4_8086	0x01		/* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO	0x02		/* Auto (normal) EOI */
#define ICW4_BUF_SLAVE	0x08		/* Buffered mode/slave */
#define ICW4_BUF_MASTER	0x0C		/* Buffered mode/master */
#define ICW4_SFNM	0x10		/* Special fully nested (not) */


#define PIB_EOI 0x20

#include <stdint.h>
#include <kernel/io/port_io.h>

void init_pic(void);

#endif