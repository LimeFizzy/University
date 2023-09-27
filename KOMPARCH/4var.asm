.model small

.stack 100h

.data
    ivesk db "Iveskite simboliu eilute:"
    enter db 10, 13, "$"
    buferis db 255
    
.code
Start:
    mov ax, @data
    mov ds, ax
    ;Prasome ivesti simboliu eilute
    mov ah, 9
    mov dx, offset ivesk
    int 21h
    ;nuskaitome simboliu eilute
    mov ah, 0Ah
    mov dx, offset buferis
    int 21h
    

    mov ah, 4Ch
    int 21h
END Start