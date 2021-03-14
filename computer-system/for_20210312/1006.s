.section .text

.global _start
_start:
	nop 
	mov  $4,%eax
	movw $1,%bx
	movb $0xff65, %dh
	movl $13,%edx

	movl $1,%eax
	movl $0,%ebx
	int $0x80
