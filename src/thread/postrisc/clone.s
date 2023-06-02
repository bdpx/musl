.text
.global __clone
.hidden __clone
.type __clone,@function
__clone:
.L__clone$local:
.type .L__clone$local,@function
/*
	xor %eax,%eax
	mov $56,%al
	mov %rdi,%r11
	mov %rdx,%rdi
	mov %r8,%rdx
	mov %r9,%r8
	mov 8(%rsp),%r10
	mov %r11,%r9
	and $-16,%rsi
	sub $8,%rsi
	mov %rcx,(%rsi)
	syscall
	test %eax,%eax
	jnz 1f
	ld_imm %fp,0
	pop %rdi
	call *%r9
	mov %eax,%edi
	ldi %r2,0
	ldi %r1,60
	syscall
*/
	halt
	retf 0
	nop 0

.Lfunc_end0:
	.size	__clone, .Lfunc_end0-__clone
	.size	.L__clone$local, .Lfunc_end0-__clone
