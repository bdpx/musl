/* Copyright 2011-2012 Nicholas J. Kain, licensed under standard MIT license */
.text
.global __unmapself
.hidden __unmapself
.type __unmapself,@function
__unmapself:
.L__unmapself$local:
.type .L__unmapself$local,@function
	alloc 3
	ld_imm %r1,11      /* SYS_munmap */
	syscall         /* munmap(arg2,arg3) */
	ld_imm %r2,0       /* exit() args: always return success */
	ld_imm %r1,60      /* SYS_exit */
	syscall         /* exit(0) */

.Lfunc_end0:
	.size	__unmapself, .Lfunc_end0-__unmapself
	.size	.L__unmapself$local, .Lfunc_end0-__unmapself
