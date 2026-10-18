# nn::nex::JobTerminate

## Identity

- vtable 0x12e7b68, 13 slots. GOT cell 0x1314e00 holds 0x12e7b58 = vptr-0x10
  (offset-to-top row 0x12e7b58 = 0, descriptor slot 0x12e7b60 = 0x12e7da0);
  installed vptr = cell+0x10. Every install site does `ldr cell; add #0x10; str [this]`.
- RTTI: descriptor 0x12e7da0 = {0x10, name 0xf86420, 0x2<<32, base 0x128d520};
  name 0xf86420 = "N2nn3nex12JobTerminateE" (nn::nex::JobTerminate);
  base 0x128d520 = "N2nn3nex15StepSequenceJobE" (nn::nex::StepSequenceJob).
- Slot map (13): 0 D1 0xa447cc, 1 D0 0xa44800, then the shared nex-family cluster
  2 0x5917a0 (12 B forward-to-slot-3 thunk), 3 0x58ff6c (220 B), 4 0x5917ac (ret),
  5 0x590148 (ret), 6 0x59014c, 7 0x5917b0, 8 0x5917cc, 9 0x58b7d8, 10 0x5917d4,
  11 0x5917d8, 12 0x59189c — identical 11-slot block in every nex job table.
- D1 0xa447cc: re-installs vptr 0x12e7b68, tail-calls 0x585ae0(this+0xb0) (the
  +0xb0 sub-object D1), then tail 0x588bd0 (shared job-base D1). D0 0xa44800:
  same body then operator delete 0x573f48.
- Sites (vt_ctors): 0xa447dc / 0xa44810 (inside D1/D0) and 0xa43da0 (factory).
  NOTE: nearby function 0xa43c10 is a manager method, not this class's ctor.

## Member notes

- Size 0x140 PROVEN: operator new(0x140) at 0xa43d78 (alloc helper 0x573f04),
  then shared job ctor 0x588b04(this, 2, scratch) at 0xa43d98.
- Shared job region [0x00,0xa0) from 0x588b04: +0x8 flag 1, +0xc u8 0,
  +0x10..0x28 zeroed, +0x28 ptr 0, +0x30 u32, +0x38 u32 = 2 (the w1 arg),
  +0x40..0x70 zeroed, +0x61 u8 1; ends by re-installing vptr (cell 0x130b7a8,
  vptr 0x128d060) at [this] and storing secondary vptr 0x128d9f8 (cell
  0x130b798) at [this+0x78]. The factory then overwrites [this] with
  0x12e7b68 (0xa43da8).
- +0x98 second vptr 0x128d9f8 (0xa43e30); +0xa0 owner back-pointer (0xa43e30);
  +0xa8 u32 copied from owner+0x18 (0xa43e2c).
- +0xb0 sub-object vptr 0x128cc20 (cell 0x130b740 = vptr-0x10, 0xa43dec);
  destroyed first by D1 via 0x585ae0(this+0xb0). +0xb8 = 1 (stlr, 0xa43dbc).
- +0xd0/{+0xd8} = self-pointers to +0xd0 (0xa43df4); +0xe0..+0x108 zeroed;
  +0x108 member inited by 0x5788e0(this+0x108, scratch) (0xa43e0c);
  +0x120/+0x128 and +0x130..+0x140 zeroed (0xa43e14-0xa43e1c).

## Construction / init order

1. Factory (inside FUN_7100a43c10 at 0xa43d78): operator new(0x140) via 0x573f04.
2. Shared job ctor 0x588b04(this, 2, scratch) (0xa43d98) builds the [0,0xa0)
   base region and stores the intermediate vptr.
3. Factory: vptr 0x12e7b68 -> [this] (0xa43da8), +0xb0 sub-vptr (0xa43dbc),
   +0xb8 stlr 1, then the field stores listed above (+0xc0..+0x140, 0xa43dcc-
   0xa43e2c), including the owner back-pointer at +0xa0.
