# NexFacade (nn::pia::inet::NexFacade)

## Identity

- vt_ctors.tsv row 0x12d9800 is the TYPEINFO SLOT, not the vptr: [0x12d9800]
  = 0x12d9880 (reloc), and 0x12d9880 is the typeinfo record
  {0x10, name 0xf7e5e0, base 0x12d9868}. Installed vptr = 0x12d9808 (row+8),
  12 slots.
- Name is exact: 0xf7e5e0 = "N2nn3pia4inet9NexFacadeE". Base record 0x12d9868
  = {0x10, 0xf7e600, base 0} = nn::pia::inet::IFacade (root).
- GOT cell 0x1312870 holds addend 0x12d97f8 = vt-0x8; code (ctor 0x92d234,
  D1 0x92d398, D0 0x92d3dc) does `ldr cell; add #0x10; str [this]`.
- Size 0x160 PROVEN: allocation site 0x92ccd8 (`mov w0, #0x160; bl 0x568b00`),
  full zero-fill loop 0x92ccf0, then ctor 0x92d218 (0x92cd10); result stored
  to singleton cell 0x1312868 (storage 0x135f740) at 0x92cd0c —
  GetInstance-style singleton.

## Slots (vptr 0x12d9808, 12 slots)

- slot 0 = 0x92d388 (D1: re-installs vptr 0x12d9808 at [this], then
  0x929ee0 at this+0x118, this+0xf8, tail this+0xd8).
- slot 1 = 0x92d3cc (D0: same as D1 then `operator delete`).
- slots 2..11 = 0x92e6d0, 0x92e6d8, 0x92e6e0, 0x92e718, 0x92e734, 0x92e760,
  0x92e798, 0x92e7b0, 0x92e710, 0x92e8bc — all functions.csv-unrecovered.

## Member notes

- 0x00 — primary vptr (IFacade table 0x12d9808).
- 0x10 — vptr 0x12d9748 of an embedded nn::pia::common::FixedString<8>
  subobject (its typeinfo slot 0x12d9740 → record 0x12d9780 = {0x10, 0xf7e580,
  base 0x12d9648}).
- 0x18 — pointer, ctor 0; 0x20 — word 0x20; 0x24 — 0.
- 0x2c..0x4c — 16 zeroed u16 + trailing byte (ctor 0x92d254..0x92d298).
- 0x2c (re-read via pre-indexed x19) region also zeroed at 0x92d2e0..0x92d320
  covering 0x2c..0x4c again plus pointer-sized clears at 0x18/0x24 and
  0x74..0x7f, 0x84 (halfword), 0x86 (byte), 0x98..0x9f pairs.
- 0xb4 — word 5000 (0x1388); 0xb8 — word 1500 (0x5dc) (ctor 0x92d2b8).
- 0xd8/0xf8/0x118 — three 0x20-byte members initialized by 0x929ec0 and
  destructed in reverse-ish order by 0x929ee0 in D1/D0; unverified inner type.
- 0x138/0x140/0x148 — pointers, ctor 0; 0x158 — byte 1; 0x15c — word 0.

## Construction / init order

1. Singleton allocation 0x92ccd0..0x92cd10: acquire context (0x563b70),
   alloc 0x160 via 0x568b00, zero-fill, store to cell 0x1312868, then C1
   0x92d218.
2. Ctor 0x92d218: [this+0x20] = 0x20; vptr 0x12d9808 at [this] (cell
   0x1312870); FixedString<8> vptr 0x12d9748 at [this+0x10] (cell 0x1312858);
   byte [this+0x2c] = 0 (pre-indexed); zero 0x2c..0x4c; ptr [this+0x18] = 0,
   [this+0x24] = 0; member inits 0x929ec0 at +0xd8, +0xf8, +0x118;
   5000/1500 at +0xb4/+0xb8; second zero pass 0x2c..0x4c + 0x74..0x7f,
   0x84, 0x86, 0x98..0x9f; [this+0x138]/[+0x140]/[+0x148] = 0; byte
   [this+0x158] = 1; word [this+0x15c] = 0.

Note: doc/_nn/pia/inet/NexMatchCommunityManagementJob.md (vtable 0x12dad18)
was previously misnamed "NexFacade"; this file is the true NexFacade.
