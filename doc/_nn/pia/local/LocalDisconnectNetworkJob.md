# nn::pia::local::LocalDisconnectNetworkJob

## Identity

- vtable row 0x12e16a0 (tsv row = typeinfo slot), vptr 0x12e16a8 = row + 8,
  6 slots. GOT cell 0x1313f58 holds 0x12e1698 = vptr - 0x10; installed
  vptr = cell + 0x10.
- RTTI: typeinfo 0x12e16e0 = {0x10, name 0xf833b0, base 0x12f8d30}; name =
  "N2nn3pia5local25LocalDisconnectNetworkJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9ceb20, 1 D0 0x9ceb6c, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 bare `ret` 0x9cee80 (unrecovered in functions.csv).
- D1 0x9ceb20: re-installs vptr, deletes the +0x60 heap sub-object
  (0x929ee0 + operator delete 0x568b64) and nulls +0x68, tail 0xb4a62c.
  D0 0x9ceb6c: same body then operator delete.
- extent 0x70 EXACT: operator new 0x70 at 0x9c52ac (factory caller
  0x9c5314).

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58: zeroed by C1.
- +0x60: heap sub-object, new 0x20 (0x9ceafc) built by 0x929ec0; deleted
  by D1. Same shape as LocalConnectNetworkJob / LocalCreateNetworkJob.
- +0x68: parent/handle passed as C1 arg x1, cleared by D1.

## Construction / init order

1. C1 0x9ceac0: base C1 0xb4a5e0(this) (0x9cead4).
2. [this+0x58] = 0 (0x9ceae0); [this+0x68] = arg x1 (0x9ceae4).
3. vptr 0x12e16a8 -> [this] (0x9ceaec, cell 0x1313f58 + 0x10).
4. new 0x20 -> 0x929ec0 -> [this+0x60] (0x9ceaf0-0x9ceb10).
