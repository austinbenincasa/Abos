#include <stdint.h>
#include "include/gdt.h"

extern void load_gdt();


void set_gdt_entry(uint16_t loc, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags) {
    GDT[loc].base_low = (base & 0xFFFF);
    GDT[loc].base_middle = ((base >> 16) & 0xFF);
    GDT[loc].base_high = ((base >> 24) & 0xFF);

    GDT[loc].limit_low = (limit & 0xFFFF);
    GDT[loc].flags = ((limit >> 16) & 0x0F);


    // Ensure present flag is set
    access |= 0x90;
    // Ensure access flag is cleared
    access &= 0xFE;

    GDT[loc].access = access;
    GDT[loc].flags |= (flags & 0x0F);
}

void init_gdt(){

    GDT_ENTRY_PTR.size = (sizeof(struct GDT_ENTRY) * GDT_SIZE) - 1;
    GDT_ENTRY_PTR.base = (uint32_t)(&GDT);

    set_gdt_entry(0, 0, 0, 0, 0);
    set_gdt_entry(1, 0, 0xFFFFFFFF, GDT_RING_0 | GDT_EXEC | GDT_EXEC_READABLE, GDT_GRAN_4KB | GDT_SIZE_32);
    set_gdt_entry(2, 0, 0xFFFFFFFF, GDT_RING_0 | GDT_DATA | GDT_DATA_WRITEABLE, GDT_GRAN_4KB | GDT_SIZE_32);

}