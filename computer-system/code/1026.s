	.file	"1026.c"
	.section	.rodata
.LC2:
	.string	"%.10f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$0x3dcccccd, %eax
	movl	%eax, 20(%esp)
	movl	$0x3e4ccccd, %eax
	movl	%eax, 24(%esp)
	flds	20(%esp)
	fadds	24(%esp)
	fstps	28(%esp)
	flds	28(%esp)
	movl	$.LC2, %eax
	fstpl	4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
