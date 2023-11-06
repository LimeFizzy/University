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

	mov cx, 0
    mov cl, [es:128]
    mov bx, 130
	cmp cx, 0
	je Helpmsg
	mov dl, [es:130]
	cmp dl, '/'
	je Helpmsg
	mov dl, [es:131]
	cmp dl, '?'
	jne SkipHelp
	JE Helpmsg

SkipHelp:
	mov si, offset input
	mov al, 0
	call SaveArgument
	mov si, offset string1
	call SaveArgument
	mov si, offset string2
	call SaveArgument
	mov si, offset output
	call SaveArgument

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
	mov dl, [es:bx]
	cmp dl, 32
	je Stop
	mov [si], dl
	inc bx
	inc si
	dec cx
	cmp cx, 0
	je Helpmsg
	jmp Begin
Stop:
	mov [si], 0
	inc bx
	mov ax, 0
	ret
SaveArgument ENDP


END Start