# object::Vt12ce9f8

PLACEHOLDER name (address-anchored). vptr 0x12ce9f8, 44 slots, typeinfo NULL
(game-side); offset-to-top and typeinfo words at 0x12ce9e8/0x12ce9f0 are zero.
Note: the vt_ctors.tsv row for this class is 0x12cea08 = vptr + 0x10.

- vptr convention: GOT cell 0x1310e78 holds 0x12ce9e8 (vt-0x10); installed
  vptr = cell+0x10 = 0x12ce9f8 (0x85CFE0-0x85CFE4).
- Table 0x12ce9f8: 44 slots (0x12ce9f8..0x12ceb58); slots 32/33 are
  __cxa_pure_virtual (0x12ceaf8/0x12ceb00); slots 42/43 are null.
- Abstract direct base of Vt12ce888, which is itself the base of Vt12ce718:
  the shared derived ctor FUN_710085664c calls this class's C1
  FUN_710085cfac(this, w1=0) first (0x856660), then installs the Vt12ce888
  vptr (see doc/object/Vt12ce888.md).
- No independent allocation: the only object is the derived Vt12ce718
  (operator new 0x918 at 0x3835f8); the base sub-object spans
  +0x00..+0x57 (derived zero-init run starts at +0x58).
- Slot 0 (0x85c49c) is the dtor-family head, shared verbatim with the
  Vt12ce888/Vt12ce718 tables; slot 1 (D0) is __cxa_pure_virtual.

## Member notes

Fields written by the base C1 FUN_710085cfac (0x85CFAC..0x85D0xx); layout is
identical to the sibling base Vt12ce0b8 (same C1 template, ICF-separated):

- [this+0x00] vptr 0x12ce9f8 (0x85CFE4).
- [this+0x08] u8 id — C1 arg w1 (0x85CFC8; caller passes 0).
- [this+0x10/+0x14/+0x18] element count / capacity / array of 0x28-byte
  elements initialized with stride arg 0x138 (0x85D054-0x85D0a0).
- [this+0x20] u8 = 1; [this+0x21] u8 = 0; pointers at +0x28/+0x40/+0x50 and
  u32s at +0x38/+0x48 zeroed (0x85CFD4-0x85D010).
- Base size 0x58 (standalone extent unproven).

## Construction / init order

1. Derived factory 0x3835e8: operator new(0x918) (Vt12ce718).
2. Base C1 FUN_710085cfac(this, 0): id at +0x08, zero-fill, vptr 0x12ce9f8
   at +0x00, flags, container fields, counted element loop.
3. Vt12ce888 phase: vptr 0x12ce888, +0x58 stride-0x18 zero run.
4. Vt12ce718 derived phase (see its doc).
