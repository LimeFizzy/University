	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 0
	.globl	_saveToFile                     ; -- Begin function saveToFile
	.p2align	2
_saveToFile:                            ; @saveToFile
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	.cfi_def_cfa_offset 64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	str	x2, [sp, #24]
	ldr	x0, [sp, #24]
	adrp	x1, l_.str@PAGE
	add	x1, x1, l_.str@PAGEOFF
	bl	_fopen
	str	x0, [sp, #16]
	ldr	x8, [sp, #16]
	subs	x8, x8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB0_6
	b	LBB0_1
LBB0_1:
	ldr	x3, [sp, #16]
	sub	x0, x29, #12
	mov	x1, #4
	mov	x2, #1
	bl	_fwrite
	str	wzr, [sp, #12]
	b	LBB0_2
LBB0_2:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #12]
	ldur	w9, [x29, #-12]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB0_5
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_2 Depth=1
	ldur	x8, [x29, #-8]
	ldrsw	x9, [sp, #12]
	add	x0, x8, x9, lsl #2
	ldr	x3, [sp, #16]
	mov	x1, #4
	mov	x2, #1
	bl	_fwrite
	b	LBB0_4
LBB0_4:                                 ;   in Loop: Header=BB0_2 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB0_2
LBB0_5:
	adrp	x9, _saveCount@PAGE
	ldr	w8, [x9, _saveCount@PAGEOFF]
	add	w8, w8, #1
	str	w8, [x9, _saveCount@PAGEOFF]
	b	LBB0_6
LBB0_6:
	ldr	x0, [sp, #16]
	bl	_fclose
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_loadFromFile                   ; -- Begin function loadFromFile
	.p2align	2
_loadFromFile:                          ; @loadFromFile
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	.cfi_def_cfa_offset 64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	x1, [x29, #-16]
	str	x2, [sp, #24]
	ldr	x0, [sp, #24]
	adrp	x1, l_.str.1@PAGE
	add	x1, x1, l_.str.1@PAGEOFF
	bl	_fopen
	str	x0, [sp, #16]
	ldr	x8, [sp, #16]
	subs	x8, x8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB1_6
	b	LBB1_1
LBB1_1:
	ldur	x0, [x29, #-16]
	ldr	x3, [sp, #16]
	mov	x1, #4
	mov	x2, #1
	bl	_fread
	str	wzr, [sp, #12]
	b	LBB1_2
LBB1_2:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #12]
	ldur	x9, [x29, #-16]
	ldr	w9, [x9]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB1_5
	b	LBB1_3
LBB1_3:                                 ;   in Loop: Header=BB1_2 Depth=1
	ldur	x8, [x29, #-8]
	ldrsw	x9, [sp, #12]
	add	x0, x8, x9, lsl #2
	ldr	x3, [sp, #16]
	mov	x1, #4
	mov	x2, #1
	bl	_fread
	b	LBB1_4
LBB1_4:                                 ;   in Loop: Header=BB1_2 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB1_2
LBB1_5:
	adrp	x9, _loadCount@PAGE
	ldr	w8, [x9, _loadCount@PAGEOFF]
	add	w8, w8, #1
	str	w8, [x9, _loadCount@PAGEOFF]
	b	LBB1_6
LBB1_6:
	ldr	x0, [sp, #16]
	bl	_fclose
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_saveCount                      ; @saveCount
.zerofill __DATA,__common,_saveCount,4,2
	.globl	_loadCount                      ; @loadCount
.zerofill __DATA,__common,_loadCount,4,2
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"wb"

l_.str.1:                               ; @.str.1
	.asciz	"rb"

.subsections_via_symbols
