# Vt12d3ba0

## Identity

- PLACEHOLDER name (identity not proven). GOT cell 0x1311870 holds
  0x12d3ba0-0x10; installed vptr = cell+0x10 = **0x12d3ba0** (row =
  installed vptr; offset-to-top 0, typeinfo 0 at 0x12d3b90/0x12d3b98).
- Pooled keyed-entry class, sibling of Vt12d3b40/Vt12d3ae0 family (see
  doc/object/Vt12d3b40.md).
- Member subobject of the 0xC78-size base initialized by FUN_71008a12f0.
  vptr store at [base+0xa60] (0x8a1c44); the region runs to the end of
  the 0xC78 base, bounding it at 0x218. Trailing members beyond the
  family layout are unverified.
- 10 slots, all game-side FUN_*/stub addresses, no symbols.

## Member notes

All offsets relative to the subobject this (per-byte layout unproven,
mirrors the family layout):

- +0x08/+0x0C u32 — key pair (family layout).
- +0x10 ptr — release handle (family layout).
- +0x25 u8 — flag guarding the virtual dispose (family behavior,
  unverified).
- +0x100 s32 — initialized to -1 by the inline ctor (0x8a1c70..0x8a1c7c,
  mov w9, #-1); distinguishes this clone from Vt12d3b40.

Slots (row 0x12d3ba0): slot0 0x8a3718 release (installs a family base
vptr from GOT cell 0x13082a0, tail-calls reset 0x8a6bcc); slot1
0x8a3568 release + operator delete (unverified); slot2 0x8a359c (56
bytes; family key != -1 check, unverified); slot3 0x8a35d4 Equals (344
bytes, unverified); slot4 0x8a365c (family static-pair copy,
unverified); slot5 0x8a0c90 (456 bytes; family registry lookup,
unverified); slot6 0x8a1190 (352 bytes, unresolved); slot7 0x3ddcfc
returns 1; slot8 0x8a6f4c (unresolved); slot9 0x8a12c0 (unresolved).

## Construction / init order

1. No standalone C1; default-constructed inline inside FUN_71008a12f0:
   members zeroed (0x8a1be0..0x8a1c2c), vptr 0x12d3ba0 installed at
   [base+0xa60] (0x8a1c30..0x8a1c44).
2. Embedded member constructed via 0x61cc48 at sub+0xA8 (0x8a1c58); flag
   byte stored through the member pointer (0x8a1c5c..0x8a1c60).
3. s32 -1 stored at sub+0x100 (0x8a1c70..0x8a1c7c); further inline
   member init continues (string vtable 0xed6af8 at sub+0x128,
   0x8a1c84..0x8a1c8c).
4. Destruction path not observed standalone (pooled; slot0/slot1 release
   entries).
