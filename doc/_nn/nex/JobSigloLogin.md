# nn::nex::JobSigloLogin

## Identity

- vtable 0x12e7be0, 13 slots. GOT cell 0x1314de0 holds 0x12e7bd0 = vptr-0x10
  (offset-to-top row 0x12e7bd0 = 0, descriptor slot 0x12e7bd8 = 0x12e7de0);
  installed vptr = cell+0x10.
- RTTI: descriptor 0x12e7de0 = {0x10, name 0xf86440, base 0x12e7d40, 0};
  name 0xf86440 = "N2nn3nex13JobSigloLoginE" (nn::nex::JobSigloLogin);
  base 0x12e7d40 = "N2nn3nex8JobLoginE" (nn::nex::JobLogin).
- Slot map (13): 0 D1 0xa4483c, 1 D0 0xa448ec, then the shared nex-family
  cluster 2 0x5917a0, 3 0x58ff6c, 4 0x5917ac, 5 0x590148, 6 0x59014c,
  7 0x5917b0, 8 0x5917cc, 9 0x58b7d8, 10 0x5917d4, 11 0x5917d8, 12 0x59189c.
- D1 0xa4483c: re-installs vptr 0x12e7be0, destroys the +0x1e8 sub-object
  (0x5790b4), destroys +0x1c0 (0x589720), re-installs the base JobLogin vptr
  0x12e7a78 at [this] (0xa4488c), removes itself from the global tree rooted
  at cell 0x1314cb0 (0xa44894-0xa448a8), destroys the +0x198 sub-object and
  the +0x190 member, destroys +0xa0 via 0xa2c1e8, tail 0x588bd0.
- D0 0xa448ec: same body then operator delete. Sites (vt_ctors): 0xa44854 /
  0xa44904 (inside D1/D0) and 0xa4375c (factory in FUN_7100a43370).

## Member notes

- Size 0x230 PROVEN: operator new(0x230) at 0xa436e8 (alloc helper 0x573f04)
  inside FUN_7100a43370; shared job ctor 0x588b04(this, 2, scratch) at 0xa43704.
- Shared job region [0x00,0xa0) from 0x588b04 (see JobTerminate.md), including
  secondary vptr 0x128d9f8 at +0x78; factory overwrites [this] with
  0x12e7be0 (0xa43770).
- +0x188 sub-object vptr 0x12e7ed8 (cell 0x1314da8 = vptr-0x10, 0xa4373c).
- +0x190 nullable member pointer (virtually destroyed in D1 if non-null);
  +0x198 sub-object vptr 0x128c698 (cell 0x130b4a8 = vptr-0x10).
- +0x1b0 = self-pointer to the +0x1a0 flag byte; +0x1b8 = 0x10 (0xa4376c).
- +0x1c0 member: init 0x5896c0 (0xa43774), destroy 0x589720 (D1 0xa44878).
- +0x1e8 sub-object vptr 0x128c698 again (0xa43784); +0x200 = self-pointer to
  +0x1f0; +0x208 = 0x10 (0xa4378c). +0x160..+0x178 zeroed (0xa43724-0xa43738).

## Construction / init order

1. FUN_7100a43370: operator new(0x230) (0xa436e8).
2. Shared job ctor 0x588b04(this, 2, scratch) (0xa43704).
3. Factory field stores: zero +0x160..+0x178; +0x188 sub-vptr; +0x198
   sub-vptr; +0x1a0 flag; +0x1b0/+0x1b8 pair; vptr 0x12e7be0 -> [this]
   (0xa43770); 0x5896c0(this+0x1c0); +0x1e8 sub-vptr; +0x1f0 flag;
   +0x200/+0x208 pair (0xa43724-0xa4378c).
4. Post-ctor: [x25+0x1fd0] = 0x2000 etc. in the enclosing manager context
   (0xa4377c onward touches owner fields, not this object).
