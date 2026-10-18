# object::Vt12f6ff0

PLACEHOLDER name. 0x2a8-byte aggregate, Vt12f6f68 vtable family.

- Identity: C1 FUN_7100b193c8. Factory validates owner (FUN_71005822fc +
  vslot +0x48), then `new 0x2a8` (0x7100b19420) and placement-init
  FUN_7100588b04.
- Vtable: row 0x12f6fe8 = offset-to-top 0; typeinfo slot 0x12f6ff0 ->
  typeinfo object 0x12f7500; installed vptr = 0x12f6ff8 (GOT cell
  0x1315948 holds 0x12f6fe8 = vt-0x10).
- Slots (13): +0x00 D1 FUN_7100b2fb8c (196 B), +0x08 D0 FUN_7100b2fda0
  (36 B). D1 re-installs vptr from cell 0x1315948, deletes pointers
  +0x2a0, +0xb0 (virtual slot +0x08 each), +0x278 (free), runs member
  dtor FUN_7100b2fc50 on +0x1f8, resets +0x1b8 to the member's base
  vtable (cell 0x1310d50 -> 0x84d17c), drains the +0x1e0 vector, and
  destroys the +0xf8 subtree (FUN_7100a2c1e8). +0x10..+0x68 shared
  family tail as Vt12f6de0.

## Member notes

- +0x1b8: secondary vptr Vt12f7dc8 (cell 0x1315950, vt-0x10 0x12f7db8);
  D1 proves the member derives from the 0x84d17c base.
- +0x208: sead-derived secondary vptr 0x128c698 (cell 0x130b4a8).
- +0x220: self-pointer (this+0x210).
- +0x228: secondary vptr Vt12f7e48 (cell 0x1315958, vt-0x10 0x12f7e38).
- +0xf8: subtree (FUN_7100a2bf88 init, FUN_7100a2c1e8 destroy).
- +0xb0: owned pointer destroyed through vslot +0x08.
- +0x1c0 byte, +0x1d0..+0x200 zeroed in ctor.

## Construction / init order

1. Factory validates owner, `new 0x2a8`, placement-init.
2. Zero 0xa0..0xf0 (+0xb8 = 1), vptr 0x12f6ff8 at +0x00, subtree +0xf8.
3. +0x1c0 = 0, +0x1d0..+0x200 zero.
4. Secondary vptrs +0x1b8 (Vt12f7dc8) and +0x208 (sead 0x128c698).
5. Self-pointer +0x220, zero +0x230..+0x270, secondary vptr +0x228
   (Vt12f7e48).
