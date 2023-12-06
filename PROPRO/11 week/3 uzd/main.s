	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 0
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
	b	LBB0_1
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp]
	ldr	w9, [sp, #4]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB0_4
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	bl	_rand
	mov	w9, #100
	sdiv	w8, w0, w9
	mul	w8, w8, w9
	subs	w8, w0, w8
	add	w8, w8, #1
	ldr	x9, [sp, #8]
	ldrsw	x10, [sp]
	str	w8, [x9, x10, lsl  #2]
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp]
	add	w8, w8, #1
	str	w8, [sp]
	b	LBB0_1
LBB0_4:
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
	b	LBB1_1
LBB1_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #16]
	ldur	w9, [x29, #-12]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB1_4
	b	LBB1_2
LBB1_2:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldur	x8, [x29, #-8]
	ldrsw	x9, [sp, #16]
	ldr	w9, [x8, x9, lsl  #2]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	b	LBB1_3
LBB1_3:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #16]
	add	w8, w8, #1
	str	w8, [sp, #16]
	b	LBB1_1
LBB1_4:
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
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
	adrp	x2, l_.str.2@PAGE
	add	x2, x2, l_.str.2@PAGEOFF
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
	adrp	x2, l_.str.3@PAGE
	add	x2, x2, l_.str.3@PAGEOFF
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
	adrp	x8, _saveCount@GOTPAGE
	ldr	x8, [x8, _saveCount@GOTPAGEOFF]
	ldr	w8, [x8]
	subs	w8, w8, #3
	cset	w8, ne
	tbnz	w8, #0, LBB2_3
	b	LBB2_1
LBB2_1:
	adrp	x8, _loadCount@GOTPAGE
	ldr	x8, [x8, _loadCount@GOTPAGEOFF]
	ldr	w8, [x8]
	subs	w8, w8, #3
	cset	w8, ne
	tbnz	w8, #0, LBB2_3
	b	LBB2_2
LBB2_2:
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	b	LBB2_4
LBB2_3:
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	b	LBB2_4
LBB2_4:
	mov	w0, #0
	ldp	x29, x30, [sp, #80]             ; 16-byte Folded Reload
	add	sp, sp, #96
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%d "

l_.str.1:                               ; @.str.1
	.asciz	"\n"

l_.str.2:                               ; @.str.2
	.asciz	"db1.bin"

l_.str.3:                               ; @.str.3
	.asciz	"db2.bin"

l_.str.4:                               ; @.str.4
	.asciz	"all good\n"

l_.str.5:                               ; @.str.5
	.asciz	"something's wrong\n"

.subsections_via_symbols
