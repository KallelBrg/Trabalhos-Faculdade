section .text

mens db 'Hello World', 0xa ;(0xa ou 10 quebra de linha)
len equ $-mens			; calcula o tamanho da string


global _start

_start:
    
    mov edx, len ;quantidade de elementos / operando imediato
    mov ecx, mens ; ponteiro da string  / operando imediato
    mov ebx, 1 ;descritor de arquivo que manda para a tela(pode mandar para outros lugares alem da tela diferente 1) / operando imediato
    mov eax, 4 ;monitor / operando imediato
    int 80h   ;chama kernel / operando imediato
    
    mov eax, 1 ; EXIT
    mov ebx, 0 ; return
    int 80h ; encerra
    
    ;nasm -f elf64 nada.s
    ;ld nada.o -o nada
    ;./nada
