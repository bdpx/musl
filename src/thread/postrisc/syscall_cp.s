.text
.global __cp_begin
.hidden __cp_begin
.global __cp_end
.hidden __cp_end
.global __cp_cancel
.hidden __cp_cancel
.hidden __cancel
.global __syscall_cp_asm
.hidden __syscall_cp_asm
.type   __syscall_cp_asm,@function
__syscall_cp_asm:
.L__syscall_cp_asm$local:
.type .L__syscall_cp_asm$local,@function
__cp_begin:
/*
	mov (%rdi),%eax
	bne %eax,%gz,__cp_cancel
	mov %rdi,%r11
	mov %rsi,%rax
	mov %rdx,%rdi
	mov %rcx,%rsi
	mov %r8,%rdx
	mov %r9,%r10
	mov 8(%rsp),%r8
	mov 16(%rsp),%r9
	mov %r11,8(%rsp)
*/
	syscall
__cp_end:
	retf 0
__cp_cancel:
	jmp __cancel

.Lfunc_end0:
	.size	__syscall_cp_asm, .Lfunc_end0-__syscall_cp_asm
	.size	.L__syscall_cp_asm$local, .Lfunc_end0-__syscall_cp_asm
