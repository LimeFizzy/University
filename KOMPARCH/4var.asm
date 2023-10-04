.model small
.stack 100h
.data
    ivesk db "Iveskite simboliu eilute:", 13, 10, "$"
    wrong_input db "Netinkama ivestis.", 13, 10, "$"
    new_line db 13, 10, "$"
    space db " ", "$"
    buffer db 100, ?, 100 dup(0)
	notification db "Ivestu simboliu ASCII kodai:", 13, 10, "$"
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
	
	mov dx, offset notification
	int 21h
	
    mov si, offset buffer
    add si, 1             

StartLoop:
    inc si
    mov ax, 0
    mov al, [ds:si]
    cmp al, 13
    JE Final
    mov dx, 0
    cmp al, 32
    JB Error
	JE SpaceWrite
    cmp ax, 100
    jb Convert2
    jmp Convert3

SpaceWrite:
    mov ah, 09h
    mov dx, offset space
    int 21h
	
	JMP StartLoop

Convert2:                                   ;konveruoja dvizenklius skaicius
    mov dl, 10
    div dl
    add al, 30h
    push ax
    
    mov dl, al
    mov ah, 2
    int 21h
    
    pop ax
    add ah, 30h
    mov dl, ah
    
    mov ah, 2
    int 21h
    
    mov ah, 09h
    mov dx, offset space
    int 21h
    
    JMP StartLoop

Convert3:									;konvertuoja trizenklius skaicius
    mov dl, 100
    div dl
    push ax
    add al, 30h
    
    mov dl, al
    mov ah, 2
    int 21h

    pop ax
    mov al, ah
    mov ah, 0
    jmp Convert2

Final:										;programos pabaiga
    mov ah, 4Ch
    int 21h

Error:										;klaidos pranesimas
    mov ah, 09h
    mov dx, offset wrong_input
    int 21h
    JMP Final

END Start