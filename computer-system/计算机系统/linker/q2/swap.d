
swap.o:     file format elf32-i386


Disassembly of section .text:

00000000 <swap>:
   0:	55                   	push   %ebp
   1:	89 e5                	mov    %esp,%ebp
   3:	83 ec 10             	sub    $0x10,%esp
   6:	c7 05 00 00 00 00 04 	movl   $0x4,0x0
   d:	00 00 00 
			8: R_386_32	.bss
			c: R_386_32	buf
  10:	a1 00 00 00 00       	mov    0x0,%eax
			11: R_386_32	bufp0
  15:	8b 00                	mov    (%eax),%eax
  17:	89 45 fc             	mov    %eax,-0x4(%ebp)
  1a:	a1 00 00 00 00       	mov    0x0,%eax
			1b: R_386_32	bufp0
  1f:	8b 15 00 00 00 00    	mov    0x0,%edx
			21: R_386_32	.bss
  25:	8b 12                	mov    (%edx),%edx
  27:	89 10                	mov    %edx,(%eax)
  29:	a1 00 00 00 00       	mov    0x0,%eax
			2a: R_386_32	.bss
  2e:	8b 55 fc             	mov    -0x4(%ebp),%edx
  31:	89 10                	mov    %edx,(%eax)
  33:	90                   	nop
  34:	c9                   	leave  
  35:	c3                   	ret    
