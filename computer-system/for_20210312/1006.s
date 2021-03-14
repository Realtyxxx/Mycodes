.section .text

.global _start
_start:
    nop 
    movl $4,%eax
    
    movl $1,%ebx
    movb $0x65, %dh
    
    movl $13,%edx

    movl $1,%eax
    movl $0,%ebx
    int $0x80
