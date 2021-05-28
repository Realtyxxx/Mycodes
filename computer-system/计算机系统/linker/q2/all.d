
main:     file format elf32-i386


Disassembly of section .init:

0804828c <_init>:
 804828c:	53                   	push   %ebx
 804828d:	83 ec 08             	sub    $0x8,%esp
 8048290:	e8 7b 00 00 00       	call   8048310 <__x86.get_pc_thunk.bx>
 8048295:	81 c3 6b 1d 00 00    	add    $0x1d6b,%ebx
 804829b:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 80482a1:	85 c0                	test   %eax,%eax
 80482a3:	74 05                	je     80482aa <_init+0x1e>
 80482a5:	e8 26 00 00 00       	call   80482d0 <__libc_start_main@plt+0x10>
 80482aa:	83 c4 08             	add    $0x8,%esp
 80482ad:	5b                   	pop    %ebx
 80482ae:	c3                   	ret    

Disassembly of section .plt:

080482b0 <__libc_start_main@plt-0x10>:
 80482b0:	ff 35 04 a0 04 08    	pushl  0x804a004
 80482b6:	ff 25 08 a0 04 08    	jmp    *0x804a008
 80482bc:	00 00                	add    %al,(%eax)
	...

080482c0 <__libc_start_main@plt>:
 80482c0:	ff 25 0c a0 04 08    	jmp    *0x804a00c
 80482c6:	68 00 00 00 00       	push   $0x0
 80482cb:	e9 e0 ff ff ff       	jmp    80482b0 <_init+0x24>

Disassembly of section .plt.got:

080482d0 <.plt.got>:
 80482d0:	ff 25 fc 9f 04 08    	jmp    *0x8049ffc
 80482d6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

080482e0 <_start>:
 80482e0:	31 ed                	xor    %ebp,%ebp
 80482e2:	5e                   	pop    %esi
 80482e3:	89 e1                	mov    %esp,%ecx
 80482e5:	83 e4 f0             	and    $0xfffffff0,%esp
 80482e8:	50                   	push   %eax
 80482e9:	54                   	push   %esp
 80482ea:	52                   	push   %edx
 80482eb:	68 a0 84 04 08       	push   $0x80484a0
 80482f0:	68 40 84 04 08       	push   $0x8048440
 80482f5:	51                   	push   %ecx
 80482f6:	56                   	push   %esi
 80482f7:	68 db 83 04 08       	push   $0x80483db
 80482fc:	e8 bf ff ff ff       	call   80482c0 <__libc_start_main@plt>
 8048301:	f4                   	hlt    
 8048302:	66 90                	xchg   %ax,%ax
 8048304:	66 90                	xchg   %ax,%ax
 8048306:	66 90                	xchg   %ax,%ax
 8048308:	66 90                	xchg   %ax,%ax
 804830a:	66 90                	xchg   %ax,%ax
 804830c:	66 90                	xchg   %ax,%ax
 804830e:	66 90                	xchg   %ax,%ax

08048310 <__x86.get_pc_thunk.bx>:
 8048310:	8b 1c 24             	mov    (%esp),%ebx
 8048313:	c3                   	ret    
 8048314:	66 90                	xchg   %ax,%ax
 8048316:	66 90                	xchg   %ax,%ax
 8048318:	66 90                	xchg   %ax,%ax
 804831a:	66 90                	xchg   %ax,%ax
 804831c:	66 90                	xchg   %ax,%ax
 804831e:	66 90                	xchg   %ax,%ax

08048320 <deregister_tm_clones>:
 8048320:	b8 27 a0 04 08       	mov    $0x804a027,%eax
 8048325:	2d 24 a0 04 08       	sub    $0x804a024,%eax
 804832a:	83 f8 06             	cmp    $0x6,%eax
 804832d:	76 1a                	jbe    8048349 <deregister_tm_clones+0x29>
 804832f:	b8 00 00 00 00       	mov    $0x0,%eax
 8048334:	85 c0                	test   %eax,%eax
 8048336:	74 11                	je     8048349 <deregister_tm_clones+0x29>
 8048338:	55                   	push   %ebp
 8048339:	89 e5                	mov    %esp,%ebp
 804833b:	83 ec 14             	sub    $0x14,%esp
 804833e:	68 24 a0 04 08       	push   $0x804a024
 8048343:	ff d0                	call   *%eax
 8048345:	83 c4 10             	add    $0x10,%esp
 8048348:	c9                   	leave  
 8048349:	f3 c3                	repz ret 
 804834b:	90                   	nop
 804834c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

08048350 <register_tm_clones>:
 8048350:	b8 24 a0 04 08       	mov    $0x804a024,%eax
 8048355:	2d 24 a0 04 08       	sub    $0x804a024,%eax
 804835a:	c1 f8 02             	sar    $0x2,%eax
 804835d:	89 c2                	mov    %eax,%edx
 804835f:	c1 ea 1f             	shr    $0x1f,%edx
 8048362:	01 d0                	add    %edx,%eax
 8048364:	d1 f8                	sar    %eax
 8048366:	74 1b                	je     8048383 <register_tm_clones+0x33>
 8048368:	ba 00 00 00 00       	mov    $0x0,%edx
 804836d:	85 d2                	test   %edx,%edx
 804836f:	74 12                	je     8048383 <register_tm_clones+0x33>
 8048371:	55                   	push   %ebp
 8048372:	89 e5                	mov    %esp,%ebp
 8048374:	83 ec 10             	sub    $0x10,%esp
 8048377:	50                   	push   %eax
 8048378:	68 24 a0 04 08       	push   $0x804a024
 804837d:	ff d2                	call   *%edx
 804837f:	83 c4 10             	add    $0x10,%esp
 8048382:	c9                   	leave  
 8048383:	f3 c3                	repz ret 
 8048385:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 8048389:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

08048390 <__do_global_dtors_aux>:
 8048390:	80 3d 24 a0 04 08 00 	cmpb   $0x0,0x804a024
 8048397:	75 13                	jne    80483ac <__do_global_dtors_aux+0x1c>
 8048399:	55                   	push   %ebp
 804839a:	89 e5                	mov    %esp,%ebp
 804839c:	83 ec 08             	sub    $0x8,%esp
 804839f:	e8 7c ff ff ff       	call   8048320 <deregister_tm_clones>
 80483a4:	c6 05 24 a0 04 08 01 	movb   $0x1,0x804a024
 80483ab:	c9                   	leave  
 80483ac:	f3 c3                	repz ret 
 80483ae:	66 90                	xchg   %ax,%ax

080483b0 <frame_dummy>:
 80483b0:	b8 10 9f 04 08       	mov    $0x8049f10,%eax
 80483b5:	8b 10                	mov    (%eax),%edx
 80483b7:	85 d2                	test   %edx,%edx
 80483b9:	75 05                	jne    80483c0 <frame_dummy+0x10>
 80483bb:	eb 93                	jmp    8048350 <register_tm_clones>
 80483bd:	8d 76 00             	lea    0x0(%esi),%esi
 80483c0:	ba 00 00 00 00       	mov    $0x0,%edx
 80483c5:	85 d2                	test   %edx,%edx
 80483c7:	74 f2                	je     80483bb <frame_dummy+0xb>
 80483c9:	55                   	push   %ebp
 80483ca:	89 e5                	mov    %esp,%ebp
 80483cc:	83 ec 14             	sub    $0x14,%esp
 80483cf:	50                   	push   %eax
 80483d0:	ff d2                	call   *%edx
 80483d2:	83 c4 10             	add    $0x10,%esp
 80483d5:	c9                   	leave  
 80483d6:	e9 75 ff ff ff       	jmp    8048350 <register_tm_clones>

080483db <main>:
 80483db:	8d 4c 24 04          	lea    0x4(%esp),%ecx
 80483df:	83 e4 f0             	and    $0xfffffff0,%esp
 80483e2:	ff 71 fc             	pushl  -0x4(%ecx)
 80483e5:	55                   	push   %ebp
 80483e6:	89 e5                	mov    %esp,%ebp
 80483e8:	51                   	push   %ecx
 80483e9:	83 ec 04             	sub    $0x4,%esp
 80483ec:	e8 0e 00 00 00       	call   80483ff <swap>
 80483f1:	b8 00 00 00 00       	mov    $0x0,%eax
 80483f6:	83 c4 04             	add    $0x4,%esp
 80483f9:	59                   	pop    %ecx
 80483fa:	5d                   	pop    %ebp
 80483fb:	8d 61 fc             	lea    -0x4(%ecx),%esp
 80483fe:	c3                   	ret    

080483ff <swap>:
 80483ff:	55                   	push   %ebp
 8048400:	89 e5                	mov    %esp,%ebp
 8048402:	83 ec 10             	sub    $0x10,%esp
 8048405:	c7 05 28 a0 04 08 1c 	movl   $0x804a01c,0x804a028
 804840c:	a0 04 08 
 804840f:	a1 20 a0 04 08       	mov    0x804a020,%eax
 8048414:	8b 00                	mov    (%eax),%eax
 8048416:	89 45 fc             	mov    %eax,-0x4(%ebp)
 8048419:	a1 20 a0 04 08       	mov    0x804a020,%eax
 804841e:	8b 15 28 a0 04 08    	mov    0x804a028,%edx
 8048424:	8b 12                	mov    (%edx),%edx
 8048426:	89 10                	mov    %edx,(%eax)
 8048428:	a1 28 a0 04 08       	mov    0x804a028,%eax
 804842d:	8b 55 fc             	mov    -0x4(%ebp),%edx
 8048430:	89 10                	mov    %edx,(%eax)
 8048432:	90                   	nop
 8048433:	c9                   	leave  
 8048434:	c3                   	ret    
 8048435:	66 90                	xchg   %ax,%ax
 8048437:	66 90                	xchg   %ax,%ax
 8048439:	66 90                	xchg   %ax,%ax
 804843b:	66 90                	xchg   %ax,%ax
 804843d:	66 90                	xchg   %ax,%ax
 804843f:	90                   	nop

08048440 <__libc_csu_init>:
 8048440:	55                   	push   %ebp
 8048441:	57                   	push   %edi
 8048442:	56                   	push   %esi
 8048443:	53                   	push   %ebx
 8048444:	e8 c7 fe ff ff       	call   8048310 <__x86.get_pc_thunk.bx>
 8048449:	81 c3 b7 1b 00 00    	add    $0x1bb7,%ebx
 804844f:	83 ec 0c             	sub    $0xc,%esp
 8048452:	8b 6c 24 20          	mov    0x20(%esp),%ebp
 8048456:	8d b3 0c ff ff ff    	lea    -0xf4(%ebx),%esi
 804845c:	e8 2b fe ff ff       	call   804828c <_init>
 8048461:	8d 83 08 ff ff ff    	lea    -0xf8(%ebx),%eax
 8048467:	29 c6                	sub    %eax,%esi
 8048469:	c1 fe 02             	sar    $0x2,%esi
 804846c:	85 f6                	test   %esi,%esi
 804846e:	74 25                	je     8048495 <__libc_csu_init+0x55>
 8048470:	31 ff                	xor    %edi,%edi
 8048472:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 8048478:	83 ec 04             	sub    $0x4,%esp
 804847b:	ff 74 24 2c          	pushl  0x2c(%esp)
 804847f:	ff 74 24 2c          	pushl  0x2c(%esp)
 8048483:	55                   	push   %ebp
 8048484:	ff 94 bb 08 ff ff ff 	call   *-0xf8(%ebx,%edi,4)
 804848b:	83 c7 01             	add    $0x1,%edi
 804848e:	83 c4 10             	add    $0x10,%esp
 8048491:	39 f7                	cmp    %esi,%edi
 8048493:	75 e3                	jne    8048478 <__libc_csu_init+0x38>
 8048495:	83 c4 0c             	add    $0xc,%esp
 8048498:	5b                   	pop    %ebx
 8048499:	5e                   	pop    %esi
 804849a:	5f                   	pop    %edi
 804849b:	5d                   	pop    %ebp
 804849c:	c3                   	ret    
 804849d:	8d 76 00             	lea    0x0(%esi),%esi

080484a0 <__libc_csu_fini>:
 80484a0:	f3 c3                	repz ret 

Disassembly of section .fini:

080484a4 <_fini>:
 80484a4:	53                   	push   %ebx
 80484a5:	83 ec 08             	sub    $0x8,%esp
 80484a8:	e8 63 fe ff ff       	call   8048310 <__x86.get_pc_thunk.bx>
 80484ad:	81 c3 53 1b 00 00    	add    $0x1b53,%ebx
 80484b3:	83 c4 08             	add    $0x8,%esp
 80484b6:	5b                   	pop    %ebx
 80484b7:	c3                   	ret    
