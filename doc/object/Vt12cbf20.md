# object::Vt12cbf20

PLACEHOLDER name (identity not proven). vptr 0x12cbf20, 90 slots, typeinfo NULL (game-side). GOT cell 0x1310920.

Single inheritance (only a primary vptr is installed). Slot addresses sit at 0x55Bxxx-0x55Cxxx and 0x82Dxxx-0x82Dxxx; a few slots carry sead symbol names in functions.csv (0x7C8-0x7D0, e.g. sead::PatternRumbleAddon::isPatternEnable, sead::ExpHeap::isFreeable) — those are vendor-side namings of nearby addresses and their linkage to this class is unverified.

## Member notes

- [this+0x5B0] u32 — element/loop count (C2 0x82D8C0; D1 iterates it at 0x82D9CC-0x82DA00).
- [this+0x5B8] ptr to a pointer table, [this+0x5C0] ptr, [this+0x5C8] ptr — pool arrays allocated by C2: 200-entry (count passed in w2, caller 0x37DEE0 passes 200) blocks of stride-0x20 nodes linked into a free list (0x82D8D4-0x82D96C).
- [this+0x5D0] u32 = 0 (C2 0x82D8A8), [this+0x5D1] u16 and [this+0x5D3] u8 reset by D1 (0x82DA04-0x82DA10).
- Deepest store 0x5D3; extent cited as 0x5D4 (unverified exact).

## Construction / init order

- C2/C1 = FUN_710082D880: calls 0x55A864 with (8, 0x1C, 0xC), stores primary vptr 0x12CBF20 (0x82D8AC-0x82D8CC), zeroes 0x5B0-0x5D0, builds the free-list pool for the w2 count.
- D1 = FUN_710082D98C (slot 0): resets via 0x55AE80, virtual calls +0x150/+0x128, zeroes 0x5B0-0x5D3.
