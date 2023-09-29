;4. Parašykite programą, kuri atspausdina įvestos simbolių eilutės ASCII kodus dešimtainiu pavidalu;
;Pvz.: įvedus abC1 turi atspausdinti 97 98 67 49

.model small
.stack 100h
.data
    ivesk db "Iveskite simboliu eilute:", 13, 10, "$"
    wrong_input db "Netinkama ivestis.", 13, 10, "$"
    new_line db 13, 10, "$"
    space db " ", "$"
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
    ;Pasiruosimas konvertavimui
    mov si, offset buffer
    add si, 1             ;pridedam viena, kad suzinot kiek simboliu gavome

StartLoop:
    inc si
    mov ax, 0
    mov al, [ds:si]       ;issaugom kiek simboliu buvo ivesta registre CX
    cmp al, 13
    JE Final
    mov dx, 0
    cmp al, 33
    JB Error
    cmp ax, 100
    jb Convert2
    jmp Convert3

Convert2:
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

Convert3:
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

Final:
    mov ah, 4Ch
    int 21h

Error:
    mov ah, 09h
    mov dx, offset wrong_input
    int 21h
    JMP Final

END Start