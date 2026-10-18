# PrudpInstance (PROVISIONAL)

- vtable 0x12e3880-family; fn row at 0x12e3888 (35 slots). GOT cell 0x1314750
  holds 0x12e3878 = row-0x10; sites 0xa0bd44 (C1) and 0xa0c14c (D2).
- Name: slot 8 thunk (0xa0ca50) returns the literal string "prudp" (0xf148e3);
  nearby code carries the path "..\OnlineCore/src/Core/InstanceTable.h"
  (0xef293c). No MethodTree string found; name stays PROVISIONAL.

## Member notes

| Offset | Field | Evidence |
|---|---|---|
| 0x00 | vptr | 0x12e3888, ctor 0xa0bd44 / D2 0xa0c14c |
| 0x10/0x18 | head/arg | ctor 0xa0bd2c (`stp xzr, x21`) |
| 0x20..0x23 | zeroed scalars | ctor 0xa0bd28/0xa0bd38 |
| 0x30/0x40/0x80 | intrusive list nodes (self ptrs) | ctor 0xa0bd5c/0xa0bd74/0xa0bd88 |
| 0x90..0xb0 | bidirectional node pair | ctor 0xa0bd94..0xa0bd9c |
| 0xd0..0x1b8 | state; +0x178 guarded by vtable lock/unlock | slots 0xa101b8/0xa101d4 call nn::os Lock/UnlockMutex on `this+0x178` |

Slots resolve to FUN_7100a0xxxx/0x9e4xxxx (all unrecovered in functions.csv
except by address); slot 6 (0x9e4970, 3684 B) initializes an event-like object
via 0x5788e0 with code 0x0e0001.

## Construction / init order

- Factory FUN_7100a2e5b4: `operator new(0x1B8)` (0xa2e5f8, allocator
  0x573f04), then C1 0xa0bcfc(this, [parent+0x48], [parent+0x40], flags bit0)
  at 0xa2e644/0xa2e6ac; result stored at parent+0x18 (bit0 set) or parent+0x10
  (bit2 set); registered into the parent container (0x9e3ca8) at parent+0x30
  (a 0x130-byte object built by 0x9e3570).
- C1 0xa0bcfc: base ctor 0x9e4484, zeroes fields, installs vptr, builds member
  at +0x178 region; second pass 0x9e4610 then final vptr store.
- D2 0xa0c134: installs vptr, walks the parent container (cells
  0x130b528/0x130b530/0x130b538).
