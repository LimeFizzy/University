; ******************************************************************************************
; 4. Žingsninio režimo pertraukimo (int 1) apdorojimo procedūra, atpažįstanti komandą MOV r/m<=sreg. 
; Ši procedūra turi patikrinti, ar pertraukimas įvyko prieš vykdant komandos MOV šeštąjį variantą, jei taip, į ekraną išvesti perspėjimą, ir visą informaciją apie komandą: adresą, kodą, mnemoniką, operandus.
; Pvz.: Į ekraną išvedama informacija galėtų atrodyti taip: Zingsninio rezimo pertraukimas! 0000:0128  8ED8  mov ds, ax ; ax= 0123
; ******************************************************************************************

;***************************************************************
; Programa, perrašanti 1 pertraukimo apdorojimo procedūrą; procedūra atpažįsta komandą MOV r/m<=sreg ir išveda į ekraną adresą, kodą, mnemoniką ir operandus.
;***************************************************************

; 1000 11d0 mod 0sr r/m [poslinkis]
.model small

.stack 100h

.data
	PradPran db "Aut. - Leonardas Sinkevicius.", 13, 10, "Programa atpazista MOV reg <=r/m komanda, apdoroja ja su INT 1.", 13, 10, "$"
	PranMOV	db "Zingsninio rezimo pertraukimas! $"
	Enteris db 13, 10, "$"
	PranNe	db "Komanda ne MOV r/m<=sreg.", 13, 10, "$"
	KomMov db "MOV $"
	SegmES db "ES$"
	SegmCS db "CS$"
	SegmSS db "SS$"
	SegmDS db "DS$"
	RegistAX db "AX$"
	RegistBX db "BX$"
	RegistCX db "CX$"
	RegistDX db "DX$"
	RegistSP db "SP$"
	RegistBP db "BP$"
	RegistSI db "SI$"
	RegistDI db "DI$"
	RegistBXirSI db "[BX+SI]$"
	RegistBXirDI db "[BX+DI]$"
	RegistBPirSI db "[BP+SI]$"
	RegistBPirDI db "[BP+DI]$"
	RegistBXirSIposl db "[BX+SI+poslinkis]$"
	RegistBXirDIposl db "[BX+DI+poslinkis]$"
	RegistBPirSIposl db "[BP+SI+poslinkis]$"
	RegistBPirDIposl db "[BP+DI+poslinkis]$"
	RegistBXposl db "[BX+poslinkis]$"
	RegistBPposl db "[BP+poslinkis]$"
	RegistSIposl db "[SI+poslinkis]$"
	RegistDIposl db "[DI+poslinkis]$"
	Next db ", $"
	SemiColon db " ; $"

.code
  Pradzia:
	MOV	ax, @data	;reikalinga kiekvienos programos pradžioj
	MOV	ds, ax		;reikalinga kiekvienos programos pradžioj

	MOV	ah, 09h			;DOS funkcijos numeris
	MOV	dx, offset PradPran
	INT	21h

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
	mov ds, [bx+si+5]
	
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
	PUSH 	cx
	PUSH	dx
	PUSH	bp
	PUSH	es
	PUSH	ds

	;Nustatome DS reikšmę, jei pertraukimą iškviestų kita programa
	MOV	ax, @data
	MOV	ds, ax

	;Į registrą DL įsirašom komandos, prieš kurią buvo iškviestas INT, operacijos kodą
	MOV bp, sp			;Darbui su steku patogiausia naudoti registrq BP
	ADD bp, 14			;Suskaičiuojame kaip giliai steke yra įdėtas grįžimo adresas
	MOV bx, [bp]		;Į bx įdedame grįžimo adreso poslinkį nuo segmento pradžios (IP)
	MOV es, [bp+2]		;Į es įdedame grįžimo adreso segmentą (CS)
	MOV dl, [es:bx]		;Išimame pirmąjį baitą, esantį grįžimo adresu - komandos OPK
	
	;Tikriname, ar INT buvo iškviestas prieš komandą MOV
	MOV al, dl
	AND al, 0FDh		;1111 1101 Tikriname pagal pirmus 6 bitus ir paskutinįjį bitą
	CMP al, 8Ch			;Ar tai MOV registras / atmintis <--> segmento registras - 1000 11d0
	JE	ReikMov
	
	;Jei INT buvo iškviestas ne prieš komandą MOV, tai išvedame pranešimą
	MOV ah, 9
	MOV dx, offset PranNe
	INT 21h
	JMP pabaiga

ReikMov:
	
	MOV ah, 9
	MOV dx, offset PranMOV
	INT 21h
	
	mov ax, es
	call Print
	mov ah, 2
	mov dx, ':'
	int 21h
	mov ax, bx
	call Print

	mov ah, 2
	mov dx, ' '
	int 21h

	MOV dh, [es:bx]
	inc bx
	mov dl, [es:bx]
	
	push dx
	mov ax, dx
	call Print
	pop dx

	push dx
	and dx, 0200h
	cmp dx, 0h
	je Dis0
	pop dx
	jmp Dis1
Dis0: 						; Ispradziu registras, po to segmentas
	pop dx
	call ChooseRegister
	push dx

	mov ah, 2
	mov dx, ' '
	int 21h

	mov ah, 9
	mov dx, offset KomMov
	int 21h
	mov dx, si
	int 21h
	mov dx, offset Next
	int 21h
	pop dx
	call ChooseSegment
	mov ah, 9
	mov dx, si
	int 21h
	mov dx, offset SemiColon
	int 21h
	
	MOV ah, 9
	MOV dx, offset enteris
	INT 21h
	jmp Pabaiga


Dis1: 						; Ispradziu segmentas, po to registras
	call ChooseSegment
	push dx

	mov ah, 2
	mov dx, ' '
	int 21h

	mov ah, 9
	mov dx, offset KomMov
	int 21h
	mov dx, si
	int 21h
	mov dx, offset Next
	int 21h
	pop dx
	call ChooseRegister
	mov ah, 9
	mov dx, si
	int 21h
	mov dx, offset SemiColon
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
	POP cx
	POP bx
	POP	ax
	IRET				;pabaigoje būtina naudoti grįžimo iš pertraukimo apdorojimo procedūros komandą IRET
						;paprastas RET netinka, nes per mažai informacijos išima iš steko
ApdorokPertr ENDP

Print PROC				; Procedura atspausdinanti registro saugoma reiksme
    push bx
	mov cx, 4
    mov bx, 10h

Begin:
    xor dx, dx
    div bx				; Dalinam ax is 10h
    cmp dx, 9			; dx saugoja liekana po dalybos
    jbe Num      		; jeigu liekana maziau uz 9 -> tai skaicius
    add dl, 'A' - 10  	; konvertuojame raide i jos ASCII koda
	jmp Continue

Num:
    add dl, '0'       	; konvertuojame skaiciu i jo ASCII koda
Continue:
	push dx				; ipushinam reiksmes i steka tam, kad apversti reiksmes
	loop Begin

	mov cx, 4
PrintReg:				; spausdiname reiksmes
    mov ah, 2
	pop dx
    int 21h

    loop PrintReg

	pop bx
    ret

Print ENDP


ChooseSegment PROC
	push bx
	mov bx, dx
	AND bx, 0018h		; visi bitai isskirus sr nunulinami

	cmp bx, 0000h		; lyginam likusius bitus ir nustatom kuris segmento registras reikalingas
	je SaveES
	cmp bx, 0008h
	je SaveCS
	cmp bx, 0010h
	je SaveSS
	cmp bx, 0018h
	je SaveDS

	jmp Exit
SaveDS:					; issaugome i si tekstines eilutes adresu su reikiamu segmentu
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


ChooseRegister PROC
	push cx
	mov cx, dx
	AND cx, 00C7h		; visi bitai isskirus mod ir r/m nunulinami

	; jeigu mod = 11
	cmp cx, 00C0h		; ieskomas tinkamas variantas
	je RegAX
	cmp cx, 00C1h
	je RegCX
	cmp cx, 00C2h
	je RegDX
	cmp cx, 00C3h
	je RegBX
	cmp cx, 00C4h
	je RegSP
	cmp cx, 00C5h
	je RegBP
	cmp cx, 00C6h
	je RegSI
	cmp cx, 00C7h
	je RegDI

	; jeigu mod = 00
	cmp cx, 0000h
	je RegBXirSI
	cmp cx, 0001h
	je RegBXirDI
	cmp cx, 0002h
	je RegBPirSI
	cmp cx, 0003h
	je RegBPirDI
	cmp cx, 0004h
	je RegSI
	cmp cx, 0005h
	je RegDI
	cmp cx, 0007h
	je RegBX
	jmp SuPosl

RegAX:					; issaugome i si tekstines eilutes adresu su reikiamu segmentu
	mov si, offset RegistAX
	jmp Exit1

RegBX:
	mov si, offset RegistBX
	jmp Exit1

RegCX:
	mov si, offset RegistCX
	jmp Exit1

RegDX:
	mov si, offset RegistDX
	jmp Exit1

RegBP:
	mov si, offset RegistBP
	jmp Exit1

RegSI:
	mov si, offset RegistSI
	jmp Exit1

RegDI:
	mov si, offset RegistDI
	jmp Exit1

RegSP:
	mov si, offset RegistSP
	jmp Exit1

RegBXirSI:
	mov si, offset RegistBXirSI
	jmp Exit1

RegBXirDI:
	mov si, offset RegistBXirDI
	jmp Exit1

RegBPirSI:
	mov si, offset RegistBPirSI
	jmp Exit1

RegBPirDI:
	mov si, offset RegistBPirDI
	jmp Exit1

SuPosl:
	; jeigu mod = 01
	cmp cx, 0040h
	je RegBXirSIposl
	cmp cx, 0041h
	je RegBXirDIposl
	cmp cx, 0042h
	je RegBPirSIposl
	cmp cx, 0043h
	je RegBPirDIposl
	cmp cx, 0044h
	je RegSIposl
	cmp cx, 0045h
	je RegDIposl
	cmp cx, 0046h
	je RegBPposl
	cmp cx, 0047h
	je RegBXposl

	; jeigu mod = 10
	cmp cx, 0080h
	je RegBXirSIposl
	cmp cx, 0081h
	je RegBXirDIposl
	cmp cx, 0082h
	je RegBPirSIposl
	cmp cx, 0083h
	je RegBPirDIposl
	cmp cx, 0084h
	je RegSIposl
	cmp cx, 0085h
	je RegDIposl
	cmp cx, 0086h
	je RegBPposl
	cmp cx, 0087h
	je RegBXposl

RegBXirSIposl:
	mov si, offset RegistBXirSIposl
	jmp Exit1

RegBXirDIposl:
	mov si, offset RegistBXirDIposl
	jmp Exit1

RegBPirSIposl:
	mov si, offset RegistBPirSIposl
	jmp Exit1

RegBPirDIposl:
	mov si, offset RegistBPirDIposl
	jmp Exit1

RegBPposl:
	mov si, offset RegistBPposl
	jmp Exit1

RegSIposl:
	mov si, offset RegistSIposl
	jmp Exit1

RegDIposl:
	mov si, offset RegistDIposl
	jmp Exit1

RegBXposl:
	mov si, offset RegistBXposl
	jmp Exit1

Exit1:
	pop cx
	ret
ChooseRegister ENDP

END Pradzia