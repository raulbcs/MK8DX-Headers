# nn::nex::AuthenticationInfo

RTTI-confirmed: typeinfo 0x12e7eb0 -> mangled `N2nn3nex18AuthenticationInfoE`
= nn::nex::AuthenticationInfo. Small value object describing an
authentication result; constructed inline at both sites (no standalone
C1).

- Vtable: vptr = 0x12e7e68. GOT cell 0x1314db8 holds 0x12e7e58 =
  vptr-0x10; sites do `ldr cell; add #0x10; str [this]`. Row:
  [0x12e7e58] = 0 (offset-to-top), [0x12e7e60] typeinfo slot ->
  0x12e7eb0.
- vptr sites: 0xa42fdc (factory FUN_7100a42e30), 0xb4cb00 (inside
  FUN_7100b4c294); additional cell users 0xa443dc (FUN_7100a442e0) and
  0xa44bb4 (FUN_7100a44af0).
- Size 0x48: factory FUN_7100a42e30 allocates exactly 0x48
  (`mov w0, #0x48; bl 0x573f04` at 0xa42fb0) before the inline init.

## Member notes

- Slots (9): +0x00 D1 0xa457e8, +0x08 D0 0xa4582c, +0x10 0xb4cabc,
  +0x18 0xb4cb88, +0x20 0xb4cbb8, +0x28 0xb4cbec (slots 2-5
  unrecovered, no functions.csv entries), +0x30 0xb4cbcc (16 B),
  +0x38 0xb4cbdc (2036 B).
- +0x18..+0x30 looks like an inline string/buffer: first byte zeroed,
  pointer at +0x28 = this+0x18, constant 0x10 at +0x30 (interpretation
  unverified).
- Constants from the FUN_7100b4c294 variant: +0x38 = 4, +0x3c = 2,
  +0x40 = 0xfab (4011).

## Construction / init order

1. Allocate 0x48 (factory FUN_7100a42e30 at 0xa42fb0) or use caller
   storage (FUN_7100b4c294).
2. Zero byte +0x09, store caller object+0x10 at +0x10, zero byte
   +0x18.
3. Install vptr at +0x00 (cell 0x1314db8 + 0x10).
4. Store this+0x18 at +0x28 and 0x10 at +0x30; store 4 at +0x38,
   2 at +0x3c, 0xfab at +0x40.
