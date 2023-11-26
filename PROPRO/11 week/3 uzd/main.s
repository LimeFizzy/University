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
	.globl	_fillArray                      ; -- Begin function fillArray
	.p2align	2
_fillArray:                             ; @fillArray
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #8]
	str	w1, [sp, #4]
	mov	x0, #0
	bl	_time
                                        ; kill: def $w0 killed $w0 killed $x0
	bl	_srand
	str	wzr, [sp]
	b	LBB2_1
LBB2_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp]
	ldr	w9, [sp, #4]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB2_4
	b	LBB2_2
LBB2_2:                                 ;   in Loop: Header=BB2_1 Depth=1
	bl	_rand
	mov	w9, #100
	sdiv	w8, w0, w9
	mul	w8, w8, w9
	subs	w8, w0, w8
	add	w8, w8, #1
	ldr	x9, [sp, #8]
	ldrsw	x10, [sp]
	str	w8, [x9, x10, lsl  #2]
	b	LBB2_3
LBB2_3:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	w8, [sp]
	add	w8, w8, #1
	str	w8, [sp]
	b	LBB2_1
LBB2_4:
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_printArray                     ; -- Begin function printArray
	.p2align	2
_printArray:                            ; @printArray
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	str	wzr, [sp, #16]
	b	LBB3_1
LBB3_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #16]
	ldur	w9, [x29, #-12]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB3_4
	b	LBB3_2
LBB3_2:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldur	x8, [x29, #-8]
	ldrsw	x9, [sp, #16]
	ldr	w9, [x8, x9, lsl  #2]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	b	LBB3_3
LBB3_3:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	w8, [sp, #16]
	add	w8, w8, #1
	str	w8, [sp, #16]
	b	LBB3_1
LBB3_4:
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #96
	.cfi_def_cfa_offset 96
	stp	x29, x30, [sp, #80]             ; 16-byte Folded Spill
	add	x29, sp, #80
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-16]
	stur	xzr, [x29, #-24]
	stur	xzr, [x29, #-32]
	mov	x0, #80
	str	x0, [sp]                        ; 8-byte Folded Spill
	bl	_malloc
	mov	x8, x0
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	stur	x8, [x29, #-16]
	bl	_malloc
	mov	x8, x0
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	stur	x8, [x29, #-24]
	bl	_malloc
	stur	x0, [x29, #-32]
	ldur	x0, [x29, #-16]
	mov	w1, #20
	str	w1, [sp, #12]                   ; 4-byte Folded Spill
	bl	_fillArray
	ldr	w1, [sp, #12]                   ; 4-byte Folded Reload
	ldur	x0, [x29, #-24]
	bl	_fillArray
	ldr	w1, [sp, #12]                   ; 4-byte Folded Reload
	ldur	x0, [x29, #-32]
	bl	_fillArray
	ldr	w1, [sp, #12]                   ; 4-byte Folded Reload
	ldur	x0, [x29, #-16]
	adrp	x2, l_.str.4@PAGE
	add	x2, x2, l_.str.4@PAGEOFF
	str	x2, [sp, #32]                   ; 8-byte Folded Spill
	bl	_saveToFile
	ldr	w1, [sp, #12]                   ; 4-byte Folded Reload
	ldr	x2, [sp, #32]                   ; 8-byte Folded Reload
	ldur	x0, [x29, #-32]
	bl	_saveToFile
	ldr	x2, [sp, #32]                   ; 8-byte Folded Reload
	ldur	x0, [x29, #-16]
	sub	x1, x29, #36
	str	x1, [sp, #24]                   ; 8-byte Folded Spill
	bl	_loadFromFile
	ldr	w1, [sp, #12]                   ; 4-byte Folded Reload
	ldur	x0, [x29, #-24]
	adrp	x2, l_.str.5@PAGE
	add	x2, x2, l_.str.5@PAGEOFF
	str	x2, [sp, #16]                   ; 8-byte Folded Spill
	bl	_saveToFile
	ldr	x2, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x1, [sp, #24]                   ; 8-byte Folded Reload
	ldur	x0, [x29, #-32]
	bl	_loadFromFile
	ldr	x1, [sp, #24]                   ; 8-byte Folded Reload
	ldr	x2, [sp, #32]                   ; 8-byte Folded Reload
	ldur	x0, [x29, #-24]
	bl	_loadFromFile
	adrp	x8, _saveCount@PAGE
	ldr	w8, [x8, _saveCount@PAGEOFF]
	subs	w8, w8, #3
	cset	w8, ne
	tbnz	w8, #0, LBB4_3
	b	LBB4_1
LBB4_1:
	adrp	x8, _loadCount@PAGE
	ldr	w8, [x8, _loadCount@PAGEOFF]
	subs	w8, w8, #3
	cset	w8, ne
	tbnz	w8, #0, LBB4_3
	b	LBB4_2
LBB4_2:
	adrp	x0, l_.str.6@PAGE
	add	x0, x0, l_.str.6@PAGEOFF
	bl	_printf
	b	LBB4_4
LBB4_3:
	adrp	x0, l_.str.7@PAGE
	add	x0, x0, l_.str.7@PAGEOFF
	bl	_printf
	b	LBB4_4
LBB4_4:
	mov	w0, #0
	ldp	x29, x30, [sp, #80]             ; 16-byte Folded Reload
	add	sp, sp, #96
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

l_.str.2:                               ; @.str.2
	.asciz	"%d "

l_.str.3:                               ; @.str.3
	.asciz	"\n"

l_.str.4:                               ; @.str.4
	.asciz	"db1.bin"

l_.str.5:                               ; @.str.5
	.asciz	"db2.bin"

l_.str.6:                               ; @.str.6
	.asciz	"all good\n"

l_.str.7:                               ; @.str.7
	.asciz	"something's wrong\n"

.subsections_via_symbols
