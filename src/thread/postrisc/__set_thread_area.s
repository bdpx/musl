/* Copyright 2023-2023 licensed under standard MIT license */
.text
.global __set_thread_area
.hidden __set_thread_area
.type __set_thread_area,@function
__set_thread_area:
.L__set_thread_area$local:
.type .L__set_thread_area$local,@function
	mov	%tp, %r1  /* copy r1 to TP */
	ldi	%r1, 0    /* clean error code */
	ret.f	0         /* return */

.Lfunc_end0:
	.size	__set_thread_area, .Lfunc_end0-__set_thread_area
	.size	.L__set_thread_area$local, .Lfunc_end0-__set_thread_area
