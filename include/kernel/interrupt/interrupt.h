#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stdint.h>
#include <libc/stdio.h>
#include <kernel/io/port_io.h>

static char *exception_messages[] =
{
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Overflow",
    "Bounds",
    "Invalid Opcode",
    "Coprocessor not available",
    "Double fault",
    "Coprocessor Segment Overrun",
    "Invalid Task State Segment",
    "Segment not present",
    "Stack Fault",
    "General protection fault",
    "Page Fault",
    "Unknown interrupt exception",
    "Coprocessor fault",
    "Alignment check exception",
    "Machine check exception",
    "Reserved Fault",
    "Reserved Fault",
    "Reserved Fault",
    "Reserved Fault",
    "Reserved Fault",
    "Reserved Fault",
    "Reserved Fault",
    "Reserved Fault",
    "Reserved Fault",
    "Reserved Fault",
    "Reserved Fault",
    "Reserved Fault",
    "Reserved Fault",
    "Reserved Fault"            
};

struct segments
{
    unsigned int gs, fs, es, ds;
}__attribute__((packed));

struct cpu_state
{
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
}__attribute__((packed));

struct interrupt_error
{
    unsigned int int_no, error_code;
}__attribute__((packed));

struct stack_state
{
    unsigned int eip, cs, eflags, useresp, ss;
}__attribute__((packed));

struct interrupt_struct
{
    struct segments segs;
    struct cpu_state cpu;
    struct interrupt_error error;
    struct stack_state stack;
}__attribute__((packed));

//void interrupt_handler(struct stack_state *stack, struct interrupt_error *err, struct cpu_state *cpu, struct segments *seg);
void interrupt_handler(struct interrupt_struct *state);



#endif