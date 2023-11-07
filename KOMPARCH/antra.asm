.MODEL small
.STACK 256
.DATA
	help db "Sveiki, sita pragrama nuskaito 4 paramentus, duomenu faila, du eilutes fragmentus ir rezultatu faila. Duomenu faile visus pirmus fragmentus pakeicia antruoju ir isspausdina rezultatu faile.", 10, 13, "Iveskite paramentus pagal pavizdi: antra.exe duom.txt abcd EFG rez.txt", 10, 13, "$"
	input db 255 dup(0)
	string1 db 255 dup(0)
	string2 db 255 dup(0)
	output db 255 dup(0)
.CODE
Start:
	mov ax, @data
	mov ds, ax

	xor cx, cx
    xor ah, ah
    mov cl, [es:0080h]
	cmp cx, 4
	jbe Helpmsg
	mov dx, [es:0082h]
	cmp dx, "?/"
	je Helpmsg
	jne SkipHelp

SkipHelp:
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

    mov ah, 09h
    mov dx, offset input
    int 21h
    mov dx, offset string1
    int 21h
    mov dx, offset string2
    int 21h
    mov dx, offset output
    int 21h

Final:
    mov ah, 4Ch
	int 21h

Helpmsg:
    mov ah, 09h
    mov dx, offset help
    int 21h
    JMP Final

SaveArgument PROC
Begin:
    int 3
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
    mov byte ptr [si], "$"
    inc di
	ret
StopEnter:
    mov byte ptr [si], "$"
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