#include "../libc/include/stdio.h"
#include "../drivers/include/screen.h"
#include "../drivers/include/keyboard.h"
#include "../drivers/include/vga.h"
#include "cpu/include/pic.h"
#include "cpu/include/idt.h"


#define K_MAJOR_VERSION "0"
#define K_MINOR_VERSION "1"

extern void init_keyboard_handler(void);

void boot(void)
{
    init_pic();
    init_idt_pointer();
    load_idt_pointer();
    load_idt_entry(1, (uint32_t)init_keyboard_handler, 0x08, 0x8e);
    keyboard_init();
    screen_init();
}

void kernal_header(void)
{
    printf("################################################################################\n");    
    screen_setcolor(VGA_COLOR_GREEN);
    printf("     ___    __               \n");
    printf("    /   |  / /__  ____  ____ \n");
    printf("   / /| | / __  / __  / ___/ \n");
    printf("  / ___ |/ /_/ / /_/ (__  )  \n");
    printf(" /_/  |_/_.___/|____/____/   \n"); 
    printf("                             \n");
    screen_setcolor(VGA_COLOR_RED);
    printf("Version: ");
    printf(K_MAJOR_VERSION);
    printf(".");
    printf(K_MINOR_VERSION);
    screen_setcolor_default();
    printf("\n################################################################################\n");
}
int __attribute__((noreturn)) main() {
    boot();
    kernal_header();
    while(1);
}