#include <libc/stdio.h>
#include <drivers/screen.h>
#include <drivers/keyboard.h>
#include <drivers/vga.h>
#include <terminal/terminal.h>
#include <kernel/cpu/pic.h>
#include <kernel/cpu/idt.h>
#include <kernel/cpu/gdt.h>
#include <kernel/cpu/isr.h>
#include <kernel/cpu/irq.h>

#define K_MAJOR_VERSION "0"
#define K_MINOR_VERSION "1"

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