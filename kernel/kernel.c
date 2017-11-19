#include <stdio.h>
#include "../drivers/include/screen.h"
#include "../drivers/include/keyboard.h"
#include "../drivers/include/vga.h"
#include "../terminal/terminal.h"
#include "cpu/include/pic.h"
#include "cpu/include/idt.h"
#include "cpu/include/gdt.h"


#define K_MAJOR_VERSION "0"
#define K_MINOR_VERSION "1"

extern void keyboard_event(void);

void boot(void)
{
    init_pic();
    init_gdt();
    idt_init_pointer();
    idt_load_table();
    idt_load_entry(1, (uint32_t)keyboard_event, 0x08, 0x8e);
    keyboard_init();
    screen_init();
}

void kernal_header(void)
{
    screen_setcolor(VGA_COLOR_DARK_GREY);
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
    screen_setcolor(VGA_COLOR_DARK_GREY);
    printf("\n################################################################################\n");
    screen_setcolor_default();
}
int __attribute__((noreturn)) main() {
    boot();
    kernal_header();
    init_terminal(screen_get_row());
    while(1);
}