# nn::pia::local::LocalMatchDestroySessionJob

Identity: vtable word 0x12e1ae0; typeinfo pointer there targets 0x12e1b40 =
{0x10, "N2nn3pia5local27LocalMatchDestroySessionJobE"}. GOT cell 0x13140c0
holds vptr-0x10 (0x12e1ad8 = offset-to-top 0), installed vptr **0x12e1ae8**,
10 slots (0x12e1ae8..0x12e1b38).

## Member notes

- Slots: 0x9d1fb4 (D1), 0x9d1fb8 (D0), 0xb4a654 / 0xb4a67c / 0x933314 (shared
  pia-job stubs), 0x9d213c, 0x9d2138, 0x9d1fdc, 0x9d2100, 0x9d211c.
- Base ctor FUN_710097f094 — nn::pia::session::DestroySessionJob, vptr
  0x12dda70 (cell 0x13136c8 + 0x10; base typeinfo via 0x12ddac0):
  job-base 0xb4a5e0, +0x58 = 0, sub-object ctor 0x929ec0 at +0x60, +0x80 = 0
  (0x97f0a4..0x97f0c4).
- Derived ctor FUN_71009d1f84 (0x9d1f84..0x9d1fb0): base ctor (0x9d1f94),
  vptr override to 0x12e1ae8 (0x9d1fa4).
- Neighbouring groups: 0x12e1b60+ = nn::pia::local::LocalMatchJoinSessionJob
  (typeinfo 0x12e1c00, name 0xf83660); the word 0x12ddac0 at 0x12e1b50 is
  this class's base-typeinfo pointer inside the typeinfo record.

## Construction / init order

1. Factory FUN_71009c3f04: alloc 0x90 (0x9c3f18), ctor FUN_71009d1f84
   (0x9c3f2c). Size 0x90 is factory-proven.
2. Ctor: base FUN_710097f094 first, then vptr 0x12e1ae8 at +0x00.
