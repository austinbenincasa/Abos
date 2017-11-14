section .text


extern GDT_ENTRY_PTR
global load_idt
global load_gdt

load_idt:
	mov edx, [esp + 4]
	lidt [edx]
	sti
	ret

load_gdt:
    lgdt [GDT_ENTRY_PTR]
    mov ax, 0x10
    jmp 0x8:reload_cs

reload_cs:
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret