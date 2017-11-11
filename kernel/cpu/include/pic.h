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
#include "../../libk/io/port_io.h"

static inline void init_pic(void)
{
    /* ICW1 - begin initialization */
    wportb(PIC1_COM, 0x11);
    wportb(PIC2_COM, 0x11);

    /* ICW2 - remap offset address of idt_table */
    /*
    * In x86 protected mode, we have to remap the PICs beyond 0x20 because
    * Intel have designated the first 32 interrupts as "reserved" for cpu exceptions
    */
    wportb(PIC1_DATA, 0x20);
    wportb(PIC2_DATA, 0x28);

    /* ICW3 - setup cascading */
    wportb(PIC1_DATA, 0x00);
    wportb(PIC2_DATA, 0x00);

    /* ICW4 - environment info */
    wportb(PIC1_DATA, 0x01);
    wportb(PIC2_DATA, 0x01);
    /* Initialization finished */

    /* mask interrupts */
    wportb(0x21 , 0xff);
    wportb(0xA1 , 0xff);
}

#endif