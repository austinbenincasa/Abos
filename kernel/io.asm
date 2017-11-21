; This is for reading IO ports
bits 32
section .text

global rportb
global wportb
global rportl
global wportl


rportb:
    mov edx, [esp + 4]
    in al, dx
    ret

rportl:
    mov edx, [esp + 4]
    in eax, dx
    ret

wportb:
    mov edx, [esp + 4]
    mov al, [esp + 4 + 4]
    out dx, al
    ret

wportl:
    mov edx, [esp + 4]
    mov eax, [esp + 8]
    out dx, eax
    ret