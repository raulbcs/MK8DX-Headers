# object::Vt12cfb88

PLACEHOLDER name (identity not proven). Animation-timing/interpolation controller, sibling of 0x12cfa80 (identical ctor prologue, different tail). vptr 0x12cfb88, 31 slots (+0x00..+0xf0), typeinfo NULL. GOT cell 0x1310f38 holds vt-0x10; installed vptr = cell+0x10. Base vptr cell 0x13100f28 (runtime cell, shared with the sibling).

## Member notes

- +0x08: config object ptr; +0x10: u32 = (cfg->0x10 == 0) << 5; +0x14: qword from global [0x12fb148]; +0x1c: u32 from [0x12fb148+8]; +0x20..+0x28: u32 triple from base virtual query ([vt+8](this, cfg, 0)) - identical to the 0x12cfa80 ctor up to here.
- Timing tail (0x86a924-0x86a95c): +0x44 = 1.0f / cfg->0x50 (inv duration); +0x34 = cfg->0x50 (duration); +0x38 = +0x44 * cfg->0x50 (= 1.0f normalized progress step); +0x3c = 0x1e (vs 0x1 on the sibling); +0x40 = -1.0f; +0x2c/+0x30 = 0.0f.
- Extent 0x48 from operator new 0x48 at both factories (0x198f90 and 0x142dcc).

## Construction / init order

- Ctor FUN_710086a864(this, cfg) (0x86a864-0x86a968): base vptr [0x13100f28]+0x10, cfg -> +0x8, globals copy, final vptr = [0x1310f38]+0x10 = 0x12cfb88, virtual cfg query, then the timing tail above.
- Factories: 0x198f90 (config byte [x8+0xb8] bit6 set -> new 0x48, result -> [manager+0x150]) and 0x142ddc (guarded by bool from 0x8105ac; cfg = [x21+0x20]; result -> [x19+0x60]).
