# ServiceClient

## Identity

- RTTI name (nex typeinfo descriptor 0x12e73c0, string at .rodata 0xf85db0): `nn::nex::ServiceClient`, base descriptor 0x128c3b0 = `nn::nex::RootObject` (same base as the ConnectionData family, typeinfo vtable cell pattern 0x12e6790).
- Vtable row 0x12e7360 (typeinfo slot), installed vptr 0x12e7368. GOT cell 0x1314b58 holds vptr-0x10; sites 0xa3287c (D2) and 0xa326e0 (C1).
- 8 slots: D2 0xa32868 (reinstalls vptr, atomically decrements the refcount at [this+0x10]+8 and releases), 0xa41c2c, 0xa41cdc, 0xa41ce0, 0xa41ef4, 0xa420dc, 0xa421d8, 0xa42250. All unresolved in functions.csv; no D0/operator-delete tail visible in the slot-0 body (derived classes override further).

## Member notes

- +0x00 vptr (0x12e7368).
- +0x08 u32 — C1 0xa326c8 stores the w1 argument (id/flag, unverified semantics).
- +0x10 u64 — null-initialized pointer; D2 treats it as a refcounted handle (lock-decrement of [ptr+8]).
- +0x18 u8 — zeroed by C1.

## Construction / init order

C1 0xa326c8: store w1 -> +0x08, xzr -> +0x10, 0 -> +0x18 (byte), then install vptr 0x12e7368 at +0x00 (cell 0x1314b58 + 0x10). No member constructors called in the C1 body — base-class layout only.

Size: lower bound 0x20 (highest store is the byte at +0x18). ServiceClient is a base class; concrete service clients derived from it are larger — unverified here.
