# eui::ButtonBase

Name proven: slot 0 (FUN 0x739968) returns the literal "ButtonBase" (rodata 0xf071f2); the class-name registry at 0x73aaf4+ strcmp-compares it. Derives eui::ControlBase (base ctor FUN_7100734380; slot layout matches include/eui/ControlBase.hpp: 0x00 getClassName, 0x08 typeinfo, 0x10 dtor, 0x18 update). vptr 0x12bea10, 36 slots (+0x00..+0x118), typeinfo NULL. GOT cell 0x130eb48 holds vt-0x10; installed vptr = cell+0x10.

## Member notes

- 0x30/0x38: self-sentinel list head pair (both = &this+0x30) written by the ctor.
- 0x42: u16 flags = 0x1f; 0x40/0x41: u8 flags = 0.
- 0x44..0x48: tiny inline string - SSO buffer 0x44 (capacity 3), length u32 0x48; accessor FUN at 0x7399c0 reads flags against mask 0x11 and appends bytes into the buffer.
- Extent inference: only known heap allocation is a derived class (ctor FUN_7100738d68 calls the ButtonBase ctor as base, then stores its own vptr from cell 0x130eb40+0x10 and zeros +0x60..+0x70). Derived size is 0x70 (aligned_alloc 0x70 at 0x73ab18, many call sites), so ButtonBase occupies 0x60 - inferred, unverified directly.

## Construction / init order

- Ctor FUN_7100739974(this): base FUN_7100734380; clears 0x40/0x41, zero 0x48, vptr = [0x130eb48]+0x10, sentinel pair 0x30/0x38, flags 0x42 = 0x1f. (0x739974-0x7399bc)
- Slots 0x20..0xb0 (0x73a00c..0x73a280) and 0xb8..0x118 (0x73a3c0..0x73a3c8 tail) are mostly 4-8 byte thunks, unrecovered in functions.csv.
- One consumer family calls vtable slot +0x80 and global 0x734380-adjacent helpers on Flag41 transitions (unverified).
