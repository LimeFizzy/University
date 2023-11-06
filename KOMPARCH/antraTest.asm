LOCALS @@ ; Lokalios zymes prasideda @@
.MODEL small ; Atminties modelis:
				; 64K kodui ir 64K duomenims
.STACK 256
.DATA
    inputFileName db 100 DUP('$') ; Variable to store input file name
    fragment1 db 100 DUP('$')     ; Variable to store first fragment
    fragment2 db 100 DUP('$')     ; Variable to store second fragment
    outputFileName db 100 DUP('$'); Variable to store output file name
	help db "Sveiki, sita pragrama nuskaito 4 paramentus, duomenu faila, du eilutes fragmentus ir rezultatu faila. Duomenu faile visus pirmus fragmentus pakeicia antruoju ir isspausdina rezultatu faile.", 10, 13, "Iveskite paramentus pagal pavizdi: antra.exe duom.txt abcd EFG rez.txt", 10, 13, "$"
    msg DB "Programos parametrai:"
.CODE
Strt:
    push ds                 ; Issaugome steke PSP pradzios adresa
    mov ax, @data
    mov ds, ax
    mov cl, [es:80h]
    cmp cl, 4              ; Check if there are enough command line arguments
    jl Helpmsg             ; If not, display help message
    mov dx, OFFSET msg
    mov ah, 09h
    int 21h

    mov si, 0081h             ; Offset for the first command line argument

    mov dx, OFFSET inputFileName
    call CopyArgument      ; Copy input file name
    mov ah, 09h
    int 21h

    mov dx, OFFSET fragment1
    call CopyArgument      ; Copy first fragment
    int 21h

    mov dx, OFFSET fragment2
    call CopyArgument      ; Copy second fragment
    int 21h

    mov dx, OFFSET outputFileName
    call CopyArgument      ; Copy output file name
    int 21h

    pop ds
Final:
    mov ax, 4C00h
    int 21h                 ; int 21,4C - programos pabaiga

CopyArgument PROC
    mov al, [es:si]           ; Load a byte from command line argument
    cmp al, ' '            ; Check if it's a space character or end of string
    je end_copy            ; If space or end of string, jump to end_copy
    mov di, dx             ; Move destination buffer offset to di
    mov [di], al           ; Store the byte in the destination buffer
    inc si                 ; Move to the next character in command line argument
    inc dx                 ; Move to the next character in the destination buffer
    jmp CopyArgument       ; Continue copying the next byte of the command line argument
end_copy:
    ret
CopyArgument ENDP

Helpmsg:
    mov ah, 09h
    mov dx, offset help
    int 21h
    JMP Final

;-------------------------------------------------------------------
END Strt
