# object::Vt12f6de0

PLACEHOLDER name. 0x378-byte aggregate in the Vt12f6f68 vtable family
(identical 11-slot tail 0x5917a0..0x59189c); allocated through a guarded
factory that also validates a request object first.

- Identity: C1 FUN_7100b18c9c. Factory prologue validates via
  FUN_71005822fc + virtual slot +0x48 on the owner, then
  `new 0x378` (0x7100b18cfc, operator-new FUN_7100573f04) and
  placement-init FUN_7100588b04.
- Vtable: row 0x12f6dd8 = offset-to-top 0; typeinfo slot 0x12f6de0 ->
  typeinfo object 0x12f7400 (name/base cells 0x12f7418/0x12f7428 ->
  0x128d520/0x128c4f8); installed vptr = 0x12f6de8 (GOT cell 0x1315938
  holds 0x12f6dd8 = vt-0x10).
- Slots (13): +0x00 D1 FUN_7100b29dac (124 B), +0x08 D0 FUN_7100b29f04
  (132 B); both re-install the vptr from cell 0x1315938 before tearing
  down. +0x10..+0x68 shared family tail: 0x5917a0 (12 B),
  0x58ff6c (220 B, U), 0x5917ac (4 B), 0x590148 (4 B), 0x59014c (unrec),
  0x5917b0 (unrec), 0x5917cc (unrec), 0x58b7d8 (tail of FUN_710058b7b8,
  36 B), 0x5917d4 (unrec), 0x5917d8 (unrec), 0x59189c (unrec). Same tail
  slots on Vt12f6e60/Vt12f6ff0/Vt12f6f68.

## Member notes

- +0x1b8: embedded member constructed by FUN_7100b29b10 (668 B) with
  x0 = this+0x1b8.
- +0x2c8: secondary vptr Vt12f7ac8 (cell 0x1315940, vt-0x10 0x12f7ab8).
- +0x2d8: sead-derived secondary vptr 0x128c698 (cell 0x130b4a8,
  vt-0x10 0x128c688).
- +0x2e0/+0x2f0: self-pointer pair (x8 = this+0x2e0 stored at +0x2f0).
- +0x358: member initialized by FUN_7100578900 (x1 = stack descriptor).
- +0xf8: subtree initialized by FUN_7100a2bf88(this+0xf8, nullptr);
  0xa0..0xf0 zeroed (wzr at +0xa0, +0xe0, xzr pairs 0xa8/0xc0/0xd8/0xe8);
  +0xb8 = 1.
- +0x370: zeroed after the +0x358 member call.

## Construction / init order

1. Factory validates owner (FUN_71005822fc + vslot +0x48).
2. `new 0x378`, placement-init FUN_7100588b04.
3. Zero 0xa0..0xf0, +0xb8 = 1, vptr 0x12f6de8 at +0x00.
4. Subtree init at +0xf8 (FUN_7100a2bf88).
5. Member ctor FUN_7100b29b10 at +0x1b8.
6. Self-pointer +0x2f0, zero +0x2c0/+0x300..+0x350, secondary vptrs
   +0x2d8 (sead 0x128c698) and +0x2c8 (Vt12f7ac8).
7. Member init at +0x358 (FUN_7100578900, stack descriptor), then
   +0x370 = 0.
