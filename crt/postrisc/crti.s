! prologs for void _init/_fini(void) functions.

.section .init
.global _init
_init:
    alloc 10
    nop 123
    nop 123

.section .fini
.global _fini
_fini:
    alloc 10
    nop 123
    nop 123
