# game::Vt12f6bc0

PLACEHOLDER name (identity not proven). Assigned address 0x12f6bc0 is the
typeinfo slot of the secondary-base vtable; installed vptr = 0x12f6bc8
(row = assigned+8, vt-8 convention). Typeinfo target 0x12F72E0, shared with the
primary table 0x12f6b30 of the same complete class.

## Identity

- Complete-object size 0x2D0: `operator new(0x2D0)` at 0xB18690 inside the
  construction helper at 0xB18690's enclosing function (unverified C1).
- GOT cell 0x1315920 holds primary_row-0x10 = 0x12F6B20 (vt-0x10 convention);
  ctor stores [this] = cell+0x10 = 0x12f6b30 and [this+0xA0] = cell+0xA8 =
  0x12f6bc8 (0xB186B0-0xB186E8).
- Primary D1 = 0xB25264 (restores both vptrs from the cell, deletes
  [this+0xB8]); primary D0 = 0xB25370.
- Secondary D1 counterpart: 0xB25278.

## Secondary table 0x12f6bc8 (6 slots)

| slot | addr | notes |
| --- | --- | --- |
| 0 | 0xB25368 | D1 thunk, unrecovered (absent from functions.csv) |
| 1 | 0xB25394 | FUN_7100B25394, 0x40 bytes |
| 2 | 0xB26444 | FUN_7100B26444, 8 bytes (O) |
| 3 | 0xB38B94 | FUN_7100B38B94, 0x20 bytes (shared secondary slot) |
| 4 | 0xB265B4 | FUN_7100B265B4, 8 bytes (O) |
| 5 | 0xB267FC | thunk `this-0xA0`, tail-calls 0xB265BC (FUN_7100B265BC, 0x584 bytes) |

Primary table 0x12f6b30: D1 0xB25264, D0 0xB25370, shared block
(0x5917A0...), then class-specific overrides 0xB253BC, 0xB262C0, 0xB2644C,
0xB265BC.

## Construction / init order

- Ctor: new 0x2D0; zero [this+0xA8], [this+0xB0]; byte 1 to [this+0xC0];
  zero [this+0xC8..0xE7], [this+0xE8], [this+0xF0..0xFF]; install vptrs
  0xB186B0-0xB186E8; member init at [this+0x100]/[this+0x1F0]/[this+0x200]/
  [this+0x268] follows (0xB186EC-0xB18708).
- Sibling classes sharing the shape: Vt12f6ae8 (size 0x2B0, cell 0x1315960)
  and Vt12f6c98 (size 0x320, cell 0x1315900).
