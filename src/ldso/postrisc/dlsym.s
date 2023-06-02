/*
.text
.global dlsym
.hidden __dlsym
.type dlsym,@function
dlsym:
	mov (%rsp),%rdx
	jmp __dlsym
;;	ld_u64 %r2,%sp,0
;;	jmp __dlsym
*/
