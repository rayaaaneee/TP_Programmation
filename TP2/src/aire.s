	.file	"aire.c"
	.text
	.p2align 4,,15
	.globl	_calculer_aire
	.def	_calculer_aire;	.scl	2;	.type	32;	.endef
_calculer_aire:
LFB10:
	.cfi_startproc
	subl	$12, %esp
	.cfi_def_cfa_offset 16
	flds	16(%esp)
	fldl	LC0
	fmul	%st(1), %st
	fmulp	%st, %st(1)
	fstps	4(%esp)
	flds	4(%esp)
	addl	$12, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE10:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC4:
	.ascii "L'aire du cercle de rayon %.2f est %.2f\12\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	flds	LC2
	movl	$LC4, (%esp)
	fstpl	12(%esp)
	flds	LC3
	fstpl	4(%esp)
	call	_printf
	xorl	%eax, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.section .rdata,"dr"
	.align 8
LC0:
	.long	1413754136
	.long	1074340347
	.align 4
LC2:
	.long	1117590627
	.align 4
LC3:
	.long	1084227584
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
