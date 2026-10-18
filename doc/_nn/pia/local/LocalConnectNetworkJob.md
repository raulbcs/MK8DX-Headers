# nn::pia::local::LocalConnectNetworkJob

## Identity

- vtable row 0x12e1580 (tsv row = typeinfo slot), vptr 0x12e1588 = row + 8,
  6 slots. GOT cell 0x1313ee0 holds 0x12e1578 = vptr - 0x10; installed
  vptr = cell + 0x10.
- RTTI: typeinfo 0x12e15c0 = {0x10, name 0xf832f0, base 0x12f8d30}; name =
  "N2nn3pia5local22LocalConnectNetworkJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9cdcc4, 1 D0 0x9cdd10, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 bare `ret` 0x9ce04c (unrecovered in functions.csv).
- D1 0x9cdcc4: re-installs vptr, deletes the +0x60 heap sub-object
  (0x929ee0 + operator delete 0x568b64) and nulls +0x68, tail 0xb4a62c.
  D0 0x9cdd10: same body then operator delete.
- extent 0x70 EXACT: operator new 0x70 at 0x9c52d4 (factory caller
  0x9c52ec).

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58: zeroed by C1.
- +0x60: heap sub-object, new 0x20 (0x9cdc9c) built by 0x929ec0; deleted
  by D1.
- +0x68: parent/handle passed as C1 arg x1, cleared by D1.

## Construction / init order

1. C1 0x9cdc64: base C1 0xb4a5e0(this) (0x9cdc78).
2. [this+0x58] = 0 (0x9cdc84); [this+0x68] = arg x1 (0x9cdc88).
3. vptr 0x12e1588 -> [this] (0x9cdc90, cell 0x1313ee0 + 0x10).
4. new 0x20 -> 0x929ec0 -> [this+0x60] (0x9cdc94-0x9cdcb4).
