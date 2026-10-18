# Vt12c0ed8

PLACEHOLDER name (address-anchored). 42-slot game class, sibling of
Vt12bf3c0 / Vt12bf520 (shared base ctor FUN_7100738d68 and large identical
slot blocks), created by the same factory/dispatch function at 0x73ab00.
Extent 0x80.

- Identity: no RTTI name (GOT cell 0x130eb80 holds 0x12c0ec8 = vt-0x10, row
  address 0x12c0ed8 IS the installed vptr).
- vptr 0x12c0ed8 installed at +0x00 by inline construction in the factory
  (vptr store at 0x73ab98 reached from the 0x73ac44 branch); there is no
  separate out-of-line ctor for this sibling.
- Extent: factory 0x73ac44 allocates 0x80 via alignedAlloc(size 0x80,
  align 4) (0x73ac44..0x73ac58).

## Member notes

- Base ctor FUN_7100738d68 called first (0x73ac5c).
- +0x70 u8 zeroed (0x73ac64); +0x71 u8 = 1 (0x73ac68); +0x78 pointer zeroed
  (0x73ac74). Same +0x70/+0x71 pattern as the Vt12bf3c0 ctor.
- Slot 1 FUN_710074ac9c, slot 19 FUN_710074ab20 and slot 23 FUN_710074ac3c
  are class-specific overrides; slot 2 FUN_71007343a0 is the 4-byte stub
  shared with the sibling tables; slots 4-18 and 21/22/29/31 are identical
  to the siblings' (FUN_7100739c44, FUN_7100739474, FUN_71007394f4,
  FUN_71007397d0, FUN_710074aa38).
- Sibling dispatch: the shared factory tail calls slot 15 (0xf8 = 248, i.e.
  +0x10 + slot 15*8) on the new object and registers it via the caller's
  slot 4 (0x73aba0..0x73abcc).

## Construction / init order

1. Factory 0x73ac44: alignedAlloc(0x80, align 4) (0x73ac44..0x73ac58).
2. Inline init: base ctor FUN_7100738d68 (0x73ac5c); +0x70 = 0, +0x71 = 1,
   +0x78 = 0 (0x73ac60..0x73ac74); vptr 0x12c0ed8 at +0x00 (0x73ab98).
