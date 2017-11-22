#ifndef IDT_H
#define IDT_H

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
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));


struct IDT_ENTRY IDT[IDT_SIZE];
struct IDT_POINTER IDT_PTR;

void idt_init_pointer(void);
void idt_load_entry(uint8_t irq, uint32_t handler, uint16_t selector, uint8_t type_attr);
void idt_load_table(void);

#endif