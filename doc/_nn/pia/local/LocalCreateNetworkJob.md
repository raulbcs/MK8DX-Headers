# nn::pia::local::LocalCreateNetworkJob

## Identity

- vtable row 0x12e15e0 (tsv row = typeinfo slot), vptr 0x12e15e8 = row + 8,
  6 slots. GOT cell 0x1313f00 holds 0x12e15d8 = vptr - 0x10; installed
  vptr = cell + 0x10.
- RTTI: typeinfo 0x12e1620 = {0x10, name 0xf83330, base 0x12f8d30}; name =
  "N2nn3pia5local21LocalCreateNetworkJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9ce0b0, 1 D0 0x9ce0fc, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 bare `ret` 0x9ce34c (unrecovered in functions.csv).
- D1 0x9ce0b0: re-installs vptr, deletes the +0x60 heap sub-object
  (0x929ee0 + operator delete 0x568b64) and nulls +0x68, tail 0xb4a62c.
  D0 0x9ce0fc: same body then operator delete.
- extent 0x70 EXACT: operator new 0x70 at 0x9c525c (factory caller
  0x9c5274).

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58: zeroed by C1.
- +0x60: heap sub-object, new 0x20 (0x9ce08c) built by 0x929ec0; deleted
  by D1. Same shape as LocalConnectNetworkJob.
- +0x68: parent/handle passed as C1 arg x1, cleared by D1.

## Construction / init order

1. C1 0x9ce050: base C1 0xb4a5e0(this) (0x9ce064).
2. [this+0x58] = 0 (0x9ce070); [this+0x68] = arg x1 (0x9ce074).
3. vptr 0x12e15e8 -> [this] (0x9ce07c, cell 0x1313f00 + 0x10).
4. new 0x20 -> 0x929ec0 -> [this+0x60] (0x9ce080-0x9ce0a0).
