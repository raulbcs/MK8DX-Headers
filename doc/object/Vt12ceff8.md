# object::Vt12ceff8

Interface row of a Network:: heap family whose concrete ctor is built inside
the shared service factory block (0x3835f8..0x3837cc).

- Identity: no RTTI. Primary row 0x12ceff8: 8 slots 0x85efc4/0x85f078/
  0x85f12c/0x397be4 (Network::HttpHeap#15)/0x397c9c/0x85f1b8/0x85f1bc/
  0x397d20; never installed (no GOT cell, no code reference).
- Concrete row 0x12cf048 (GOT cell 0x1310e98 holds vt-0x10; installed vptr =
  cell+0x10 = 0x12cf048): 44 slots, 0x12cf048..0x12cf1a8. First slots
  0x85f34c, 0x860210, 0x860218 ... (functions.csv U). Installed by ctor
  FUN_710085f270 at 0x85f294.
- Unlike the sibling families, no separate singleton stub row was found for
  this primary (single GOT cell 0x1310e98 in the range).

## Member notes

- +0x00 vptr 0x12cf048.
- +0xa8 pointer to a `new` 0x50 subobject (0x85f2e4..0x85f2ec); zeroed
  fields +0/+0x38/+0x40 inside the subobject (0x85f2f4..0x85f2fc).
- +0xb0 pointer to a `new` 0x88 subobject (0x85f2c8..0x85f2cc), further
  initialized by 0x91f950 with (0x9, 0xc) (0x85f2e0).
- +0xc2 u8 flag zeroed by ctor (0x85f2b4).
- Ctor also `new`s a 0x30 subobject initialized by 0x840ac4 (0x85f2b0..0x85f2c4),
  storage offset unverified.

## Construction / init order

1. Shared factory: `new` 0xc8 via FUN_710060afec (0x383620..0x383628);
   result stored at [parent+0x230] (0x383638).
2. Ctor FUN_710085f270: zeroes +0xc2; builds the 0x30/0x88/0x50 subobjects;
   installs vptr 0x12cf048 (0x85f294).
