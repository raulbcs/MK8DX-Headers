# nn::nex::JobTicketManagerLogin

## Identity

- RTTI-confirmed: typeinfo slot 0x12e6af8, typeinfo struct 0x12e7460, name
  "N2nn3nex21JobTicketManagerLoginE". Row layout: typeinfo slot holds the
  typeinfo pointer; installed vptr = 0x12e6b00 (assigned + 8); offset-to-top 0
  at 0x12e6af0. GOT cell 0x1314ba8 holds 0x12e6af0 (vptr-0x10); installed
  vptr = cell + 0x10.
- 13 slots (0x12e6b00..0x12e6b60): slot0 = D1 0xa3473c (168 B, csv
  FUN_7100a3473c), slot1 = D0 0xa347c0 (calls D1, tail operator delete
  0x573f48), slots 2..12 are the shared nn::nex job block 0x5917a0 (vt+0x18
  secondary dispatch) / 0x58ff6c / 0x5917ac / 0x590148 / 0x59014c / 0x5917b0 /
  0x5917cc / 0x58b7d8 / 0x5917d4 / 0x5917d8 / 0x59189c.
- Base init 0x588b04(this, 2, scratch) — nn::nex::ForcedCriticalSection base
  region 0x08..0xa0 (secondary vptr at +0x78).

## Member notes

- Size 0x2e8 PROVEN: factory FUN_7100a32c28 news 0x2e8 via 0x573f04
  (0xa32d84..0xa32d8c) then tail-calls the ctor at 0xa32dbc.
- Ctor FUN_7100a343d0 (0x20c) stores: +0xa0 = arg w1 (id), +0xa8 = arg x2,
  +0xb0 = vptr from cell 0x130b740 (secondary base), +0xb8 release-flag 1
  (stlr), +0xbc..+0x100 zeros, +0xd0 self-pointer pair, +0x108 subobject init
  (0x5788e0), +0x120..+0x138 zeros, +0x140 subobject init (0x58b7dc), +0x168
  vptr from cell 0x130b4a8, +0x170 flag zero / +0x180 pair = 0x10, +0x1a0/+0x1a8
  args, +0x1b0 arg, +0x1b8 subobject init (0xa2bf88), +0x190 = 0, +0x278 = vptr
  from cell 0x130b618, +0x280 release-flag 1, +0x2b8 vptr from cell 0x130b4a8
  (written by D1; also initialized late in the ctor).
- D1 0xa3473c reinstalls vptr, releases [+0x190] (ptr-4 via 0x5763ac when
  non-null), destroys members at +0x2b8 (cell 0x130b4a8 reinstalled), +0x278
  (0x5790b4), +0x1b8 (0xa2c1e8), +0x168 (0x5790b4), +0x140 (0x58bc04), +0xb0
  (0x585ae0).

## Construction / init order

1. Factory FUN_7100a32c28: `mov w0, #0x2e8; bl 0x573f04` (0xa32d84), null
   check, arg marshalling (8 args + 2 stack), `bl 0xa343d0` (0xa32dbc).
2. Ctor: ForcedCriticalSection base init 0x588b04 (0xa3441c), then vptr store
   (0xa34424..0xa34430) and the field writes listed above in ascending order.

Size 0x2e8 proven by the factory allocation.
