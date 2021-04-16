.section .text

.global _start

_start:

  nop
  movl $0x210a0eed, %eax 
  movl $0x28214ec0, %edx
  imul %eax, %edx

  mov $1, %eax
  int $0x80
