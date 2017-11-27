#include <stdint.h>
#include "include/idt.h"


extern void load_idt();

void idt_init_pointer()
{
    IDT_PTR.limit = (sizeof(struct IDT_ENTRY) * IDT_SIZE) - 1;
    IDT_PTR.base = (uint32_t)&IDT;
}

void idt_load_entry(uint8_t irq, uint32_t handler, uint16_t selector, uint8_t type_attr) {
    uint8_t int_num = 0x20 + irq;
    IDT[int_num].offset_lowerbits = handler & 0xffff;
	IDT[int_num].selector = selector; 
	IDT[int_num].zero = 0;
	IDT[int_num].type_attr = type_attr;
	IDT[int_num].offset_higherbits = (handler & 0xffff0000) >> 16;
}

void idt_load_table()
{
	idt_init_pointer();
	memset((void*)&IDT, 0, sizeof(struct IDT_ENTRY) * 256);
	load_idt();
}