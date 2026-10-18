# Vt12f4ee8

Unnamed intrusive-list container; no RTTI (off-top 0 at 0x12f4ed8,
typeinfo slot 0x12f4ee0 = 0).

- Init: FUN_7100b03d94 (36 B, site 0xb03da0) — installs vptr (GOT cell
  0x13155c8 holds 0x12f4ed8 = vptr-0x10, site adds 0x10), writes
  this+0x08 into both +0x08 and +0x10 (empty-list self sentinel), 0 at
  +0x18, 0x20 at +0x1c.
- Allocation: caller (singleton init at 0x8c174c) does operator-new
  0x20, zeroes the object, calls the init, then overrides the vptr with
  cell 0x1311a18+0x10 — so 0x12f4ee8 is the base-class vtable of a
  derived singleton member stored at [singleton+0x30].
- Slots (9): +0x00 0xb03db8 (`ret` stub), +0x08 0xb03dbc (tail
  `b operator delete`, deleting dtor), +0x10 0xb03dc0 (432 B worker,
  builds stack buffer 0x100 and walks vtable cells 0x12fada0/0x12fada8/
  0x12fbd88 — dispatch driver), +0x18 0xb03f70, +0x20 0xb041cc, +0x28
  0xb04420, +0x30 0xb044a0, +0x38 0xb044d8, +0x40 0xb042f8; +0x58
  0xb04850, +0x60 0xb048d8. All unnamed in functions.csv; no strings.
- Size: 0x20 EXACT (operator-new size).

## Construction / init order

1. operator-new 0x20; full zero.
2. FUN_7100b03d94: vptr, self-sentinels at +0x08/+0x10, +0x18=0,
   +0x1c=0x20.
3. Caller overrides vptr (derived vtable from cell 0x1311a18) and
   stores the pointer at [singleton+0x30].
