# nn::nex::JobAcquireAccessToken

## Identity

- vtable 0x12d70b8, 13 slots. GOT cell 0x1312108 holds 0x12d70a8 = vptr-0x10
  (row 0x12d70a8 = typeinfo-slot row); installed vptr = cell+0x10.
- RTTI: typeinfo 0x12d7460 (at vptr-8), name 0xf7d4a0
  "nn::nex::JobAcquireAccessToken". ot = 0.
- Slot 0 = 0x8fd918 (752 B) which is itself the full init entry used by
  placement constructors; slot 1 = 0x8fdc84 (D1, tail of FUN_71008fdc08);
  slots 2..12 are the shared nex-family cluster
  0x5917a0/0x58ff6c/0x5917ac/0x590148/0x59014c/0x5917b0/0x5917cc/0x58b7d8/
  0x5917d4/0x5917d8/0x59189c (same 11-slot block recurring in the 16c batch).

## Member notes

- Size 0x560 PROVEN: static factory FUN_71008ff0b4 allocates w0 = 0x230
  (= 0x560) via 0x573f04 (0x8ff0e4..0x8ff0ec), then memzero-style init
  0x588b04(obj, 2, scratch) and installs the vptr (0x8ff104..0x8ff124).
- MI layout: secondary vptrs at +0x38, +0xa8, +0x190, +0x1a0, +0x1a8,
  +0x1d0, +0x1e0, +0x208, each followed by a 0x5790b4 sub-init call:
  - slot0 fn 0x8fd918: [this] = 0x12d70b8, [this+0x1d0] = cell 0x1312118,
    [this+0x208] = cell 0x130b4a8, [this+0x1e0] = cell 0x1312120 value,
    [this+0x1d0] overwritten with cell 0x1312120, stp at +0x1a0 =
    {cell 0x1312120, same}, [this+0x190] = cell 0x13120f8.
  - FUN_71008fdc08 (placement variant): [this] = 0x12d70b8,
    [this+0x38] = cell 0x1312110, [this+0x1d0] = cell 0x1312118,
    [this+0x10 post-index] = cell 0x1312118 value.
  - Factory FUN_71008ff0b4: [this+0xa8] = cell 0x130b618;
    words +0xa0 = 0 and +0xa4 = 0x10.
- Four install sites (vt_ctors): 0x8fd934 (slot0 fn), 0x8ff108 (factory
  FUN_71008ff0b4), 0x90a7e4 and 0x90cc74 (both inside
  enl::TaskThread::ThreadHeap#2, 0x907d10) - job instances also built
  in place on task threads.

## Construction / init order

1. Factory FUN_71008ff0b4: alloc 0x560 via 0x573f04 (0x8ff0e4).
2. 0x588b04(obj, 2, scratch) zero/tag init (0x8ff0f4..0x8ff100).
3. Vptr 0x12d70b8 at +0x00 (0x8ff104..0x8ff124); words +0xa0/+0xa4;
   secondary vptr +0xa8; +0xb0 sub-init.
4. Slot0 init entry 0x8fd918 (called via FUN_71008fdc08 or in place):
   installs primary vptr and the +0x190/+0x1a0/+0x1a8/+0x1d0/+0x1e0/+0x208
   secondary vptrs, each sub-object initialized by 0x5790b4.
