# Vt12bf3c0

PLACEHOLDER name (address-anchored). 42-slot game class, member of a sibling
family (with Vt12bf520 and Vt12c0ed8) that shares base ctor FUN_7100738d68
and a large block of identical slots, created by one factory/dispatch
function at 0x73ab00. Extent 0x98.

- Identity: no RTTI name (GOT cell 0x130ec28 holds 0x12bf3b0 = vt-0x10, row
  address 0x12bf3c0 IS the installed vptr).
- vptr 0x12bf3c0 installed at +0x00 by ctor FUN_710073c66c (0x73c680..
  0x73c6a4).
- Extent: factory 0x73ac7c allocates 0x98 via alignedAlloc(size 0x98,
  align 4) (0x73ac7c..0x73ac94) then calls the ctor.

## Member notes

- Base ctor FUN_7100738d68 called first (0x73c67c).
- +0x70 u8 zeroed (0x73c6a0); +0x71 u8 = 1 (0x73c690); +0x78 pointer zeroed
  (0x73c694); +0x80 / +0x88 pointers zeroed (0x73c698); +0x90 u8 zeroed
  (0x73c68c).
- Slot 0 FUN_710073c660 is a 12-byte function returning a .dynstr string
  pointer (0xf0724d); slot 2 FUN_71007343a0 is a 4-byte stub shared verbatim
  with the sibling tables.
- Sibling override examples: slot 39 (FUN_710073c6cc) reads +0x42 bit 6 and
  copies +0x80 to +0x50 (0x73c6d4..0x73c6dc); slot 40 FUN_710073c738 and
  slot 31 FUN_710074aa38 are family-shared game methods.

## Construction / init order

1. Factory 0x73ac7c: alignedAlloc(0x98, align 4) (0x73ac7c..0x73ac90).
2. Ctor FUN_710073c66c: base ctor FUN_7100738d68 (0x73c67c); field stores
   listed above; vptr 0x12bf3c0 at +0x00 installed at 0x73c6a4.
