! epilogs for void _init/_fini(void) functions.

.section .init
    retf 0
    nop 123
    nop 123

.section .fini
    retf 0
    nop 123
    nop 123
