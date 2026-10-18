# nn::nex::JobLogin

## Identity

- RTTI-confirmed: typeinfo slot 0x12e7a70, typeinfo struct 0x12e7d40, name
  "N2nn3nex8JobLoginE". Installed vptr = 0x12e7a78 (assigned slot + 8);
  offset-to-top 0 at 0x12e7a70. GOT cell 0x1314dc8 holds 0x12e7a70
  (vptr-0x10); installed vptr = cell + 0x10.
- 13 slots (0x12e7a78..0x12e7ad8): slot0 = D1 0xa44078 (132 B, csv
  FUN_7100a44078), slot1 = D0 0xa440fc (140 B, D1 body + operator delete
  0x573f48), slots 2..12 are the shared nn::nex job block 0x5917a0 / 0x58ff6c /
  0x5917ac / 0x590148 / 0x59014c / 0x5917b0 / 0x5917cc / 0x58b7d8 / 0x5917d4 /
  0x5917d8 / 0x59189c.
- Correction over the previous header: the previously cited "ctor 0xa20e4c /
  size 0x118" is wrong — FUN_7100a20e4c never touches GOT cell 0x1314dc8 (it
  is an unrelated 940 B vector-copy helper). JobLogin is the base class of
  nn::nex::JobNNIDLogin; no standalone allocation of a JobLogin-final object
  exists.

## Member notes

- 0x08..0xa0: nn::nex::ForcedCriticalSection base region (base init
  0x588b04(this, 2, scratch)).
- +0x190: pointer member released by D1 (virtual call through [+0x190]+8 when
  non-null).
- +0x198: secondary vptr from cell 0x130b4a8, reinstalled by D1 before
  destroying it (0x5790b4).
- +0x1a0..: subobject init 0xa2c1e8 in D1.
- Size: lower bound 0x1a0 (D1 stores [+0x198]); no standalone allocation, so
  the exact complete-object size is unproven. Derived JobNNIDLogin allocates
  0x1d0 (see its doc), bounding this class below that.

## Construction / init order

1. Factory FUN_7100a43370 (0x5e4): constructs a derived login job (0x1d0 via
   0x573f04 at 0xa435f0) — the inlined base ctor installs the JobLogin vptr
   first (cell 0x1314dc8 at 0xa43614..0xa43624), then the derived ctor
   overrides [obj] with the JobNNIDLogin vptr (cell 0x1314dd0 at
   0xa43668..0xa43674).
2. Destruction: derived dtor path FUN_7100a4459c runs the NNID members, then
   inlines JobLogin::D1 (vptr re-install at 0xa44880) and the base teardown.
