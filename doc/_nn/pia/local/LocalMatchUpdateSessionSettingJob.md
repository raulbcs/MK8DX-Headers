# nn::pia::local::LocalMatchUpdateSessionSettingJob

Identity: vtable word 0x12e1db0; typeinfo pointer there targets 0x12e1e10 =
{0x10, "N2nn3pia5local33LocalMatchUpdateSessionSettingJobE"}. GOT cell
0x1314110 holds vptr-0x10 (0x12e1da8 = offset-to-top 0), installed vptr
**0x12e1db8**, 10 slots (0x12e1db8..0x12e1e08). The words at 0x12e1e30+ are
the neighbouring nn::pia::local::LocalMatchmakeSession vtable (typeinfo
0x12e1fc0, ~41 slots), a separate class.

## Member notes

- Slots: 0x9d2e14 (D1), 0x9d2e18 (D0), 0xb4a654 / 0xb4a67c / 0x933314 (shared
  pia-job stubs), 0x9d3198, 0x9d3190, 0x9d2e3c, 0x99f6f8, 0x99f708 (last two
  shared with the lan twin nn::pia::lan::LanMatchUpdateSessionSettingJob).
- Base ctor FUN_710099f4e4 — nn::pia::session::UpdateSessionSettingJob, vptr
  0x12de9b8 (cell 0x1313a40 + 0x10; base typeinfo via 0x12dea10):
  job-base 0xb4a5e0, +0x58 = 0, sub-object ctor 0x929ec0 at +0x60
  (0x99f4f4..0x99f518).
- Derived ctor FUN_71009d2de0 (0x9d2de0..0x9d2e10): base ctor (0x9d2df0),
  +0x94 = 0 (0x9d2dfc), vptr override to 0x12e1db8 (0x9d2e04).

## Construction / init order

1. Factory FUN_71009c3f40: alloc 0x98 (0x9c3f54), ctor FUN_71009d2de0
   (0x9c3f68). Size 0x98 is factory-proven.
2. Ctor: base FUN_710099f4e4 first, then +0x94 = 0, then vptr 0x12e1db8 at
   +0x00.
