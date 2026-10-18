# nn::nex::Data

RTTI-confirmed: typeinfo 0x12e61b0 -> mangled `N2nn3nex4DataE` =
nn::nex::Data. Table-node object of the online "InstanceTable" (caller
0xa42f60 asserts via string 0xef293c =
`..\..\..\..\.\/OnlineCore/src/Core/InstanceTable.h`); the vtable's
virtuals allocate/register/look up entries named "Data" (rodata
0xf14ec5).

- Identity: C1 FUN_7100a28aa4 (12 B): installs vptr, writes 0 to +0x08.
- Size proof: factory at 0xa42fb0 does `mov w0, #0x48; bl operator new
  0x573f04` then calls the C1 - size 0x48 exact.
- Vtable: vptr = 0x12e5a98. GOT cell 0x1314938 holds 0x12e5a88 =
  vptr-0x10; sites add 0x10. Row: [0x12e5a88] = 0 (offset-to-top),
  [0x12e5a90] typeinfo slot -> 0x12e61b0.
- Sites: 0xa28aa8 (C1), 0xa28bd4 (slot2 factory body).

## Member notes

- Slots (8): +0x00 D1 0xa30458 (4 B, `ret` - trivial destructor),
  +0x08 D0 0xa28abc (tail `b operator delete` 0x573f48), +0x10 0xa28bbc
  (entry at 0xa28bbc = factory: `new 0x10`, write 0 to +0x08 of the new
  block, install this vptr), +0x18 0xa28bec (create + register: stores
  name ptr "Data", [+0x18] = this+8, [+0x20] = 0x10, installs vptr,
  tail 0x578f98 list insert), +0x20 0xa28c1c (lookup wrapper tail
  0x579324 with "Data"), +0x28 0xa28d28 (same lookup wrapper), +0x30
  0xa28c30 (guarded search reading flag [x1+0x69] and byte [x0+0x08]),
  +0x38 0xa28c98 (clone of slot6).
- Caller-initialized fields past the C1 (factory 0xa42fc0..): +0x09 = 0,
  +0x10 = vptr of a member object (GOT cell 0x1314db8, unmapped class),
  +0x18 = 0, +0x28/+0x30 = pointer pair, +0x38 = 4, +0x40 = 0xfab.

## Construction / init order

1. `operator new(0x48)` (0xa42fb0).
2. C1 0xa28aa4: vptr 0x12e5a98 at +0x00, +0x08 = 0.
3. Caller (0xa42fc0 onwards) fills +0x09..+0x40 as listed above.
