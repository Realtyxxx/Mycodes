.section .data
	value:
		.int 1,2,3,4,5,6,7,8,9 
.section .text

.global _start
 _start:
	nop
	leal value ,%edi
	mov $2, %eax
	leal 1(%edi,%eax,2),%ecx
	int $0x80
	
