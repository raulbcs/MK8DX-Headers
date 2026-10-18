# object::Vt12cba38

PLACEHOLDER name (identity not proven). vptr 0x12cba38, 87 slots, typeinfo NULL (game-side). GOT cell 0x1310858.

Relationship: derived class of Vt12b63f0. Slots 0x04-0x56 and 0x2D-0x56 overlap the base table's implementations (same function addresses, e.g. 0x6acfc4, 0x6af998, 0x6ad930-0x6afb8c, 0x6ecba4/0x6ecc34, 0x6adbdc-0x6adf98). Both tables share the secondary-base subtable at base-vt+0x2C8, installed at [this+0xB8].

## Member notes

- [this+0x2F0] u64, zeroed at 0x828EA8 (C2 0x828E84).
- [this+0x2F8] u64, zeroed at 0x828EBC.
- [this+0x300] u64, zeroed at 0x828E98.
- [this+0x308], [this+0x310], [this+0x318] s64 = -1 (0x828EA4/0x828EB0/0x828EC8).
- Everything below 0x2F0 belongs to the Vt12b63f0 base layout.

## Construction / init order

- C2 = FUN_7100828E84 (0x828E84): calls base C2 0x6ABF6C, then zeroes 0x2F0/0x2F8/0x300 and writes -1 to 0x308/0x310/0x318, finally stores primary vptr 0x12CBA38 at [this+0x00] and secondary 0x12CBA38+0x2C8 at [this+0xB8] (0x828EB4-0x828EC4).
- Factory: FUN at 0x821408 — allocFromHeapOrDefault_710060B234 with size 0x320, then C2 0x828E84 (0x821414-0x82141C). Immediately before, the same function looked up "GSysMii" / "GSysMiiFaceOnly" (strings 0xF0C06E/0xF0C076) via FUN_71008215D8 — Mii association is contextual, unverified.
- D1 thunk FUN_7100828ED8 (0x828ED8): restores both vptrs then tail-calls base D2 0x6AC01C.
