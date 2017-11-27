#include <stdint.h>
#include <kernel/cpu/idt.h>


extern void load_idt();

void idt_init_pointer()
{
    IDT_PTR.limit = (sizeof(struct IDT_ENTRY) * IDT_SIZE) - 1;
    IDT_PTR.base = (uint32_t)&IDT;
}

void idt_load_entry(uint8_t irq, uint32_t handler, uint16_t selector, uint8_t type_attr) {
    IDT[irq].offset_lowerbits = handler & 0xffff;
	IDT[irq].selector = selector; 
	IDT[irq].zero = 0;
	IDT[irq].type_attr = type_attr;
	IDT[irq].offset_higherbits = ((handler >> 16) & 0xffff);
}

void idt_load_table()
{
	idt_init_pointer();
	memset((void*)&IDT, 0, sizeof(struct IDT_ENTRY) * 256);
	load_idt();
}