# object::Vt12bb2d8

PLACEHOLDER name. 8-slot secondary hook-band vtable of
ParamContainerVtb1e8 (primary vptr 0x12bb1e8), installed at owner+0x30.
Subobject is vptr-only (owner fields resume at +0x38).

- Identity: no RTTI ([vptr-8] 0x12bb2d0 = 0); [vptr-0x10] 0x12bb2c8 =
  -0xd0 (offset-to-top row, raw value; interpretation unverified).
- Install: owner ctor site 0x6fc4d4 (alloc 0x2f0) stores GOT cell
  0x130e4c8 + 0x10 = 0x12bb1e8 at [owner] and cell + 0x100 = 0x12bb2d8
  at [owner+0x30]; owner D2 body 0x6fb174 re-stores the same pair.
- Slots (8, row 0x12bb2d8..0x12bb310; zero slots at +0x30/+0x38 double
  as the header of primary row 0x12bb318):
  - slot 0 (+0x00) 0x6fb5b4: D1 thunk; loads GOT cell 0x130e470
    (ParamContainerVtb448 header 0x12bb438) and stores cell+0x10 =
    0x12bb448 at [this-0x30] (reset to the ParamContainerVtb448
    primary; hierarchy implication unverified).
  - slot 1 (+0x08) 0x6fb5f0: D0 thunk (same reset + operator delete).
  - slots 2-5: shared band forwarders (see doc/object/Vt12bb078.md).
  - slots 6/7: 0, 0.

## Construction / init order

1. Ctor at 0x6fc4d4: new 0x2f0, primary vptr 0x12bb1e8 at [owner],
   band vptr 0x12bb2d8 at [owner+0x30].
2. Destruction: D2 0x6fb174 re-installs the primary/band pair.
