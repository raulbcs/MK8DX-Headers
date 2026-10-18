# nn::pia::session::CreateMeshJob

Identity: vtable word 0x12dd900; typeinfo pointer there targets 0x12dd960 =
{0x10, "N2nn3pia7session13CreateMeshJobE"}. GOT cell 0x1313698 holds
vptr-0x10 (0x12dd8f8 = offset-to-top 0), installed vptr **0x12dd908**, 10
slots (0x12dd908..0x12dd958). Neighbour group at 0x12dd980+ is
nn::pia::session::CreateSessionJob (typeinfo 0x12dd9e0, name 0xf812f0) — a
separate class, not a secondary group of this one.

## Member notes

- Slots: 0x97e118 (D1), 0x97e11c (D0), 0xb4a654 / 0xb4a67c / 0x933314 (shared
  pia-job stubs), 0x97e8f0, 0x97e1b4, 0x97e8e8, 0x97e8ec, 0x97e30c.
- Ctor FUN_710097e0e4 (0x97e0e4..0x97e114): job-base ctor 0xb4a5e0 first
  (0x97e0f4), then +0x58 = 0 (0x97e100), then vptr 0x12dd908 (0x97e108).
- D0 0x97e11c: base D1 0xb4a62c then operator delete.
- In-place derived wrapper FUN_71009373ac (0x9373ac..0x9373d8): calls this
  ctor then re-installs vptr 0x12da4d8 =
  nn::pia::inet::InetCreateMeshJob (0x9373bc..0x9373cc); used for
  stack/embedded inet-twin construction.

## Construction / init order

1. Factories FUN_710096ceec and FUN_71009c3ab4: alloc 0x60 (0x96cf00 /
   0x9c3ac8), then ctor FUN_710097e0e4 (0x96cf14 / 0x9c3adc). Size 0x60 is
   factory-proven.
2. Ctor: 0xb4a5e0, +0x58 = 0, vptr 0x12dd908 at +0x00.
