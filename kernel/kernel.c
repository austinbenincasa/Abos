#include "../drivers/include/screen.h"
#include "../drivers/include/vga.h"



#define K_MAJOR_VERSION 0
#define K_MINOR_VERSION 1

void boot(void)
{
    screen_init();
    //inits everything required for the kernel
}

void boot_image(void)
{
    screen_setcolor(VGA_COLOR_GREEN);
    screen_writestring("     ___    __               \n");
    screen_writestring("    /   |  / /__  ____  ____ \n");
    screen_writestring("   / /| | / __  / __  / ___/ \n");
    screen_writestring("  / ___ |/ /_/ / /_/ (__  )  \n");
    screen_writestring(" /_/  |_/_.___/|____/____/   \n"); 
    screen_writestring("                             \n");
    screen_setcolor_default();
}

int __attribute__((noreturn)) main() {
    boot();
    screen_writestring("####################################################\n");
    boot_image();
    screen_writestring("####################################################\n");
    while(1);
}