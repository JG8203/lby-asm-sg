section .data
    msg db "Hello World", 13, 10, 0  ; Message with carriage return, line feed, and null terminator

section .text
bits 64
default rel                          ; to handle address relocation
global asmhello                      ; make the function visible to linker
extern printf                        ; declare the C function we'll call

asmhello:
    sub rsp, 8*5                     ; allocate shadow space for Windows x64 calling convention
    lea rcx, [msg]                   ; first parameter for printf
    call printf                      ; call C printf function
    add rsp, 8*5                     ; restore stack
    ret