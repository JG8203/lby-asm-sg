section .data
    align 16
    float255 dd 255.0, 255.0, 255.0, 255.0    ; Constant for division

section .text
bits 64
default rel
global imgCvtGrayIntToDouble

; Function parameters (Windows x64 calling convention):
; rcx = height
; rdx = width
; r8 = source array pointer (int*)
; r9 = destination array pointer (float*)
imgCvtGrayIntToDouble:
    ; Preserve registers
    push rbp
    mov rbp, rsp
    push rbx
    push r12
    push r13
    push r14
    
    ; Store parameters in preserved registers
    mov r12, rcx        ; height
    mov r13, rdx        ; width
    mov r14, r8         ; source pointer
    mov rbx, r9         ; destination pointer
    
    ; Calculate total elements (height * width)
    mov rax, r12
    mul r13
    mov r12, rax        ; Store total count in r12
    
    ; Load 255.0 into xmm4 for division
    movaps xmm4, [float255]
    
    ; Initialize counter
    xor rcx, rcx        ; rcx = 0
    
.loop:
    ; Check if we have at least 4 elements remaining
    mov rax, r12
    sub rax, rcx
    cmp rax, 4
    jl .remainder
    
    ; Process 4 integers at a time using SIMD
    movdqu xmm0, [r14 + rcx*4]    ; Load 4 ints
    cvtdq2ps xmm0, xmm0           ; Convert to floats
    divps xmm0, xmm4              ; Divide by 255.0
    movups [rbx + rcx*4], xmm0    ; Store result
    
    ; Increment counter by 4
    add rcx, 4
    jmp .loop
    
.remainder:
    ; Handle remaining elements
    cmp rcx, r12
    jge .done
    
    ; Process one element at a time
    cvtsi2ss xmm0, dword [r14 + rcx*4]  ; Convert int to float
    divss xmm0, dword [float255]        ; Divide by 255.0
    movss [rbx + rcx*4], xmm0           ; Store result
    
    inc rcx
    jmp .remainder
    
.done:
    ; Restore registers
    pop r14
    pop r13
    pop r12
    pop rbx
    pop rbp
    ret