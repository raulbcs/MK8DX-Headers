# nn::pia::lan::LanMatchUpdateSessionSettingJob

Identity: vtable word 0x12dd170; typeinfo pointer at 0x12dd170 targets
0x12dd1d0 = {0x10, "N2nn3pia3lan31LanMatchUpdateSessionSettingJobE"}. GOT cell
0x1313620 holds vptr-0x10 (0x12dd168 = offset-to-top 0), so the installed vptr
is **0x12dd178** and slot 0 starts there. 10 slots (0x12dd178..0x12dd1c8).

## Member notes

- Slots: 0x97947c (D1), 0x979480 (D0), 0xb4a654 / 0xb4a67c / 0x933314 (shared
  pia-job stubs), 0x979770, 0x97961c, 0x9794a4 (arg-heavy step: stores x2 at
  +0x88, result string at +0x40, 0x9794cc..0x979510 — unverified semantics),
  0x99f6f8, 0x99f708 (slots shared with the local twin).
- Base ctor FUN_710099f4e4 (0x979458): installs base vptr 0x12de9b8 (=
  nn::pia::session::UpdateSessionSettingJob, typeinfo name string via
  0x12dea10), zeroes +0x58, runs sub-object ctor 0x929ec0 at +0x60.
- Derived ctor FUN_7100979448 (0x979448..0x979478): zeroes the +0x88 pointer
  (0x979464), overrides the vptr to 0x12dd178 (0x97946c).
- D0 0x979480: base D1 0x99f51c then operator delete.

## Construction / init order

1. Factory FUN_710096d33c: alloc 0x98 (0x96d350), then ctor FUN_7100979448
   (0x96d364). Size 0x98 is factory-proven.
2. Ctor: base FUN_710099f4e4 first, then +0x88 = 0 (0x979464), then vptr
   0x12dd178 at +0x00 (0x97946c).
