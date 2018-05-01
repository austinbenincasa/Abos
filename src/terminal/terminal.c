#include <stdint.h>
#include <stdbool.h>
#include <terminal/terminal.h>
#include <kernel/cpu/irq.h>
#include <kernel/interrupt/interrupt.h>
#include <libc/stdio.h>
#include <drivers/keyboard.h>
#include <drivers/vga.h>


static int input_buff_index = 0;
static unsigned char input_buff[250];

void init_terminal()
{
    irq_install_handler(1, keyboard_input);
    terminal_header();
    terminal_prompt();
}

void terminal_header(void)
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

void terminal_prompt(void)
{
    printf("prompt> ");
}

void keyboard_input(struct interrupt_struct *state)
{
    unsigned char key = keyboard_handler();
    if (key == '\b')
    {
        if(input_buff_index > 0)
        {
            input_buff_index--;
            putchar(key);
        }
    }
    else if (key == '\n')
    {
        putchar(key);
        run_command();
        terminal_prompt();
        input_buff_index = 0;
    }
    else if(key != 0)
    {
        input_buff[input_buff_index] = key;
        input_buff_index++;
        putchar(key);
    }

}

void run_command(void)
{

    printf(input_buff);
    printf("\n");
    
}
