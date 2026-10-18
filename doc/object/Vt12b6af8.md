# Vt12b6af8

PLACEHOLDER name (address-anchored). Large aggregate object in the model/scene
code region (ModelScene::calc is FUN_71006bc4f4, the next function after the
ctor cluster). Extent 0x5ec8.

- Identity: no RTTI name; no owned string recoverable from the slots. Name
  stays PLACEHOLDER.
- vptr 0x12b6af8 installed at +0x00 by ctor FUN_71006bb300 (0x71006bb324..
  0x71006bb33c, GOT cell 0x130e1c0 holds 0x12b6ae8).
- Secondary vptr 0x12b6da0 (cell + 0x2b8, i.e. primary table + 83 slots)
  installed at +0xd0 (0x71006bb334/0x71006bb340).
- Derivation: ctor first calls FUN_7100732620 (ctor of the Vt12be028 class, at
  0x71006bb314), then FUN_71006155bc with this+0xd0 (0x71006bb318) - the
  Vt12be028 class is the primary base and a second base sits at +0xd0.
- Extent: caller FUN_71006b95ec allocates 0x5ec8 via allocFromHeapOrDefault
  (w0=0x5ec8, w2=8 align, 0x710060b234) then calls the ctor (0x71006b95f8..
  0x71006b9604).

## Member notes

- +0xf0 u32 zeroed (0x71006bb320); +0xf8 pointer to a 0x3e0-stride element
  array whose count header sits at ptr[-0x8]; destroyed element-wise by the
  destructor FUN_71006bb450 (0x71006bb488..0x71006bb4bc, element dtor
  FUN_71006ccfac).
- +0x360 self-pointer (stores this, 0x71006bb440).
- Sub-object ctor calls at this+0x16a0 (FUN_71006c0b68), +0x1dd8
  (FUN_71006e38e0), +0x39c8 (FUN_71006e22b4), +0x3cd0 (FUN_71006d9a60),
  +0x3fd0 (FUN_71006c36c0), +0x4d00 (FUN_71006dd190), +0x54b8
  (FUN_7100730fc8), +0x5670 (FUN_71006489bc), +0x5af8 (FUN_710064bdac),
  +0x5d48 (FUN_710063194c), +0x5e28 / +0x5e68 (FUN_7100628628) - addresses
  0x71006bb34c..0x71006bb43c.
- +0x5cf8 u64 zeroed; +0x5d00 u64 = 0xa39; +0x5d08 u64 = 3; +0x5d10 u32 = -1;
  +0x5d14 u64 zeroed; +0x5d1c u16 zeroed; +0x5d20 two 1.0f floats
  (0x71006bb3c8..0x71006bb3fc).
- +0x5e18 pointer zeroed by ctor (0x71006bb42c) and freed by the destructor
  (0x71006bb4c8..0x71006bb4d4); +0x5e10 u32 zeroed (0x71006bb420).
- Slots 0/1 (0x71006c0718 / 0x71006c07e4) are inherited dtors shared with the
  Vt12be028 table; slot 2 is the class destructor FUN_71006bb450, slot 3
  FUN_71006bb6d4. The 0x71006c0840..0x71006c0a40 thunk cluster (slots 6-81)
  is shared verbatim with the Vt12be028 table.

## Construction / init order

1. FUN_71006b95ec: allocFromHeapOrDefault(0x5ec8, align 8) (0x71006b95ec..
   0x71006b9604).
2. Ctor FUN_71006bb300: base Vt12be028-class ctor FUN_7100732620 (0x71006bb314);
   second base ctor FUN_71006155bc at +0xd0 (0x71006bb318); then the field and
   sub-object stores listed above in ascending offset order; vptrs at +0x00 /
   +0xd0 installed at 0x71006bb33c / 0x71006bb340.
