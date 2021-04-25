; libc

section .data
        informat   db "%d", 0
        out2format db "%d %d", 10, 0
        min        dd 128
        max        dd -127
    
section .bss
        N   resb 4
        num resb 4

section .text
        global main
        extern scanf, printf

%macro scanInt 2
        push %2
        push %1
        call scanf
        add esp, 8
%endmacro
    
main:
        scanInt informat, N
        mov ecx, [N]
        call _minMax
    
        push ebx
        push eax
        push out2format
        call printf
        add esp, 12
    
        xor eax, eax
        ret
    
_minMax:
        scanInt informat, num
        mov eax, [num]
    
        cmp eax, [min]
        jl _newMin
_nextMin:

        cmp eax, [max]
        jg _newMax
_nextMax:

        loop _minMax
        mov eax, [min]
        mov ebx, [max]
        ret
    
_newMin:
        mov [min], eax
        jmp _nextMin

_newMax:
        mov [max], eax
        jmp _nextMax
