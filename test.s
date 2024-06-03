section .text
global _start
_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, msg
    mov edx, msg_len
    int 0x80

    mov eax, 1
    mov ebx, 42
    int 0x80

section .data

msg: db "Hello World!", 10
msg_len: equ $ - msg