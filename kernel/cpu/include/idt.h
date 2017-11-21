#ifndef IDT_H
#define IDT_H

#include <stdint.h>
#include "../../io/port_io.h"

#define IDT_SIZE 256

struct IDT_ENTRY{
	uint16_t offset_lowerbits;
	uint16_t selector;
	uint8_t zero;
	uint8_t type_attr;
	uint16_t offset_higherbits;
} __attribute__((packed));

struct IDT_POINTER
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));


struct IDT_ENTRY IDT[IDT_SIZE];
struct IDT_POINTER IDT_PTR;

extern void load_idt(void*);

static inline void idt_init_pointer(void)
{
    IDT_PTR.limit = (sizeof(struct IDT_ENTRY) * IDT_SIZE) - 1;
    IDT_PTR.base = (unsigned int)&IDT;
}

static inline void idt_load_entry(uint8_t irq, uint32_t handler, uint16_t selector, uint8_t type_attr) {
    uint8_t int_num = 0x20 + irq;
    IDT[int_num].offset_lowerbits = handler & 0xffff;
	IDT[int_num].selector = selector; 
	IDT[int_num].zero = 0;
	IDT[int_num].type_attr = type_attr;
	IDT[int_num].offset_higherbits = (handler & 0xffff0000) >> 16;
}

static inline void idt_load_table(void)
{
	//external call to kernel/idt.asm
	idt_init_pointer();
	load_idt(&IDT_PTR);
}
#endif