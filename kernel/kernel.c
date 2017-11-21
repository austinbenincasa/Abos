#include <stdio.h>
#include "../drivers/include/screen.h"
#include "../drivers/include/keyboard.h"
#include "../drivers/include/vga.h"
#include "../terminal/terminal.h"
#include "cpu/include/pic.h"
#include "cpu/include/idt.h"
#include "cpu/include/gdt.h"
#include "cpu/include/irs.h"
#include "cpu/include/irq.h"




#define K_MAJOR_VERSION "0"
#define K_MINOR_VERSION "1"

extern void keyboard_handler();

void boot(void)
{   
    init_gdt();
    init_pic();
    idt_load_table();
    isrs_install();
    irqs_install();
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
int __attribute__((noreturn)) kmain() {
    boot();
    kernal_header();
    init_terminal(screen_get_row());
    while(1);
}