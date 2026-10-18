# object::Vt12dcaf0

PLACEHOLDER name (identity not proven). Composite class, size 0x58 exact: primary
vtable row 0x12dcaf0 (installed vptr 0x12dcaf8, row-0x8 = 0x12dcae8 held in GOT
cell 0x1313410 — cell+0x10 convention) plus a secondary row 0x12dcb20
(offset-to-top -0x18 at 0x12dcb20, installed vptr 0x12dcb30 = cell+0x48) stored
at this+0x18. Row 0x12dcaf0 starts with a descriptor pointer 0x12dcb50
(struct {0x10, table 0xf80e20, ...} — game-rolled descriptor, not Itanium
typeinfo; interpretation unverified).

## Member notes

- Primary slots (vptr 0x12dcaf8): 0x975138 (D1 complete dtor: member dtor 0x92a014 on +0x20/+0x28/+0x30/+0x38, clears +0x40, reinstalls both vptrs, tail-calls base dtor 0xb4a58c), 0x9751f8 (D0 deleting dtor, same body; tail unverified), 0x9752e4 (process/handler: reads flag [this+8], derefs [this+0x50] → [+0x50], error 0xc0710000 paths; 232B), 0x9755d0 (serialize-out: rejects len w2 >= 0xc with 0xc0710000, reads [x3+0x620], memcpy 8B from x3+0x14), 0x9752d8 (setter: [this+0x40] = x1, [x8] = 0).
- Secondary slots (vptr 0x12dcb30): 0x975198, 0x975260, 0x9755c8 (thunk sub x0,#0x18 → 0x9752e4, confirming offset-to-top -0x18), 0x97563c (variant of 0x9755d0).
- Subobjects at +0x20..+0x3C (4 pointers): ctor 0x929fd4, dtor 0x92a014.
- Fields: +0x08 byte flag, +0x40 pointer (nulled by dtors), +0x48 byte, +0x50 pointer.

## Construction / init order

- Factory at 0x96cd6c: operator new(0x58, align 8) at 0x96cd78 (0x568aa0), then ctor 0x9750d4 at 0x96cd88.
- Ctor 0x9750d4: base ctor call 0xb4a570; loads GOT cell 0x1313410; stores cell+0x10 (0x12dcaf8) at [this], cell+0x48 (0x12dcb30) at [this+0x18]; runs member ctor 0x929fd4 on this+0x20/+0x28/+0x30/+0x38; zeroes +0x50, +0x40, byte +0x48.
