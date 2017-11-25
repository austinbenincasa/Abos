bits 32

section .text
extern interrupt_handler

; ISR Definitions
global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31

;hardware interrupt
global irq0
global irq1
global irq2
global irq3
global irq4
global irq5
global irq6
global irq7
global irq8
global irq9
global irq10
global irq11
global irq12
global irq13
global irq14
global irq15


;  0: Divide By Zero Exception
isr0:
    cli
    push byte 0
    push byte 0
    jmp base_stub

;  1: Debug Exception
isr1:
    cli
    push byte 0
    push byte 1
    jmp base_stub

;  2: Non Maskable Interrupt Exception
isr2:
    cli
    push byte 0
    push byte 2
    jmp base_stub

;  3: Breakpoint
isr3:
    cli
    push byte 0
    push byte 3
    jmp base_stub

;  4: Bounds
isr4:
    cli
    push byte 0
    push byte 4
    jmp base_stub

;  5: Coprocessor not available
isr5:
    cli
    push byte 0
    push byte 5
    jmp base_stub

;  6: Invalid Opcode
isr6:
    cli
    push byte 0
    push byte 6
    jmp base_stub

;  7: Coprocessor not available
isr7:
    cli
    push byte 0
    push byte 7
    jmp base_stub

;  8: Double Fault
isr8:
    cli
    push byte 8
    jmp base_stub

;  9: Coprocessor Segment Overrun
isr9:
    cli
    push byte 0
    push byte 9
    jmp base_stub

;  10: Coprocessor Segment Overrun
isr10:
    cli
    push byte 10
    jmp base_stub

;  11: Invalid Task State Segment
isr11:
    cli
    push byte 11
    jmp base_stub

;  12: Segment not present
isr12:
    cli
    push byte 12
    jmp base_stub

;  13: Stack Fault
isr13:
    cli
    push byte 13
    jmp base_stub

;  14: General protection fault
isr14:
    cli
    push byte 14
    jmp base_stub

;  15: Page Fault
isr15:
    cli
    push 0
    push byte 15
    jmp base_stub

;  16: Unknown interrupt exception
isr16:
    cli
    push 0
    push byte 16
    jmp base_stub
    
;  17: Coprocessor fault
isr17:
    cli
    push 0
    push byte 17
    jmp base_stub

;  18: Alignment check exception
isr18:
    cli
    push 0
    push byte 18
    jmp base_stub

;  19: Machine check exception
isr19:
    cli
    push 0
    push byte 19
    jmp base_stub

;  20: Reserved
isr20:
    cli
    push 0
    push byte 20
    jmp base_stub

;  21: Reserved
isr21:
    cli
    push 0
    push byte 21
    jmp base_stub

;  22: Reserved
isr22:
    cli
    push 0
    push byte 22
    jmp base_stub

;  23: Reserved
isr23:
    cli
    push 0
    push byte 23
    jmp base_stub

;  24: Reserved
isr24:
    cli
    push 0
    push byte 24
    jmp base_stub

;  25: Reserved
isr25:
    cli
    push 0
    push byte 25
    jmp base_stub

;  26: Reserved
isr26:
    cli
    push 0
    push byte 26
    jmp base_stub

;  27: Reserved
isr27:
    cli
    push 0
    push byte 27
    jmp base_stub

;  28: Reserved
isr28:
    cli
    push 0
    push byte 28
    jmp base_stub

;  29: Reserved
isr29:
    cli
    push 0
    push byte 29
    jmp base_stub

;  30: Reserved
isr30:
    cli
    push 0
    push byte 30
    jmp base_stub

;  31: Reserved
isr31:
    cli
    push 0
    push byte 31
    jmp base_stub


irq0:
    cli
    push byte 0
    push byte 32
    jmp base_stub

irq1:
    cli
    push byte 0
    push byte 33
    jmp base_stub

irq2:
    cli
    push byte 0
    push byte 34
    jmp base_stub

irq3:
    cli
    push byte 0
    push byte 35
    jmp base_stub

irq4:
    cli
    push byte 0
    push byte 36
    jmp base_stub

irq5:
    cli
    push byte 0
    push byte 37
    jmp base_stub

irq6:
    cli
    push byte 0
    push byte 38
    jmp base_stub

irq7:
    cli
    push byte 0
    push byte 39
    jmp base_stub

irq8:
    cli
    push byte 0
    push byte 40
    jmp base_stub

irq9:
    cli
    push byte 0
    push byte 41
    jmp base_stub

irq10:
    cli
    push byte 0
    push byte 42
    jmp base_stub

irq11:
    cli
    push byte 0
    push byte 43
    jmp base_stub

irq12:
    cli
    push byte 0
    push byte 44
    jmp base_stub

irq13:
    cli
    push byte 0
    push byte 45
    jmp base_stub

irq14:
    cli
    push byte 0
    push byte 46
    jmp base_stub

irq15:
    cli
    push byte 0
    push byte 47
    jmp base_stub

; This saves the processor state, sets
; up for kernel mode segments, calls the C-level fault handler,
; and finally restores the stack frame.
base_stub:
    pusha
    push ds
    push es
    push fs
    push gs
    mov ax, 0x10   ; Load the Kernel Data Segment descriptor!
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov eax, esp   ; Push us the stack
    push eax
    mov eax, interrupt_handler
    call eax       ; A special call, preserves the 'eip' register
    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp, 8     ; Cleans up the pushed error code and pushed ISR number
    iret       
