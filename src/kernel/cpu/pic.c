#include <stdint.h>
#include <kernel/cpu/pic.h>
#include <kernel/io/port_io.h>


#define PIC1_COM 0x20
#define PIC1_DATA 0x21

#define PIB_EOI 0x20


void init_pic()
{
 
    wportb(PIC1_COM, 0x11);
    wportb(PIC2_COM, 0x11);

    wportb(PIC1_DATA, 0x20);
    wportb(PIC2_DATA, 0x28);

    wportb(PIC1_DATA, 0x04);
    wportb(PIC2_DATA, 0x02);

    wportb(PIC1_DATA, 0x01);
    wportb(PIC2_DATA, 0x01);
    
}