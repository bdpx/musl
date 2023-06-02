/*
.text
.global dlsym
.hidden __dlsym
.type dlsym,@function
dlsym:
	mov (%rsp),%rdx
	jmp __dlsym
;;	ldz.d	%r2,%sp,0
;;	jmp	__dlsym
*/
