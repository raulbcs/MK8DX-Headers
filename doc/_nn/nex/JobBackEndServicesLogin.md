# nn::nex::JobBackEndServicesLogin

## Identity

- RTTI-confirmed: typeinfo slot 0x12e6cc0, typeinfo struct 0x12e7480, name
  "N2nn3nex23JobBackEndServicesLoginE". Installed vptr = 0x12e6cd0 (assigned
  slot + 8); offset-to-top 0 at 0x12e6cc0. GOT cell 0x1314c28 holds 0x12e6cc0
  (vptr-0x10); installed vptr = cell + 0x10.
- 13 slots (0x12e6cd0..0x12e6d30): slot0 = D1 0xa39fdc (708 B, csv
  FUN_7100a39fdc), slot1 = D0 0xa3a3e0 (unrecovered), slots 2..12 are the
  shared nn::nex job block 0x5917a0 / 0x58ff6c / 0x5917ac / 0x590148 /
  0x59014c / 0x5917b0 / 0x5917cc / 0x58b7d8 / 0x5917d4 / 0x5917d8 / 0x59189c.
- Base init 0x588b04(this, 2, scratch) — ForcedCriticalSection base region.

## Member notes

- Size 0x520 PROVEN: factory FUN_7100a36378 news 0x520 via 0x573f04
  (0xa3678c..0xa36790) then calls the ctor at 0xa3683c.
- Ctor FUN_7100a39964 (0x678): vptr store at 0xa399d8 ([this] = cell
  0x1314c28 + 0x10), +0xa0 = arg w1 (id), +0xb0 subobject region initialized
  from cell 0x130b4a8 family (secondary vptr), remaining per include header.
- D1 0xa39fdc reinstalls the vptr (site 0xa39fec) and tears down the member
  chain; D0 0xa3a3e0 unrecovered (unverified).

## Construction / init order

1. Factory FUN_7100a36378: `mov w0, #0x520; bl 0x573f04` (0xa3678c), null
   check, arg marshalling, `bl 0xa39964` (0xa3683c).
2. Ctor: ForcedCriticalSection base init 0x588b04 (0xa399c8), then vptr store
   (0xa399cc..0xa399d8) and field writes in ascending order.

Size 0x520 proven by the factory allocation.
