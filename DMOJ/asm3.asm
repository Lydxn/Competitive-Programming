; libc

section .data
    informat    db "%d", 0
    outformat   db "%d", 10, 0
    A times 100 dd 0
    min         dd 1000
    max         dd -1000

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
    xor ecx, ecx
    mov esi, A
    call _minus

    push eax
    push outformat
    call printf
    add esp, 8
    
    xor eax, eax
    ret
    
_minus:
    push ecx
    scanInt informat, num
    pop ecx
    mov eax, [num]
    mov [esi + ecx * 4], eax

    inc ecx
    cmp ecx, [N]
    jl _minus

    dec dword[N]
    xor ecx, ecx
    
_loopMinMax:
    mov eax, [esi + ecx * 4]
    xor eax, [esi + ecx * 4 + 4]

    cmp eax, [min]
    jl _newMin
_nextMin:

    cmp eax, [max]
    jg _newMax
_nextMax:

    inc ecx
    cmp ecx, [N]
    jl _loopMinMax
    
    mov eax, [max]
    sub eax, [min]
    ret
    
_newMin:
    mov [min], eax
    jmp _nextMin
    
_newMax:
    mov [max], eax
    jmp _nextMax
