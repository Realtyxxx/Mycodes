.section .data

	values:
		.int 10,15,20,25,30,35,40,45,50,55,60
		
.section .text    
   
.global _start   
 _start:      
     	nop
     	movl values,%eax
	movl $values,%edi
	#leal values,%edi 
	#lealæŒ‡ä»¤ï¼Œå°†valuesçš„åœ°å€æ”¾åˆ°å¯„å­˜å™¨ä¸­
	movl $1,%edx
	leal 5(%edx, %edx, 2), %eax
	#å‡è®¾%edxçš„å€¼ä¸ºx, ä¸Šé¢è¿™è¡Œä¼šå°†%eaxçš„å€¼è®¾ç½®ä¸ºâ€?x+5â€?
	movl $100,4(%edi)
	movl $1,%edi
	movl values(,%edi,4),%ebx
	#¼ÙÉè%ediµÄÖµÎªi£¬ÉÏÃæµÄÔËÐÐ»á½«%ebxÉèÖÃÎªvalues+4*i£¬
      #¼´valuesÊý×éÖÐµÚi¸öÔªËØµÄµØÖ·£¨ÔªËØ´Ó0¼ÆÆð£©	
	#leal values(%edi,4),%ebx
      #´ËÖ¸ÁîÍê³ÉÊ²Ã´¹¦ÄÜ£¿ÔËÐÐºó½á¹û£¿

     	movl $1, %eax   
     	int $0x80  
