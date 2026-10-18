# nn::pia::local::LocalDestroyNetworkJob

## Identity

- vtable row 0x12e1640 (tsv row = typeinfo slot), vptr 0x12e1648 = row + 8,
  6 slots. GOT cell 0x1313f18 holds 0x12e1638 = vptr - 0x10; installed
  vptr = cell + 0x10.
- RTTI: typeinfo 0x12e1680 = {0x10, name 0xf83370, base 0x12f8d30}; name =
  "N2nn3pia5local22LocalDestroyNetworkJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9ce3bc, 1 D0 0x9ce408, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 bare `ret` 0x9ceabc (unrecovered in functions.csv).
- D1 0x9ce3bc: re-installs vptr, deletes the +0x60 heap sub-object
  (0x929ee0 + operator delete 0x568b64) and nulls +0x88, tail 0xb4a62c.
  D0 0x9ce408: same body then operator delete.
- extent 0x90 EXACT: operator new 0x90 at 0x9c5284 (factory caller
  0x9c529c).

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58: zeroed by C1.
- +0x60: heap sub-object, new 0x20 (0x9ce398) built by 0x929ec0; deleted
  by D1.
- [0x68, 0x78) and +0x78: zeroed by C1; +0x80 u8 = 0.
- +0x88: parent/handle passed as C1 arg x1, cleared by D1.

## Construction / init order

1. C1 0x9ce350: base C1 0xb4a5e0(this) (0x9ce364).
2. [this+0x58] = 0 (0x9ce368).
3. [this+0x68] = [this+0x70] = 0 (0x9ce374); [this+0x78] = 0 (0x9ce380).
4. [this+0x80] = 0 (0x9ce384); [this+0x88] = arg x1 (0x9ce388).
5. vptr 0x12e1648 -> [this] (0x9ce37c, cell 0x1313f18 + 0x10).
6. new 0x20 -> 0x929ec0 -> [this+0x60] (0x9ce38c-0x9ce3ac).
