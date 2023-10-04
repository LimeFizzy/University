.model small
.stack 100h
.data
    buffer db 100, ?, 100 dup(0)
    ivesk db "Iveskite simboliu eilute:", 13, 10, "$"
    new_line db 13, 10, "$"
    pranesimas db "Jusu ivesta eilute:", 13, 10, "$"
.code
Start:
    mov ax, @data
    mov ds, ax

    mov ah, 09h
    mov dx, offset ivesk
    int 21h

    mov ah, 0Ah
    mov dx, offset buffer
    int 21h

    mov ah, 09h
    mov dx, offset new_line
    int 21h

    mov dx, offset pranesimas
    int 21h

    mov si, offset buffer
    inc si

StartLoop:
    mov ax, 0
    inc si
    mov al, [ds:si]
    cmp al, 13
    JE Final
    
    mov dl, al
    mov ah, 2
    int 21h
    
    jmp StartLoop

Final:
    mov ah, 4Ch
    int 21h

END Start