section .data
    mens db 'Entre com uma frase: ', 10 
    tam equ $-mens

segment .bss
    b1 resb 500
    
segment .bss
    b2 resb 500

    
section .text
    global _start    


_start:
    ;exibe uma mensagem para o usuário entrar com uma frase
    mov eax, 4
    mov ebx, 1
    mov ecx, mens
    mov edx, tam
    int 80h
    
    mov eax, 3 ;ler do teclado
    mov ebx, 0 
    mov ecx, b1
    mov edx, 500 ;guarda o tamanho da string digitada
    int 80h ; vai retornar o tamanho da escrita do teclado em eax
    mov esi, 0 ;index para andar pela string
    
iniloop:
    mov al,[b1+esi] ;transfere para o registrador al
    mov [b2+esi],al ;transfere para string2 o char da string1
    cmp esi, edx ;compara o index para ver se já chegou ao final
    je sai ;se já chegou ele vai para fora do loop
    inc esi ;incrementa o index para ir pra próxima posição da string
    jmp iniloop ;volta para o inicio do loop
sai:
    ;exibe a mensagem que foi transferida pra string2 
    mov eax, 4
    mov ebx, 1
    mov ecx, b2
    inc esi
    mov edx, esi
    int 80h
    
    ;fim
    mov eax, 1
    mov ebx, 0
    int 80h
