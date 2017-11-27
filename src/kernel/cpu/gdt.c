#include <stdint.h>
#include <kernel/cpu/gdt.h>

extern void load_gdt();

void set_gdt_entry(uint16_t loc, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags) {
    GDT[loc].base_low = (base & 0xFFFF);
    GDT[loc].base_middle = ((base >> 16) & 0xFF);
    GDT[loc].base_high = ((base >> 24) & 0xFF);
    GDT[loc].limit_low = (limit & 0xFFFF);
    GDT[loc].flags = ((limit >> 16) & 0x0F);
    GDT[loc].access = access;
    GDT[loc].flags |= (flags & 0xF0);
}

void init_gdt(){

    GDT_ENTRY_PTR.size = (sizeof(struct GDT_ENTRY) * GDT_SIZE) - 1;
    GDT_ENTRY_PTR.base = (uint32_t)(&GDT);
    set_gdt_entry(0, 0, 0, 0, 0);
    set_gdt_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    set_gdt_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
    load_gdt();
}