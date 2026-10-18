# object::Vt12e6fc8

PLACEHOLDER name. Vtable row label 0x12e6fc8; installed vptr 0x12e6fd0 (row 0x12e6fc8 is the
descriptor-pointer slot; GOT cell 0x1314be8 holds vptr-0x10 = 0x12e6fc0). Six virtual slots.
Identity: NEX/Rendez-Vous protocol descriptor — slot 3 returns 22, slot 4 returns the string
"RendezVousLogout" (0xf15736). Size 0x28, exact (allocation `mov w0,#0x28`).
Sibling of Vt12e6f88 ("RendezVousLogin", id 21); same base class and layout.

## Member notes

- Row layout: [vptr-0x10] = 0xa4230c (shared ret-stub, also slot 5 of Vt12e6f88's row),
  [vptr-0x8] = 0x12e7790 (per-row data descriptor holding fn 0xf860d0/0xf86100 and ptr
  0x12e7750; interpretation unverified), slots at vptr+0x00..+0x28: 0xa3efc8 (ret), 0xa3efcc
  (tail `b 0x573f48`, deleting dtor thunk), 0x5919c0 (shared thunk, tail-calls the slot at
  [vtable+0x18]), 0xa42310 (ret 22), 0xa42318 (ret "RendezVousLogout"), 0xa42324 (ret).
- Base class: ctor FUN_710058bd2c (36 bytes) writes +0x8 b = 0, +0x10 w = 0, +0x18 w = arg
  (called with 0), installs base vptr from cell 0x130b848 (value 0x128ced0, rodata) at +0x0,
  +0x9 b = 0.
- +0x20: owner back-pointer, stored at 0xa36b48 by the lazy-init accessor.
- Extent 0x28: `mov w0,#0x28` at 0xa36b24 immediately before operator new 0x573f04 — exact.

## Construction / init order

- Lazy member of a protocol manager at field +0x128: accessor function 0xa36a68
  (0xa36a68-0xa36b7c) checks [this+0x128]; if null, allocates 0x28 via 0x573f04, calls base
  ctor 0x58bd2c(obj, 0), installs derived vptr 0x12e6fd0 (0xa36b40-0xa36b50), stores owner at
  +0x20, caches at [this+0x128] (0xa36b24-0xa36b54).
- Tail-calls 0xa37510 (shared registration path with Vt12e6f88), which registers via 0x586d34.
- Destruction path beyond slot 1's operator-delete tail: not located (unverified).
