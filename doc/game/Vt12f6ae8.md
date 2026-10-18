# game::Vt12f6ae8

PLACEHOLDER name (identity not proven). Assigned address 0x12f6ae8 is the
typeinfo slot of the secondary-base vtable; installed vptr = 0x12f6af0
(row = assigned+8, vt-8 convention). Typeinfo target 0x12f7290, shared with the
primary table 0x12f6a58 of the same complete class.

## Identity

- Complete-object size 0x2B0: `operator new(0x2B0)` at 0xB197D8 inside the
  construction helper at 0xB19764 (unverified whether that is the C1).
- GOT cell 0x1315960 holds primary_row-0x10 = 0x12f6a48 (vt-0x10 convention);
  ctor computes [this] = cell+0x10 = 0x12f6a58 and [this+0xA0] = cell+0x98+0x10
  = 0x12f6af0 (0xB197FC-0xB19834).
- Primary D1 = 0xB23E98 (resets both vptrs, then tears down members);
  primary D0 = 0xB23F78.
- Only install site found: 0xB197FC; the D1 counterpart is 0xB23EA4.

## Secondary table 0x12f6af0 (6 slots)

| slot | addr | notes |
| --- | --- | --- |
| 0 | 0xB23F70 | D1 thunk, unrecovered (absent from functions.csv) |
| 1 | 0xB23F9C | FUN_7100B23F9C, 0x40 bytes |
| 2 | 0xB25118 | FUN_7100B25118, 8 bytes (O) |
| 3 | 0xB38B94 | FUN_7100B38B94, 0x20 bytes (shared with Vt12f6bc0/Vt12f6c98 secondary slot 3) |
| 4 | 0xB25128 | unrecovered (absent) |
| 5 | 0xB2525C | thunk `this-0xA0`, tail-calls 0xB25130 (FUN_7100B25130, 0x308 bytes) |

Primary table 0x12f6a58 carries the class-specific overrides after a shared
slot block (0xB23FC4, 0xB25008, 0xB25120, 0xB25130, ...).

## Construction / init order

- 0xB19764 (helper): new 0x2B0 at 0xB197D8; zero [this+0xA8], [this+0xB0],
  [this+0xC0]; install vptrs 0xB197FC-0xB19834; string field initialized at
  0xB19850 (limit 0x80 checked at 0xB251CC in slot-5 target 0xB25130).
- D1 0xB23E98: delete [this+0xB8] guard, restore [this] / [this+0xA0] from the
  same GOT cell, destroy [this+0x268] list (0xB23ED4-0xB23F04).
- Sibling classes sharing the shape: Vt12f6bc0 (size 0x2D0, cell 0x1315920) and
  Vt12f6c98 (size 0x320, cell 0x1315900).
