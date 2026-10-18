# object::Vt12ce1c8

nn-network/ldn-style framework family built by the shared service factory in
the Network:: heap region (factory block at 0x3835f8..0x3837cc, file
functions.csv names only Network::HttpHeap#NN there).

- Identity: no RTTI. Primary row 0x12ce1c8: offset-to-top 0 (0x12ce1b8) and
  typeinfo 0 (0x12ce1c0); 8 slots 0x852bfc/0x852cb0/0x852d64/0x852df0/
  0x852ea8/0x8534b4/0x852f28/0x852f2c (functions.csv U, sizes 0x180/0x180/
  0x140/0x340). The primary row is never installed — no GOT cell and no
  code reference targets it; the GOT convention cells hold the derived rows.
- Stub row 0x12ce218 (GOT cell 0x1310dc8 holds vt-0x10; installed vptr =
  cell+0x10): 1 slot 0x853674. Lazy guards 0x852abc and 0x852b88 install the
  stateless singleton (this == vptr) into 0x1310dd0 under guard 0x1310dc0;
  slot 0x853674 compares its two args and, when unequal, forwards to the
  sibling singleton 0x1310de0 slot 0 (stub-director pattern).
- Concrete row 0x12ce230 (GOT cell 0x1310df0; installed vptr = cell+0x10):
  54 slots, 0x12ce230..0x12ce3e0, bounded by the next row's 0,0 pair at
  0x12ce3e8/0x12ce3f0. First slots: 0x55ae80, then ICF-clone stubs 0xbbdc,
  0xbbe4, ... (functions.csv U throughout).

## Member notes

- +0x00 vptr 0x12ce230, stored by init FUN_71008537b0 (0x8537ec).
- +0x5b0/+0x5b8: list head/tail, ctor zeroes both (0x8537e0/0x8537d4).
- +0x5e8: self-pointer node (0x85385c area, unverified).
- +0x630..+0x780: fourteen 0x18-stride intrusive nodes, each storing
  this+next-stride (0x8537f0..0x85385c).
- +0x7f8: zeroed by ctor (0x8537e4).
- All other fields: unproven padding.

## Construction / init order

1. Shared factory: `new` 0x8d0 via FUN_710060afec (0x383754..0x38375c);
   result stored at [parent+0x250] (0x383768).
2. Init FUN_71008537b0 (csv FUN_71008537b0, size 0x284): zeroes +0x5b0,
   +0x5b8, +0x7f8; installs vptr 0x12ce230 (0x8537ec); links the 0x18-stride
   node list +0x630..+0x780; calls enl::EventSynchronizer::EventSyncHeap
   (0x55a864) with (0xb, 0x32, 0x18, 0xc) before the vptr store (0x8537d0).
3. Sibling class in the same family: `new` 0xf60 -> ctor FUN_7100853c80
   (0x3837a8..0x3837b4), stored at [parent+0x260] — separate vtable, not
   mapped here (unverified).
