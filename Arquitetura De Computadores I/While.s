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
    ;exibe mensagem para entrar com uma frase
    mov eax, 4
    mov ebx, 1
    mov ecx, mens
    mov edx, tam
    int 80h
    
    mov eax, 3 ;ler do teclado
    mov ebx, 0
    mov ecx, b1
    mov edx, 500
    int 80h ; vai retornar o tamanho da escrita do teclado em eax
    mov esi, 0 ;index para varrer a string
    
iniloop:
    mov al,[b1+esi]
    mov [b2+esi],al
    cmp al, 10 ;compara para ver se o index já chegou no enter ou nao
    je sai ;se for igual pula para fora do loop
    inc esi ;incrementa o index
    jmp iniloop ;volta para o loop
sai:
    ;imprime a mensagem que foi transferia de b1 para b2
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
