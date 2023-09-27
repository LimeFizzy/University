.model small

.stack 100h

.data

.code
Start:
    mov ax, @data
    mov ds, ax

    ;pirmo skaiciaus nuskaitymas
    mov ah, 1
    int 21h
    sub al, 30h
    mov bl, al

    ;antro skaiciaus nuskaitymas
    int 21h
    sub al, 30h
    
    add al, bl
    
    mov ah, 0          ;isvalom ah
    mov cl, 10         ;issaugom dalykli
    div cl             ; al = al/cl    ir ah = ah%cl
    add al, 30h        ;atgal i ASCII
    add ah, 30h

    mov bl, al
    mov bh, ah

    cmp bl, '0'
    je WithoutTens

    mov ah, 2
    mov dl, bl
    int 21h

WithoutTens:
    mov ah, 2
    mov dl, bh
    int 21h

    mov	ah, 4Ch
    int 21h

END Start