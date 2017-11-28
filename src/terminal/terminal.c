#include <stdint.h>
#include <stdbool.h>
#include <terminal/terminal.h>
#include <kernel/cpu/irq.h>
#include <kernel/interrupt/interrupt.h>
#include <libc/stdio.h>
#include <drivers/keyboard.h>



static uint16_t start_row;
static uint16_t current_col;
static int input_buff_index = 0;
static unsigned char input_buff[250];
int enter = 1;

void init_terminal(uint16_t row)
{
    irq_install_handler(1, keyboard_input);
    start_row = row;
    terminal_prompt();
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
    for(int i = 0; i < input_buff_index; i++)
    {
        putchar(input_buff[i]);
    }
    input_buff_index = 0;
    printf("\n");
}
