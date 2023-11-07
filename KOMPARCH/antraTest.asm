.MODEL small
.STACK 256
.DATA
	help db "Sveiki,", 10, 13, "iveskite paramentus pagal pavizdi: antra.exe duom.txt abcd EFG rez.txt", 10, 13, "$"
	FileProblem db "Ivestas failas nebuvo rastas.", 10, 13, "Iveskite paramentus pagal pavizdi: antra.exe duom.txt abcd EFG rez.txt", 10, 13, "$"
    trying db "All good", 10, 13, "$"
    input db 255 dup(0)
    inputFD dw, ?               ; Input Failo Deskriptorius
	string1 db 255 dup(0)
	string2 db 255 dup(0)
	output db 255 dup(0)
    outputFD dw, ?              ; Output Failo Deskriptorius
    buffer db 50000 dup(?)
    tempBuf db 255 dup(0)       ; Reikalingas kad issaugoti dalinai kartojamaji pradinio failo teksta
.CODE
Start:
	mov ax, @data
	mov ds, ax
    ; ********** Argumentu tikrinimas **********
	xor cx, cx
    xor ah, ah
    mov cl, [es:0080h]
	cmp cx, 4
	jbe Helpmsg
	jne SkipHelp

SkipHelp:
    ; ********** Argumentu irasymas i kintamuosius **********
    xor di, di
    mov bx, 82h
	mov si, offset input
	call SaveArgument
	mov si, offset string1
	call SaveArgument
	mov si, offset string2
	call SaveArgument
	mov si, offset output
	call SaveArgument

    ; ********** Nuskaitymas / Irasymas **********
    ; Bylos atidarimas skaitymui
    xor ax, ax
    mov ah, 3Dh
    mov al, 00
    mov dx, offset input
    int 21h
    jc MissingFile
    mov inputFD, ax
    ; Skaitymas
    mov ah, 3Fh
    mov bx, inputFD
    mov cx, 100
    mov dx, offset buffer
    int 21h
    push ax
    ; Bylos sukurimas rasymui
    mov ah, 3Ch
    mov cx, 0
    mov dx, offset output
    int 21h
    mov outputFD, ax
    ; Rasymas
    mov ah, 40h
    mov bx, outputFD
    pop cx
    mov dx, offset buffer
    int 21h
    ; Bylos uzdarimas
    mov ah, 3Eh
    mov bx, outputFD
    int 21h

Final:
    mov ah, 4Ch
	int 21h

Helpmsg:
    mov ah, 09h
    mov dx, offset help
    int 21h
    JMP Final

MissingFile:
    mov ah, 09h
    mov dx, offset FileProblem
    int 21h
    jmp Final


SaveArgument PROC
Begin:
	mov dx, [es:bx]
	inc bx
    cmp dl, 20h
	je StopSpace
    cmp dl, 13
    je StopEnter
	mov byte ptr [si], dl
	inc si
	jmp Begin
StopSpace:
    mov byte ptr [si], 0
    inc di
	ret
StopEnter:
    mov byte ptr [si], 0
    cmp di, 3
    jb Helpme
    ret
Helpme:
    mov ah, 09h
    mov dx, offset help
    int 21h
    mov ah, 4Ch
    int 21h
    ret
SaveArgument ENDP


END Start