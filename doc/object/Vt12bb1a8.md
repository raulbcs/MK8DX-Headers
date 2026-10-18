# object::Vt12bb1a8

PLACEHOLDER name. 8-slot secondary hook-band vtable of
ParamContainerVtb0b8 (primary vptr 0x12bb0b8), installed at owner+0x30.
Subobject is vptr-only (owner fields resume at +0x38).

- Identity: no RTTI ([vptr-8] 0x12bb1a0 = 0); [vptr-0x10] 0x12bb198 =
  -0xd0 (offset-to-top row, raw value; interpretation unverified).
- Install: owner ctor site 0x6fc2dc (alloc 0x2f0) stores GOT cell
  0x130e4c0 + 0x10 = 0x12bb0b8 at [owner] and cell + 0x100 = 0x12bb1a8
  at [owner+0x30]; the owner D2 body 0x6fb98c re-stores the same pair
  during destruction reset.
- Slots (8, row 0x12bb1a8..0x12bb1e0; zero slots at +0x30/+0x38 double
  as the header of primary row 0x12bb1e8):
  - slot 0 (+0x00) 0x6fb0e0: D1 thunk; loads GOT cell 0x130e468
    (ParamMultiChanVtb318 header 0x12bb308) and stores cell+0x10 =
    0x12bb318 at [this-0x30] — i.e. resets the owner primary to the
    ParamMultiChanVtb318 vptr (suggesting ParamContainerVtb0b8 derives
    from ParamMultiChanVtb318; unverified).
  - slot 1 (+0x08) 0x6fb11c: D0 thunk (same reset + operator delete).
  - slots 2-5: shared band forwarders 0x648094/0x6480a0/0x6480a8/
    0x6480b4 (see doc/object/Vt12bb078.md).
  - slots 6/7: 0, 0.

## Construction / init order

1. Ctor at 0x6fc2dc (FUN_71006fc300 region): new 0x2f0, primary vptr
   0x12bb0b8 at [owner], band vptr 0x12bb1a8 at [owner+0x30].
2. Destruction: D2 0x6fb98c re-installs the primary/band pair before
   member teardown.
