section .data
    width_val dq 0
    height_val dq 0
    pixels_ptr dq 0
    converted_ptr dq 0

section .text
bits 64
default rel
global imgCvtGrayIntToDouble

imgCvtGrayIntToDouble:

    ;; In asm, parameters are passed as the ff:
    ;; func(rcx, rdx, r8, r9, [stack])
    ;; where the first parameter is passed onto rcx, the second onto rdx,
    ;; the third onto r8, and the fourth onto r9.
    ;; Any additional parameters (5th, 6th, etc.) are passed on the stack.

    ;; Demo code for moving around the params
    mov [width_val], rcx ;; stores first parameter into width_val
    mov [height_val], rdx ;; stores second parameter into height_val
    mov al, byte [r8] ;; stores character in source array (index 0) to al
    mov [r9], al ;; stores character in al to index 0 of dest array
    ret

    ;; TODO:
    ;; Use XMM to store floating point values and store into r9
    ;; Use SIMD instructions to do the conversion from source to dest array