# nn::pia::inet::NexMatchCreateSessionJob

RTTI-confirmed via typeinfo name `N2nn3pia4inet24NexMatchCreateSessionJobE` (0xf7f1a0). Vtable 0x12dada0 is a typeinfo-row vtable: GOT cell 0x1312c98 holds vptr-0x10, installed vptr 0x12dada8; the word at 0x12dada0 points to the embedded typeinfo pair {0x10, name-ptr} at 0x12dada0+0x60 (0x12dae00). Offset-to-top at 0x12dad98 is 0. 10 slots at vptr+0x00..+0x48; slots 2-4 are the shared job overrides 0xb4a654 / 0xb4a67c / 0x933314 (same set as NexMatchJoinSessionJob).

## Member notes

- Ctor 0x93dd60 (unrecovered in functions.csv): calls base C1 0x97e8f4, then zeroes [this+0x88] (w), [this+0xa8] (q), [this+0xb0] (b), [this+0xb8] (q) and installs the vptr.
- Base C1 0x97e8f4 (vptr cell 0x13136a8, vptr 0x12dd988, slot0 0x97e934): zeroes [this+0x58], inits the member at +0x60 via 0x929ec0, zeroes [this+0x80] (w).
- Size: lower bound 0xc0 from the deepest ctor store (+0xb8 qword). No operator-new site exists - the class is never constructed in the binary (the ctor has zero code references and no relocation points at it); treated as linked-but-unused SDK code.

## Construction / init order

1. Base C1 0x97e8f4 (fields +0x58/+0x60/+0x80).
2. Ctor 0x93dd60: vptr install, then the zero stores above.
No construction sites found (unverified order end-to-end).
