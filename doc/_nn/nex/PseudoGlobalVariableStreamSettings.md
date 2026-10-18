# nn::nex::PseudoGlobalVariableStreamSettings

RTTI-confirmed: typeinfo 0x12e4f70 -> mangled
`N2nn3nex20PseudoGlobalVariableINS0_14StreamSettingsEEE` =
nn::nex::PseudoGlobalVariable<nn::nex::StreamSettings>. Settings-profile
entry: three embedded sub-interface vptrs (+0x18/+0x50/+0x160/+0x198
reusing two vtables at 0x12e3458/0x12e3438), three embedded subobjects
constructed with FUN_7100574a70 at +0x78/+0x168/+0x1c0, and a block of
numeric defaults.

- Identity: C1 FUN_71009f7068 (1440 B) is called 8 times in a loop from
  the global-table init FUN_71009f7434; a second in-place init path lives
  in FUN_7100a1bf28 (site 0xa1c074).
- Vtable: vptr = 0x12e4f28. GOT cell 0x13145b0 holds 0x12e4f18 =
  vptr-0x10; sites add 0x10. Row: [0x12e4f18] = 0 (offset-to-top),
  [0x12e4f20] typeinfo slot -> 0x12e4f70.
- Sites: 0x9f709c (C1), 0x9f7380 (bulk init of table entries in
  FUN_71009f7358), 0x9f790c (slot0/D1 body), 0xa1c074 (in-place init).

## Member notes

- Slots (8): +0x00 D1 0x9f78f8 (re-installs vptr, destroys subobjects
  +0x1c0 and +0x78 via 0x576340), +0x08 D0 0xa1c060 (in FUN_7100a1bf28;
  D1 body + delete), +0x10 0xa1c0f8 (712 B), +0x18..+0x30 slots 3-6 all
  0xa1c3c0 (348 B, shared), +0x38 0xa1c51c (396 B).
- Defaults written by C1: +0x5c = 0, +0x68 = -1, +0x70 = -1, +0xc8 =
  1000, +0xd0 = 10000, +0xe8 = 1.25f, +0xec = 1.0f, +0xf0 = 50, +0xf4 =
  750, +0xf8 = 250, +0x108 = 2000, +0x114 = 2, +0x158 = -1, +0x208 = 20;
  bytes +0x58/+0xcc(unproven pad)/+0x110 = 0, +0x10d/+0x10f = 1.
- Size: lower bound 0x20c (max C1 store +0x20b); no per-object
  allocation found (table storage), so full size is unproven.

## Construction / init order

1. Storage provided by caller (global table entry).
2. C1 FUN_71009f7068: vptr (cell 0x13145b0) at +0x00; iface vptrs
   cells 0x13145b8/0x13145c0 at +0x18/+0x50; zeros/-1 block +0x58..+0x70;
   subobject ctor 0x574a70 at +0x78; +0xc8..+0x114 defaults; iface vptrs
   at +0x160/+0x198; subobject ctors at +0x168 and +0x1c0; +0x208 = 20.
