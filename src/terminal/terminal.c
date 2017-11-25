#include <stdint.h>
#include <stdbool.h>
#include <terminal/terminal.h>
#include <libc/stdio.h>


static uint16_t start_row;
static uint16_t current_col;
static int input_buff_index = 0;
static char input_buff[250];

void init_terminal(uint16_t row)
{
    start_row = row;
    terminal_loop();
}
void terminal_loop(void)
{
    while(1)
    {
        //write prompt
        printf("prompt> ");
        bool enter = false;
        while(!enter)
        {
            //write input to cmd buffer
            
            //wait for enter
        }
        //run input
        run_command();

        //loop
    }
}
void run_command(void)
{
    printf("\n");
    printf(input_buff);
}
