section .data
    msor db "Entre com uma frase: ", 10
    tamor equ $-msor

section .data
     saida db "Sua mensagem é: ", 10
     len equ $-saida

segment .bss
    mentr resb 30
    tament resd 1

segment .text
    global _start
    
_start:
    
    ;imprime a msg pra entrar com a frase
    mov edx, tamor
    mov ecx, msor
    mov ebx, 1
    mov eax, 4
    int 80h
    
    ;recebe a string digitada do teclado
    mov edx, 30
    mov ecx, mentr
    mov ebx, 0
    mov eax, 3
    int 80h
    
    ;imprime uma msg falando qual é a msg digitada
    mov edx, len
    mov ecx, saida
    mov ebx, 1
    mov eax, 4
    int 80h
    
    ;immprime a msg digitada
    mov eax, 4
    mov ebx, 1
    mov ecx, mentr
    mov edx, 30
    int 80h
