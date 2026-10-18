# nn::nex::CurlHttpConnection

## Identity

- RTTI: typeinfo 0x12e5780, name "N2nn3nex18CurlHttpConnectionE" (0xf852e0); si-type with base nn::nex::HttpConnection (typeinfo 0x12e5740).
- Row layout: 0x12e53e0 is the typeinfo slot; installed vptr = 0x12e53e8 (assigned+8); GOT cell 0x1314858 holds 0x12e53d8 (vptr-0x10).
- Note: the typeinfo name string address collides textually with std::__list_imp<URLProbe> naming seen in neighboring rodata; the typeinfo ptr chain (0x12e5780) is what binds this vtable to CurlHttpConnection.
- 24 slots (0x12e53e8..0x12e54a0).

## Slots (config/functions.csv)

- slot0 0xa1f9e4 (592B, contains the D2 block 0xa1f9fc that reinstalls the vptr from cell 0x1314858), slot1 0xa1fc10 (D0).
- slots 2-6: FUN_7100a1fc34 (220B) + FUN_7100a1fe5c-family (648B folds).
- slot7 0xa219f0 (724B), slot8 0xa200e4 (68B), slot9 0xa20d6c (116B), slots 10/11 0xa206a4 (620B folds), slot12 0xa20910 (152B), slot13 0xa209a8 (228B), slot14 0xa20a8c (252B), slots 15-17 0xa20b88 (376B folds), slot18 0xa20d00, slot19 0xa20d74 (216B), slots 20/22 0xa20e4c-family (940B folds), slots 21/23 0xa25454-family (292B folds).

## Member notes

- 0x50..0x19f: subobject initialized by 0x57a4e0 (bl at 0xa1f820, x0=this+0x50); further init via 0x578900 / 0x574a70 / 0x576368 in the same ctor.
- 0x1a0: second init region (add x0,x19,#0x1a0 at 0xa1f824).

## Construction / init order

1. Factory near 0xa21e30: `mov w0, #0x2e0; bl 0x573f04` (nex alloc), null-check, increment of the connection counter (cell 0x13148c0, ldr/add/str at 0xa21e28..0xa21e34), `bl 0xa1f7bc`.
2. Ctor 0xa1f7bc (unrecovered, 552B): vptr store from cell 0x1314858, then subobject inits at +0x50 and +0x1a0.

Size 0x2e0 proven by the factory allocation.
