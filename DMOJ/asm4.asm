; features: libc

section .data
        in3format db "%d %d %d", 0
        outformat db "%d", 10, 0

section .bss
        N resb 8
        P resb 8
        M resb 8

section .text
        global main
        extern scanf, printf

main:
        push rbp

        mov rdi, in3format
        mov rsi, N
        mov rdx, P
        mov rcx, M
        xor rax, rax
        call scanf

        call _powmod
        
        mov rdi, outformat
        mov rsi, rax
        xor al, al
        call printf

        pop rbp
        xor rax, rax
        ret

_powmod:
        mov rax, 1

_loop:
        mov rbx, [P]
        and rbx, 1
        cmp rbx, 1
        je _if
        jmp _next

_if:
        mov rbx, [N]
        mul rbx
        mov rbx, [M]
        xor rdx, rdx
        div rbx
        mov rax, rdx
        
_next:
        mov rbx, [P]
        shr rbx, 1
        mov [P], rbx

        push rax
        mov rax, [N]
        mul rax
        mov rbx, [M]
        xor rdx, rdx
        div rbx
        mov [N], rdx
        pop rax

        mov rbx, [P]
        cmp rbx, 0
        jg _loop
        
        ret
