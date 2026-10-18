# Vt12d5cf8

## Identity

- PLACEHOLDER name (identity not proven). GOT cell 0x1311dd8 holds
  0x12d5ce8 (vt-0x10); installed vptr = cell+0x10 = **0x12d5cf8** (row =
  installed vptr; offset-to-top 0, typeinfo 0).
- Direct derived class of Vt12c7d88 (base ctor FUN_71007d4c9c called
  with kind w1 = 9); sibling of Vt12d5c98 (kind 8) and Vt12d5d58 (see
  doc/object/Vt12c7d88.md for the hierarchy).
- size 0x170 proven by `operator new(0x170)` at the construction sites
  (0x80516c; sites 0x805190, 0x8059c4, 0x805d40 call the ctor
  FUN_71008dc2b0).
- Derived-slot overrides vs base: slots 1 (0x8dce50), 2 (0x8dc7d0),
  3 (0x8dc7e4), 6 (0x8dce3c), 8 (0x807ad8).

## Member notes

- +0x140/+0x144/+0x148 floats — copied in scalar form from the vector
  args (v1 pair, then v0) at ctor 0x8dc2e4..0x8dc2f0; duplicated again
  at +0x158..+0x164 (ctor 0x8dc30c..0x8dc314).
- +0x14C and +0x164 u64 — arg x1[0] (ctor 0x8dc300..0x8dc308,
  0x8dc320..0x8dc328); +0x154 and +0x16C — arg x1[8]
  (ctor 0x8dc2f8, 0x8dc318..0x8dc31c).
- Tail helper 0x8dc340 (tail-called by the ctor): stores 5 at +0x20
  (overriding the base's 6), 1.0f at +0xD4, 0 at +0xD8, 0 at +0xF0 and
  1.0f at +0xF4 (0x8dc364..0x8dc38c); rest of the 0x1c30-byte body is
  vertex/matrix math, not field-proven.

Slots (row 0x12d5cf8): slot0 0x7d4d44 (D1, inherited, unrecovered in
functions.csv); slot1 0x8dce50 (unresolved); slot2 0x8dc7d0 (7216-byte
body — draw/update, unresolved); slot3 0x8dc7e4 (unresolved); slot4
0x7d513c, slot5 0x7d5144, slot7 0x7d514c, slot9 0x7d515c inherited from
Vt12c7d88; slot6 0x8dce3c (unresolved); slot8 0x807ad8 (unresolved).

## Construction / init order

1. `operator new(0x170)` at the site (0x80516c).
2. Ctor FUN_71008dc2b0: base ctor 0x7d4c9c(this, 9, NULL) (0x8dc2d8).
3. Vector args split into +0x140..+0x164 floats (0x8dc2e4..0x8dc314).
4. Install vptr 0x12d5cf8 (0x8dc2dc..0x8dc2f4).
5. Arg x1 pairs to +0x14C/+0x154 and +0x164/+0x16C
   (0x8dc2f8..0x8dc32c).
6. Tail helper 0x8dc340: +0x20 = 5, base-region floats +0xD4/+0xD8/
   +0xF0/+0xF4, then vertex math.
