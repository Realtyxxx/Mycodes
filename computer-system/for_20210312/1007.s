.section .data
       
         value1:
              .int 1

         value2:
              .short 2

         value3:
              .byte 3

.section .text

.global _start

_start:
  
       nop
       movl value1,%ecx
       movw value1,%bx
       movw value2,%bx
       movb value3,%cl

       movl $1,%eax
       movl $0,%ebx
       int $0x80
