LOCALS @@ ; Lokalios zymes prasideda @@
.MODEL small ; Atminties modelis:
				; 64K kodui ir 64K duomenims
.STACK 256
.DATA
	help db "Sveiki, sita pragrama nuskaito 4 paramentus, duomenu faila, du eilutes fragmentus ir rezultatu faila. Duomenu faile visus pirmus fragmentus pakeicia antruoju ir isspausdina rezultatu faile.", 10, 13, "Iveskite paramentus pagal pavizdi: antra.exe duom.txt abcd EFG rez.txt", 10, 13, "$"
    msg DB "Programos parametrai:"
	msgLen = $-msg          ; Eilutes msg ilgis gaunamas is einamojo adreso ($) atemus jos pradzios adresa
.CODE
Strt:
	push ds                 ; Issaugome steke PSP pradzios adresa
	mov ax, @data
	mov ds, ax
    mov cl, [es:80h]
    cmp cl, 0
    je Helpmsg
	mov cx, (msgLen)
	mov dx, OFFSET msg
	call PrintBuf           ; Atspausdiname pranesima
	pop ds
	mov cl, [ds:80h]         ; Parametru eilutes ilgis (PSP su poslinkiu 80h)
	xor ch, ch
	mov dx, 81h              ; Parametru eilutes pradzios adresas
	call PrintBuf
Final:
    mov ax, 04C00h
	int 21h                 ; int 21,4C - programos pabaiga

Helpmsg:
    mov ah, 09h
    mov dx, offset help
    int 21h
    JMP Final

PrintBuf PROC
	push ax                 ; Issaugome steke registrus,
	push bx                 ; kurie keisis
	mov ah, 40h
	mov bx, 1
	int 21h                 ; int 21,40 - isvedimas i faila ar irengini	
	pop bx                  ; Atstatome issaugotus registrus
	pop ax
	ret
PrintBuf ENDP
;-------------------------------------------------------------------
END Strt