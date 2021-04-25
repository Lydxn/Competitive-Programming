; libc

section .data
        in3format db "%d %d %d", 0
        outformat db "%d", 10, 0

section .bss
        A resb 4
        B resb 4
        C resb 4

section .text
        global main
        extern scanf, printf
    
main:
        push C
        push B
        push A
        push in3format
        call scanf
        add esp, 16
        
        mov eax, [A]
        add eax, [B]
        add eax, [C]
        xor edx, edx
        mov ecx, 3
        div ecx

        push eax
        push outformat
        call printf
        add esp, 8
    
        xor eax, eax
        ret
