# object::Vt12cfa80

PLACEHOLDER name (identity not proven). Animation-timing/interpolation controller sibling of 0x12cfb88 (same slot skeleton, same ctor shape). vptr 0x12cfa80, 31 slots (+0x00..+0xf0), typeinfo NULL. GOT cell 0x1310f30 holds vt-0x10; installed vptr = cell+0x10. Base-ctor vptr cell is 0x13100f28 (no RELA; runtime cell, not resolved in file).

## Member notes

- +0x08: config object ptr (ctor arg).
- +0x10: u32 = (cfg->0x10 == 0) << 5 (0 or 0x20).
- +0x14: qword from global [0x12fb148]; +0x1c: u32 from [0x12fb148+8]; +0x20..+0x28: u32 triple from the base-class virtual call result ([vt+8](this, cfg, 0) -> fields +8/+c/+10).
- +0x2c/+0x30: floats = 0.0f; +0x34/+0x38: floats = 1.0f; +0x3c: u16 = 0x1 (loop-mode flag; sibling 0x12cfb88 uses 0x1e); +0x40: float = -1.0f.
- Extent 0x48 from operator new 0x48 at the factory (0x198f34, called for config byte [x8+0xb8] bit6 clear).

## Construction / init order

- Ctor FUN_7100869c74(this, cfg) (0x869c74-0x869d38): installs base vptr [0x13100f28]+0x10, stores cfg at +0x8, copies the globals block, installs final vptr = [0x1310f30]+0x10 = 0x12cfa80, then performs the virtual cfg query and fills +0x20..+0x40.
- Factory: FUN_7100869c74 chosen by the 4-way jump table at 0x198f20 when mode <= 3 and config bit cleared; alternative branches build 0x12cfb88 (new 0x48, ctor 0x86a864) or a third variant (new 0x38, ctor 0x86ad94).
- Also constructed at 0x142ddc path: new 0x48 from a 0x8105ac-returned object's +0x20 (sibling Vt12cfb88 ctor; same shape).
