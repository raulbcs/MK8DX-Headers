# nn::pia::session::OpenParticipationJob

## Identity

- vtable row 0x12deb50 (tsv row = typeinfo slot), vptr 0x12deb58 = row + 8,
  6 slots. GOT cell 0x1313aa8 holds 0x12deb48 = vptr - 0x10 (offset-to-top
  0x12deb48 = 0, typeinfo slot 0x12deb50 = 0x12deb90); installed vptr =
  cell + 0x10.
- RTTI: typeinfo 0x12deb90 = {0x10, name 0xf820a0, base 0x12f8d30}; name =
  "N2nn3pia7session20OpenParticipationJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9a08e8, 1 D0 0x9a091c, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 `ret` 0x9a0d18 (bare `ret`). D1 0x9a08e8: re-installs
  vptr, destroys the +0x60 sub-object (0x929ee0), tail 0xb4a62c. D0
  0x9a091c: same body then operator delete 0x60b470.
- extent 0x90 EXACT: operator new 0x90 at 0x997918 (factory caller
  0x99792c, stored at [mgr+0x48]), sole site found.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58: ptr (0 = none) — set by member fn 0x9a0854 (guards flags
  +0x8d/+0x8e, calls 0x929eec on the stored ptr).
- +0x60 sub-object (0x20 bytes): built by 0x929ec0; torn down by the
  request path 0x9a0820 region (0x929f00 etc.).
- +0x80 u32 = 0; +0x88 ptr = 0.

## Construction / init order

1. C1 0x9a08a4: base C1 0xb4a5e0(this) (0x9a08b4).
2. [this+0x58] = 0 (0x9a08c0).
3. vptr 0x12deb58 -> [this] (0x9a08cc, cell 0x1313aa8 + 0x10).
4. Sub-object ctor 0x929ec0(this + 0x60) (0x9a08d0).
5. [this+0x80] = 0 (0x9a08d4); [this+0x88] = 0 (0x9a08d8).
