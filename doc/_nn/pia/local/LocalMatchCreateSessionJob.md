# nn::pia::local::LocalMatchCreateSessionJob

Identity: vtable word 0x12e1a60; typeinfo pointer there targets 0x12e1ac0 =
{0x10, "N2nn3pia5local26LocalMatchCreateSessionJobE"}. GOT cell 0x1314080
holds vptr-0x10 (0x12e1a58 = offset-to-top 0), installed vptr **0x12e1a68**,
10 slots (0x12e1a68..0x12e1ab8). The words at 0x12e1ad8+ are the adjacent
nn::pia::local::LocalMatchDestroySessionJob vtable (vptr 0x12e1ae8), a
sibling class — not a secondary group.

## Member notes

- Slots: 0x9d1aac (D1), 0x9d1ac4 (D0), 0xb4a654 / 0xb4a67c / 0x933314 (shared
  pia-job stubs), 0x9d1f80, 0x9d1f7c (step overrides shared with the
  Destroy-session sibling region), 0x9d1afc, 0x9d1f10, 0x9d1f54.
- Base ctor FUN_710097e8f4 — nn::pia::session::CreateSessionJob, vptr
  0x12dd988 (cell 0x13136a8 + 0x10): job-base 0xb4a5e0, +0x58 = 0, sub-object
  ctor 0x929ec0 at +0x60, +0x80 = 0 (0x97e904..0x97e924).
- Derived ctor FUN_71009d1a70 (0x9d1a70..0x9d1aa8): calls the base ctor
  (0x9d1a84); +0x98 = 0 (0x9d1a90); +0x88 = 0 and +0x90 = x1 via stp
  (0x9d1a94); vptr override to 0x12e1a68 (0x9d1a9c). x1 comes from the
  singleton at cell 0x1312638 (factory 0x9c3dcc, 0x9c3dd8..0x9c3e04).
- D1 0x9d1aac / D0 0x9d1ac4: zero +0x90, re-install base vptr, tail to base
  D1 0x97e934.

## Construction / init order

1. Factory FUN_71009c3dcc: alloc 0xa0 (0x9c3dec), x1 = [cell 0x1312638]
   (0x9c3dd8..0x9c3de4), ctor FUN_71009d1a70 (0x9c3e04). Size 0xa0 is
   factory-proven.
2. Ctor: base FUN_710097e8f4 first, then +0x88/+0x90/+0x98 stores, then vptr
   0x12e1a68 at +0x00.
