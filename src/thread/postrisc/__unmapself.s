/* Copyright 2011-2012 Nicholas J. Kain, licensed under standard MIT license */
.text
.global __unmapself
.type   __unmapself,@function
__unmapself:
	alloc 3
	ldi %r1,11      /* SYS_munmap */
	syscall         /* munmap(arg2,arg3) */
	ldi %r2,0       /* exit() args: always return success */
	ldi %r1,60      /* SYS_exit */
	syscall         /* exit(0) */
