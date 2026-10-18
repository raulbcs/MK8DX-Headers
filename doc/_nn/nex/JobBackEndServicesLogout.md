# nn::nex::JobBackEndServicesLogout

## Identity

- RTTI-confirmed: typeinfo slot 0x12e6d38, typeinfo struct 0x12e7660, name
  "N2nn3nex24JobBackEndServicesLogoutE". Installed vptr = 0x12e6d48 (assigned
  slot + 8); offset-to-top 0 at 0x12e6d38. GOT cell 0x1314cc8 holds 0x12e6d38
  (vptr-0x10); installed vptr = cell + 0x10.
- 13 slots (0x12e6d48..0x12e6da8): slot0 = D1 0xa3cb84 (csv FUN_7100a3cb84),
  slot1 = D0 0xa3cbb8 (unrecovered), slots 2..12 are the shared nn::nex job
  block 0x5917a0 / 0x58ff6c / 0x5917ac / 0x590148 / 0x59014c / 0x5917b0 /
  0x5917cc / 0x58b7d8 / 0x5917d4 / 0x5917d8 / 0x59189c.
- Base init 0x588b04(this, 2, scratch) — ForcedCriticalSection base region.

## Member notes

- Size 0x158 PROVEN: factory FUN_7100a36dd0 news 0x158 via 0x573f04
  (0xa36eb4..0xa36ebc) then calls the ctor at 0xa36ed4; the pointer is stored
  to an outer field [+x19+0x108] and refcount-incremented (ldar/stxr pair at
  0xa36edc..0xa36f00).
- Ctor FUN_7100a3c8e0 (0x89c): base init at 0xa3c918, vptr store at
  0xa3c91c..0xa3c920, +0xa0 = arg w1 (id), +0x120 subobject init region.
- D1 0xa3cb84 reinstalls the vptr (site 0xa3cb90) and destroys the +0x120
  member; D0 0xa3cbb8 same plus delete (site 0xa3cbc4; body unrecovered,
  unverified).

## Construction / init order

1. Factory FUN_7100a36dd0: `mov w0, #0x158; bl 0x573f04` (0xa36eb4), null
   check, `bl 0xa3c8e0` (0xa36ed4), store to [+x19+0x108], refcount++.
2. Ctor: ForcedCriticalSection base init 0x588b04, then vptr store and field
   writes in ascending order.

Size 0x158 proven by the factory allocation.
