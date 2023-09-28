.model small
.stack 100h
.data
    ivesk db "Iveskite simboliu eilute:", 13, 10, "$"
    new_line db 13, 10, "$"
    buffer db 10, ?, 10 dup(0)
.code
Start:
    mov ax, @data
    mov ds, ax
    ;Prasome ivesti simboliu eilute
    mov ah, 09h
    mov dx, offset ivesk
    int 21h
    ;Nuskaitome simboliu eilute
    mov ah, 0Ah
    mov dx, offset buffer
    int 21h
    ;Pereinam i sekancia eilute
    mov ah, 09h
    mov dx, offset new_line
    int 21h

    mov ah, 4Ch
    int 21h
END Start