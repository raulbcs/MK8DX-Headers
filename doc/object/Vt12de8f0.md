# object::Vt12de8f0

PLACEHOLDER name (identity not proven). Stack-constructed packet-like object
carrying a 0x10-byte payload. Primary row 0x12de8f0 (installed vptr 0x12de8f8;
GOT cell 0x1313a30 addend 0x12de8e8 = row-0x8, cell+0x10 convention). Row head
points to descriptor 0x12de920 (struct {0x10, table 0xf81f30, 0x12dd558, ...} —
game-rolled descriptor, interpretation unverified).

## Member notes

- Slots (vptr 0x12de8f8): 0x97da50 (D1, trivial `ret`), 0x99f47c (D0 deleting dtor — tail-jumps operator delete 0x60b470), 0x99f3d0 (serialize-out: writes bytes of [this+8] qword into out buffer x1, null-arg checks → error 0xc0710000), 0x99f0ec (168B parse/build: takes src x1 = arg+0x18, writes through x8 out-param), 0x99f480 (returns 0x10 — payload size getter).
- Fields: +0x08 qword payload, +0x10 word. Lower-bound footprint 0x18 (vptr + payload + word).
- Consumed by FUN_710099ee00 (300B) and FUN_710099ef2c (448B); those construct the object on the stack ([sp+8]/[sp+0x10] = vptr), so no operator-new extent exists — lower bound only.

## Construction / init order

- Stack construction: vptr 0x12de8f8 (cell 0x1313a30 + 0x10) stored at [sp+8] at 0x99ed60-0x99ed80 and at [sp+0x10] in 0x99ef2c (0x99ef44-0x99ef50); then slot 0x99f0ec fills the payload from a source descriptor at [arg+8]+0x18.
- No heap factory found for this row (cell has exactly two text references, both stack sites).
