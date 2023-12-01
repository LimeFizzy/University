; Savo darbo pradžioje programa turi išvesti trumpą aprašymą: autorių ir ką ji daro. Komandinės eilutės parametrų apdoroti nebūtina.
; Programa turi apdoroti programos variante nurodytą pertraukimą:
; Įsiminti esamą pertraukimo apdorojimo procedūros adresą;
; Į pertraukimo vektorių lentelę įrašyti Jūsų parašytos pertraukimo apdorojimo procedūros adresą;
; Atlikti keletą operacijų, kurių metu gali kilti pertraukimas;
; Atstatyti buvusį pertraukimo apdorojimo procedūros adresą;

; ******************************************************************************************
; 4. Žingsninio režimo pertraukimo (int 1) apdorojimo procedūra, atpažįstanti komandą MOV r/m<=sreg. 
; Ši procedūra turi patikrinti, ar pertraukimas įvyko prieš vykdant komandos MOV šeštąjį variantą, jei taip, į ekraną išvesti perspėjimą, ir visą informaciją apie komandą: adresą, kodą, mnemoniką, operandus.
; Pvz.: Į ekraną išvedama informacija galėtų atrodyti taip: Zingsninio rezimo pertraukimas! 0000:0128  8ED8  mov ds, ax ; ax= 0123
; ******************************************************************************************

;***************************************************************
; Programa, perrašanti 1 pertraukimo apdorojimo procedūrą; procedūra atpažįsta komandą MOV ir išveda į ekraną jos bitą w
;***************************************************************

; 1000 11d0 mod 0sr r/m [poslinkis]
.model small

.stack 100h

.data
	PranMOV	db "Zingsninio rezimo pertraukimas! $"
	Enteris db 13, 10, "$"
	PranNe	db "Komanda ne MOV r/m<=sreg.", 13, 10, "$"
	KomMov db "MOV $"
	SegmES db "ES $"
	SegmCS db "CS $"
	SegmSS db "SS $"
	SegmDS db "DS $"

.code
  Pradzia:
	MOV	ax, @data	;reikalinga kiekvienos programos pradžioj
	MOV	ds, ax		;reikalinga kiekvienos programos pradžioj

;****************************************************************************
; Nusistatom reikalingas registrų reikšmes
;****************************************************************************
	MOV	ax, 0		;nėra komandos MOV es, 0 - tai reikia daryti per darbinį registrą (ax)
	MOV	es, ax		;į es įsirašome 0, nes pertraukimų vektorių lentelė yra segmente, kurio pradžios adresas yra 00000
	
;****************************************************************************
; Iššisaugome tikrą pertraukimo apdorojimo procedūros adresą, kad programos gale galėtume jį atstatyti
;****************************************************************************
	PUSH	es:[4]
	PUSH	es:[6]
	
;****************************************************************************
; Pertraukimų vektorių lentelėje suformuojame pertraukimo apdorojimo procedūros adresą
;****************************************************************************
	MOV	word ptr es:[4], offset ApdorokPertr	;į pertraukimų vektorių lentelę įrašome pertraukimo apdorojimo procedūros poslinkį nuo kodo segmento pradžios
	MOV	es:[6], cs				;į pertraukimų vektorių lentelę įrašome pertraukimo apdorojimo procedūros segmentą

;****************************************************************************
; Testuojame pertraukimo apdorojimo procedūrą
;****************************************************************************
	PUSHF			;Išsisaugome SF reikšmę testavimo pradžioje
	PUSHF			;Išsisaugome SF kad galėtume ją išimti ir nustatyti TF
	POP ax			;Išimame SF reikšmę į TF
	OR ax, 0100h	;Nustatome TF=1
	PUSH ax			;Įdedame pakoreguotą reikšmę
	POPF			;Išimame pakoreguotą reikšmę į SF; Nuo čia TF=1
	NOP				;Pirmas pertraukimas kyla ne prieš šią komandą, o po jos; todėl tiesiog vieną komandą nieko nedarome
	
	MOV	ax, bx		;Šitą komandą nagrinės pertraukimo apdorojimo procedūra
	MOV	ax, cs		;Šitą komandą nagrinės pertraukimo apdorojimo procedūra d = 0
	mov ds, ax      ;d = 1
	mov ds, sp
	mov ds, bp
	mov ds, si
	mov ds, di
	mov ds, [BX+SI]
	mov [bx+si], ds
	MOV	al, 22h		;Šitą komandą nagrinės pertraukimo apdorojimo procedūra
	INC ax			;Šitą komandą nagrinės pertraukimo apdorojimo procedūra
	
	POPF			;Ištraukiame iš steko testavimo pradžioje buvusią SF reikšmę
					;Kadangi tada TF buvo lygi 0, tai tokiu būdu numušame TF
	
;****************************************************************************
; Atstatome tikrą pertraukimo apdorojimo programos adresą pertraukimų vektoriuje
;****************************************************************************
	POP	es:[6]
	POP	es:[4]

	MOV	ah, 4Ch		;reikalinga kiekvienos programos pabaigoj
	MOV	al, 0		;reikalinga kiekvienos programos pabaigoj
	INT	21h			;reikalinga kiekvienos programos pabaigoj

;****************************************************************************
; Pertraukimo apdorojimo procedūra
;****************************************************************************
  ApdorokPertr PROC
	;Įdedame registrų reikšmes į steką
	PUSH	ax
	PUSH	bx
	PUSH	dx
	PUSH	bp
	PUSH	es
	PUSH	ds

	;Nustatome DS reikšmę, jei pertraukimą iškviestų kita programa
	MOV	ax, @data
	MOV	ds, ax

	;Į registrą DL įsirašom komandos, prieš kurią buvo iškviestas INT, operacijos kodą
	MOV bp, sp			;Darbui su steku patogiausia naudoti registrq BP
	ADD bp, 12			;Suskaičiuojame kaip giliai steke yra įdėtas grįžimo adresas
	MOV bx, [bp]		;Į bx įdedame grįžimo adreso poslinkį nuo segmento pradžios (IP)
	MOV es, [bp+2]		;Į es įdedame grįžimo adreso segmentą (CS)
	MOV dl, [es:bx]		;Išimame pirmąjį baitą, esantį grįžimo adresu - komandos OPK
	
	;Tikriname, ar INT buvo iškviestas prieš komandą MOV
	MOV al, dl
	AND al, 0FDh		;Tikriname pagal pirmus 6 bitus ir paskutinįjį bitą
	CMP al, 8Ch			;Ar tai MOV registras / atmintis <--> segmento registras - 1000 11d0
	JE	ReikMov
	
	;Jei INT buvo iškviestas ne prieš komandą MOV, tai išvedame pranešimą
	MOV ah, 9
	MOV dx, offset PranNe
	INT 21h
	JMP pabaiga

	;Jei INT buvo iškviestas prieš komandą MOV, tai tada dl registre suformuojame bito w reikšmę
ReikMov:
	MOV dl, 31h		;Šiuo atveju w bito nėra, bet galima laikyti, kad w=1, nes visada veiksmai atliekami su žodžio dydžio registrais

	;Išvedame pranešimą ir bito w reikšmę
Spausdink:
	MOV ah, 9
	MOV dx, offset PranMOV
	INT 21h
	
	mov ax, es
	mov cx, 4
	call Print
	mov ah, 2
	mov dx, ':'
	int 21h
	mov ax, bx
	mov cx, 4
	call Print

	mov ah, 2
	mov dx, ' '
	int 21h

	MOV dh, [es:bx]
	inc bx
	mov dl, [es:bx]
	call ChooseSegment
	mov ax, dx
	mov cx, 4
	call Print

	mov ah, 2
	mov dx, ' '
	int 21h

	mov ah, 9
	mov dx, offset KomMov
	int 21h
	mov dx, si
	int 21h
	
	MOV ah, 9
	MOV dx, offset enteris
	INT 21h

	;Atstatome registrų reikšmes ir išeiname iš pertraukimo apdorojimo procedūros
Pabaiga:
	POP ds
	POP es
	POP bp
	POP	dx
	POP bx
	POP	ax
	IRET			;pabaigoje būtina naudoti grįžimo iš pertraukimo apdorojimo procedūros komandą IRET
				;paprastas RET netinka, nes per mažai informacijos išima iš steko
ApdorokPertr ENDP

Print PROC
    push bx
    mov bx, 10h

Begin:
    xor dx, dx        ; Clear dx before each division
    div bx            ; Divide AX by 10h, quotient in AX, remainder in DX
    ; Compare remainder with '9' to decide whether to print a number or a character
    cmp dx, 9
    jbe Num      ; Jump if less than or equal to '9'
    add dl, 'A' - 10  ; Convert remainder to ASCII for letters
	jmp Continue

Num:
    add dl, '0'       ; Convert remainder to ASCII for numbers
Continue:
	push dx
	loop Begin

	mov cx, 4
PrintReg:
    ; Print the current character
    mov ah, 2
	pop dx
    int 21h

    loop PrintReg

	pop bx
    ret

Print ENDP


ChooseSegment PROC
	push bx
Prepare:
	mov bx, dx
	AND bx, 0018h

SegmentSelection:
	cmp bx, 0000h
	je SaveES
	cmp bx, 0008h
	je SaveCS
	cmp bx, 0010h
	je SaveSS
	cmp bx, 0018h
	je SaveDS

	jmp Exit
SaveDS:
	mov si, offset SegmDS
	jmp Exit

SaveES:
	mov si, offset SegmES
	jmp Exit

SaveCS:
	mov si, offset SegmCS
	jmp Exit

SaveSS:
	mov si, offset SegmSS
	jmp Exit

Exit:
	pop bx
	ret
ChooseSegment ENDP

END Pradzia