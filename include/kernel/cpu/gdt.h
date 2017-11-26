#ifndef GDT_H
#define GDT_H


#define GDT_SIZE 3

struct GDT_ENTRY
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t flags;
    uint8_t base_high;
} __attribute__((packed));

struct GDT_PTR
{
    uint16_t size;
    uint32_t base;
} __attribute__((packed));

struct GDT_ENTRY GDT[GDT_SIZE];
struct GDT_PTR GDT_ENTRY_PTR;

void init_gdt(void);
void set_gdt_entry(uint16_t loc, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags);

#endif