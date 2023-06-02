! epilogs for void _init/_fini(void) functions.

.section .init
    ret.f 0
    nop 123
    nop 123

.section .fini
    ret.f 0
    nop 123
    nop 123
