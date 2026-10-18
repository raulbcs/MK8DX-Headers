# nn::pia::session::CloseParticipationJob

## Identity

- vtable row 0x12dea90 (tsv row = typeinfo slot), vptr 0x12dea98 = row + 8,
  6 slots. GOT cell 0x1313a68 holds 0x12dea88 = vptr - 0x10 (offset-to-top
  0x12dea88 = 0, typeinfo slot 0x12dea90 = 0x12dead0); installed vptr =
  cell + 0x10.
- RTTI: typeinfo 0x12dead0 = {0x10, name 0xf82020, base 0x12f8d30}; name =
  "N2nn3pia7session21CloseParticipationJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x99fea0, 1 D0 0x99fed4, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 `ret` 0x9a0478 (unrecovered in functions.csv; bare
  `ret` at 0x9a0478). Slots 2-4 are the shared StepSequenceJob stubs.
- D1 0x99fea0: re-installs vptr (cell 0x1313a68 + 0x10), advances this by
  0x60 and destroys the +0x60 sub-object (0x929ee0), tail 0xb4a62c (shared
  job-base D0). D0 0x99fed4: same body then operator delete 0x60b470.
- extent 0x98 EXACT: operator new 0x98 at 0x997948 (factory caller
  0x997958), sole site found.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58: zeroed by C1; set to a session/handle ptr by 0x99ff10 (also
  stores [this+0x80] result and [this+0x88] ptr).
- +0x60 sub-object (0x20 bytes): built by 0x929ec0 (same builder as
  JoinSessionJob +0x60 and LanMatchmakeUpdateJob +0xd78).
- +0x80 u32 = 0; [0x88, 0x98) zeroed by C1.

## Construction / init order

1. C1 0x99fe5c: base C1 0xb4a5e0(this) (0x99fe6c).
2. [this+0x58] = 0 (0x99fe78).
3. vptr 0x12dea98 -> [this] (0x99fe84, cell 0x1313a68 + 0x10).
4. Sub-object ctor 0x929ec0(this + 0x60) (0x99fe88).
5. [this+0x80] = 0 (0x99fe8c); [this+0x88] = [this+0x90] = 0 (0x99fe90).
