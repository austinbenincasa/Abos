#ifndef GDT_H
#define GDT_H

#define GDT_SIZE 3

#define GDT_RING_0 0x00
#define GDT_RING_3 0x60
#define GDT_EXEC 0x08
#define GDT_DATA 0x00
#define GDT_DATA_GROW_UP 0x04
#define GDT_EXEC_CONFORMING 0x04
#define GDT_DATA_WRITEABLE 0x02
#define GDT_EXEC_READABLE 0x02

#define GDT_GRAN_4KB 0x8F
#define GDT_GRAN_1B 0x0F

#define GDT_SIZE_16 0x0F
#define GDT_SIZE_32 0x4F

#include <stdint.h>

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

void set_gdt_entry(uint16_t loc, uint32_t base, uint32_t limit, uint8_t access, uint8_t flags);
void init_gdt();

#endif //GDT_H