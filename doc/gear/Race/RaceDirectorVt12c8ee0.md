# gear::RaceDirectorVt12c8ee0

## Identity

- vtable `.data 0x12c8ee0` (15+ slots, single table, no typeinfo row: no RELA
  entries at vt-0x10/vt-8). GOT cell `0x1310238` holds vt-0x10 (`0x12c8ed0`);
  installed vptr = cell + 0x10 (adrp 0x1310000 + ldr #0x238 + add #0x10).
- RaceDirector family: slot +0x90 = `RaceDirector::getRuntimeTypeInfo` (0x7ef9e4),
  slot +0x98 = dtor 0x7ee4ec, slots +0xa8..+0xd8 are the shared director impls
  (0x4dd70, `RaceDirector::enter` 0x4dddc, `::calc` 0x4de3c, `::render` 0x4de94,
  `::exit` 0x4def8, `::isDirector` 0x4df50, `::accept` 0x4df58); the table
  continues into the gear::Actor interface (slot +0xe0 = sead::FixedSizeJQ::begin
  0x1cbc, +0xe8 Actor::prepareOuter 0x7b97a8).
- Base class of a derived director whose final vptr is 0x11b8f58 (cell 0x12fcda0,
  unmapped): the sole factory (0xcc7d4 region) news 0x1a0, runs base ctor
  0x7ecba0, then overwrites [this] with the derived vptr.

## Member notes

All stores by ctor 0x7ecba0 (0x7ecba0-0x7ecd6c):
- 0x70/0x78: two new(0x10) records `{ptr, this}`; ptr chosen from static table
  0x135bf00 by a mode word ([0x87fcd0 singleton]+0x1a0 == 0x7a): +0x38 vs base
  for the first, +0x1c/+0x54 for the second. Copies kept at 0x80/0x88.
- 0x90: zeroed pair; 0x98: new(0x70) initialized by 0x7c55cc(this, -1).
- 0xa0..0x198: repeated config records sourced from cells 0x12fb148 /
  0x12fb150 (rodata 0xf57b7c / 0xf57b94, mostly empty strings) and six 0x24
  byte blobs memcpy'd from [cell 0x12fd1c8] (rodata 0x135e218) at
  0xac/0xdc/0x10c/0x130. 0x15c/0x160/0x194/0x198/0x19c zeroed.

## Construction / init order

1. Derived factory (code 0xcc8b0): `new 0x1a0` → ctor 0x7ecba0(this).
2. Ctor: vptr ← [0x1310238]+0x10; sub-records 0x70/0x78; zero 0x90; 0x98
   sub-object; config records 0xa0..0x19c.
3. Factory: [this] ← derived vptr 0x11b8f58 ([0x12fcda0]+0x10), object stored
   into a director array slot ([table + w8*8], w8 = [this+0xd8] clamp).
4. D2 0x7ecd70 / D1 0x7ecdd0 delete 0x70/0x78 and virtually destroy 0x98
   before reinstalling the vptr.
