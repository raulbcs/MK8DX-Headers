# PaneBnd1

## Identity

- vtable 0x12bf8a0, 28 slots, GOT cell 0x130ecc8 holds vt-0x10 (0x12bf890);
  installed vptr = cell+0x10.
- Factory: pane-tag dispatcher 0x7430bc: tag "bnd1" (w2 == 0x31646e62,
  checked at 0x743108) allocates 0xe0 (align 0x10) and calls ctor 0x73fb2c
  (0x743214..0x743238). No resource-string gate.
- MI chain: C1 0x73fb2c calls intermediate base C1 0x5ac4d8 (installs vptr
  0x12ad428 from cell 0x130ca18), then re-installs 0x12bf8a0 at +0x00.

## Member notes

- No owned field stores in the C1; extent 0xe0 comes from the factory
  allocation. Content of +0x08..+0xdf initialized by 0x5ac4d8/0x5a22e4 -
  unproven.
- Dtor triple: slot 0 D1 0x5ac50c (tail 0x5a22e0), slot 1 D0 0x73fb5c (calls
  0x5ac50c then operator delete 0x60b470), slot 2 0x73fb80 (guarded static
  getter over cells 0x130ebd8/0x130ea20/0x12fbbe0).
- Slots 6-27 shared 0x5a2xxx cluster; slot 22 = 0x5ac534 (family override,
  unrecovered).

## Construction / init order

1. Factory 0x743214: "bnd1" tag match; aligned_alloc(0xe0, align 0x10) at
   0x74321c.
2. C1 0x73fb2c: intermediate base ctor 0x5ac4d8 (0x73fb3c); vptr 0x12bf8a0
   at +0x00 (0x73fb44..0x73fb4c).
