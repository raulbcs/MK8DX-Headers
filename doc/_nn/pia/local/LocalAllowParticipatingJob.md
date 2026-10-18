# nn::pia::local::LocalAllowParticipatingJob

## Identity

- vtable row 0x12e1480 (tsv row = typeinfo slot), vptr 0x12e1488 = row + 8,
  6 slots. GOT cell 0x1313eb8 holds 0x12e1478 = vptr - 0x10 (offset-to-top
  0x12e1478 = 0, typeinfo slot 0x12e1480 = 0x12e14c0); installed vptr =
  cell + 0x10.
- RTTI: typeinfo 0x12e14c0 = {0x10, name 0xf83280, base 0x12f8d30}; name =
  "N2nn3pia5local26LocalAllowParticipatingJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9cd018, 1 D0 0x9cd078, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 bare `ret` 0x9cd368 (unrecovered in functions.csv).
  Slots 2-4 are the shared StepSequenceJob stubs.
- D1 0x9cd018: re-installs vptr, deletes the +0x58 heap object via its
  vtable + operator delete 0x568b64 and nulls +0x58, destroys the +0x68
  sub-object (0x929ee0), tail 0xb4a62c (shared job-base D0).
  D0 0x9cd078: same body then operator delete.
- extent 0x98 EXACT: operator new 0x98 at 0x9c5360 (factory caller
  0x9c5378), sole site found.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58: pointer to a heap object allocated with new 0x70 (0x9ccfec) and
  built by 0x9d4620; deleted by D1.
- +0x60: u64 zeroed by C1.
- +0x68 sub-object (0x20 bytes): built by 0x929ec0 (same builder as
  CloseParticipationJob +0x60 and JoinSessionJob +0x60).
- +0x88: zeroed by C1; +0x90: parent/handle passed as C1 arg x1.

## Construction / init order

1. C1 0x9ccfa4: base C1 0xb4a5e0(this) (0x9ccfbc).
2. [this+0x60] = 0 (0x9ccfc8).
3. vptr 0x12e1488 -> [this] (0x9ccfd4, cell 0x1313eb8 + 0x10).
4. Sub-object ctor 0x929ec0(this + 0x68) (0x9ccfd8).
5. [this+0x88] = 0; [this+0x90] = arg x1 (0x9ccfdc).
6. new 0x70 -> 0x9d4620 -> [this+0x58] (0x9ccfe8-0x9cd004).
