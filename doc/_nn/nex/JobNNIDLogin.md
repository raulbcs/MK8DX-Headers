# nn::nex::JobNNIDLogin

## Identity

- RTTI-confirmed: typeinfo slot 0x12e7ae0, typeinfo struct 0x12e7d80, name
  "N2nn3nex12JobNNIDLoginE". Installed vptr = 0x12e7af0 (assigned slot + 8);
  offset-to-top 0 at 0x12e7ae0. GOT cell 0x1314dd0 holds 0x12e7ae0
  (vptr-0x10); installed vptr = cell + 0x10.
- 13 slots (0x12e7af0..0x12e7b50): slot0 = 0xa44078 (shared with base
  nn::nex::JobLogin — the complete-dtor slot folds to the base D1, which
  reinstalls the JobLogin vptr), slot1 = D0 0xa442e0 (700 B, csv
  FUN_7100a442e0; reinstalls the base vptr, then tears down the derived
  member range), slots 2..12 are the shared nn::nex job block 0x5917a0 /
  0x58ff6c / 0x5917ac / 0x590148 / 0x59014c / 0x5917b0 / 0x5917cc / 0x58b7d8 /
  0x5917d4 / 0x5917d8 / 0x59189c.
- Correction over the previous header/doc: this class IS constructed — the
  earlier "NEVER CONSTRUCTED" note missed factory FUN_7100a43370.

## Member notes

- Size 0x1d0 PROVEN: factory FUN_7100a43370 news 0x1d0 via 0x573f04
  (0xa435f0..0xa435f8) for the branch that finalizes with the JobNNIDLogin
  vptr.
- 0x08..0xa0: nn::nex::ForcedCriticalSection base region (inherited; base
  init 0x588b04(this, 2, scratch) at 0xa4360c).
- +0x160/+0x164: id pair ([arg+0x18], ctor arg w2) written by the derived
  ctor segment (0xa4367c..0xa43690).
- +0x168: back-pointer to the owning factory object (x20).
- +0x178: arg from stack (w27); +0x180: scratch value (0x575b3c result).
- +0x1c0/+0x1c8: arg pointers (x24/x28); +0x1c0 region also released by the
  derived dtor path (0x589720 call at 0xa4487c).

## Construction / init order

1. Factory FUN_7100a43370 (0x5e4): `mov w0, #0x1d0; bl 0x573f04`
   (0xa435f0..0xa435f8), null check.
2. Base init 0x588b04 (0xa4360c), base vptr 0x12e7a78 installed
   (0xa43614..0xa43624), +0xa0 subobject init 0xa2bf88 (0xa43628).
3. Member zeroing pass +0x160..+0x1b0 (0xa4362c..0xa43664; ownership
   base-vs-derived unresolved).
4. Derived vptr 0x12e7af0 installed (cell 0x1314dd0 at 0xa43668..0xa43674),
   then derived field writes (0xa4367c..0xa436d0).
5. Destruction: derived dtor path in FUN_7100a4459c (installs base vptr at
   0xa44880 after derived teardown; tail operator delete 0x588bd0).

Size 0x1d0 proven by the factory allocation.
