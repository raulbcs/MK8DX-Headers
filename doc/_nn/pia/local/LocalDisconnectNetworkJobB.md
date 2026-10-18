# nn::pia::local::LocalDisconnectNetworkJobB

## Identity

- vtable row 0x12e1700 (tsv row = typeinfo slot), vptr 0x12e1708 (ICF duplicate copy) = row + 8,
  6 slots. GOT cell 0x1313f78 holds 0x12e16f8 = vptr - 0x10; installed
  vptr = cell + 0x10.
- RTTI: typeinfo 0x12e1740 = {0x10, name 0xf833f0, base 0x12f8d30}; name =
  "N2nn3pia5local25LocalDisconnectNetworkJobBE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9cef7c, 1 D0 0x9cf03c, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 `ret` 0x9cf3d0 (bare `ret`; unrecovered in
  functions.csv). Slots 2-4 are the shared StepSequenceJob stubs.
- D1 0x9cef7c: re-installs vptr (cell 0x1313f78 + 0x10), destroys the
  +0x58 job ptr (virtual + delete via 0x568b64), zeroes +0x108, destroys
  the +0xe8 subobject (0x929ee0), re-installs cell 0x1312438 + 0x10 into
  the [0x60, 0xd0) unit slots, tail 0xb4a62c (shared job-base D0).
  D0 0x9cf03c: same body then operator delete 0x60b470.
- size 0x110 EXACT: operator new 0x110 at 0x9c5338, C1 call at 0x9c5350
  (factory context 0x9c4c88 region).

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58: ptr to a 0x78-byte object allocated inside the C1 (alloc
  0x568aa0 at 0x9cef0c, C1 0x9d4850 with the session arg).
- [0x60, 0xd0): 7 subobjects, stride 0x10, each C1 0x92a1e0 (0x9cee9c..);
  fields at +0x68/+0x6c etc. (u32 + u32 + u16 pattern) zeroed at
  0x9cef2c..0x9cef64.
- +0xd0: list head set to this+0x60 (0x9cef68); +0xd8/+0xe0 zeroed then
  +0xe0 = count 7.
- +0xe8 subobject (0x18 bytes): C1 0x929ec0 (0x9ceef8).
- +0x108: session/handle arg (C1 x1, stored at 0x9ceefc).

## Construction / init order

1. C1 0x9cee84: base C1 0xb4a5e0(this) (0x9cee9c).
2. vptr 0x12e1708 (ICF duplicate copy) -> [this] (0x9ceeb4, cell 0x1313f78 + 0x10).
3. Subobject ctors 0x92a1e0 at this+0x60..+0xc0, stride 0x10.
4. +0xd0..+0xe4 zeroed; +0xe8 subobject C1 0x929ec0; +0x108 = x1.
5. 0x78-byte job alloc at +0x58, C1 0x9d4850(x1).
