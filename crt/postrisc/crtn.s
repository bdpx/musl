.section .init
/*	pop %rax
	ret
*/
	alloc 3
	retf 0
	nop 0

.section .fini
/*	pop %rax
	ret
*/
	alloc 3
	retf 0
	nop 0
