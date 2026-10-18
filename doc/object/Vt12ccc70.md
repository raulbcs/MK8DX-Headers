# object::Vt12ccc70

PLACEHOLDER name (identity not proven). vptr 0x12ccc70, 71 slots. GOT cell 0x1310b08 holds vptr-0x10 (cell+0x10 = installed vptr; the row address IS the vptr).

Exactly 0x130 bytes; allocated by factory FUN at 0x83F570 (`new 0x130` at 0x83F580, stored to a manager at [x19+0x2C0]).

## Member notes

- [this+0x00] vptr 0x12ccc70 (0x841B18).
- [this+0x70]/[this+0x78]/[this+0x80]/[this+0x88]/[this+0x98] zeroed by C1 (0x841B08-0x841B1C).
- [this+0x9C] u8 flags: C1 computes `1 << w` from a stack input (0x841B28-0x841B3C, unverified semantics).
- [this+0xA0] inlined sub-object: vptr 0x12ccfd8 (cell 0x1310b10), [+0xA8] = 0 (0x841B6C).
- [this+0xC8] inlined sub-object (init via FUN_710061CC48 at 0x841B7C): vptr 0x12cdd08 (cell 0x1310da0+0x10) at [x19+0xC8], u32 0x10 at +0xD8, self-pointer chain: [this+0xD0] = this+0xDC (0x841B64), byte from cell 0x1310da8 copied to [this+0xD0] target (0x841B90-0x841BA4).
- Second inlined sub-ctor at this+0x100 (0x841B9C-0x841BB8, vptr cell 0x1310da8+0x10 = 0x12cdd38) — 0x130-0x12C region belongs to these sub-objects.

## Construction / init order

- C1 = FUN at 0x841AE4: base init FUN_7100841C00 (0x841AFC), zeroing, primary vptr (0x841B18), flags byte, then the two inlined member sub-ctors at +0xC8/+0x100 (0x841B7C/0x841BB8).
- All 71 slots resolve to functions in the 0x841xxx-0x848xxx range; none is in config/functions.csv (all unlisted/unrecovered).
- Factory 0x83F570 allocates 0x130 (0x83F580), calls C1 (0x83F58C), stores the object at [x19+0x2C0], then immediately `new 0x158` (0x83F590, next member at +0x2C8).
