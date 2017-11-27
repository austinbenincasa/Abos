bits 32
section .text


extern GDT_ENTRY_PTR
extern IDT_PTR
global load_idt
global load_gdt

load_idt:
	lidt [IDT_PTR]
    sti
	ret

load_gdt:
    lgdt [GDT_ENTRY_PTR]
    mov ax, 0x10
    jmp 0x08:reload_cs

reload_cs:
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret