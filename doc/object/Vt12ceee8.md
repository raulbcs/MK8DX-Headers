# object::Vt12ceee8

PLACEHOLDER name (address-anchored). vptr 0x12ceee8, 44 slots, typeinfo NULL
(game-side); offset-to-top and typeinfo words at 0x12ceed8/0x12ceee0 are zero.
Note: the vt_ctors.tsv row for this class is 0x12ceef8 = vptr + 0x10.

- vptr convention: GOT cell 0x1310e90 holds 0x12ceed8 (vt-0x10); installed
  vptr = cell+0x10 = 0x12ceee8 (0x85EB70-0x85EB74).
- Table 0x12ceee8: 44 slots (0x12ceee8..0x12cf048); slots 32/33 are
  __cxa_pure_virtual (0x12cefe8/0x12ceff0); slots 42/43 are null.
- Abstract direct base of Vt12ced30, which is the direct base of Vt12ceb70:
  Vt12ced30's C1 FUN_710085d484 calls this class's C1 FUN_710085eb3c first
  (0x85d49c) — see doc/object/Vt12ced30.md.
- No independent allocation: the only object is the derived Vt12ceb70
  (operator new 0x680 at 0x3836AC); the base sub-object spans
  +0x00..+0x57 (Vt12ced30 stores its id at +0x60).
- Slot 0 (0x396f48) is the dtor-family head, shared verbatim with the
  Vt12ced30 table; slot 1 (D0) is __cxa_pure_virtual. Slots 4-10 and many
  later slots (0x397xxx cluster) are shared with the sibling bases.

## Member notes

Fields written by the base C1 FUN_710085eb3c (0x85EB3C..0x85ECxx); layout is
identical to the sibling base Vt12ce0b8 (same C1 template, ICF-separated):

- [this+0x00] vptr 0x12ceee8 (0x85EB74).
- [this+0x08] u8 id — C1 arg w1 (0x85EB58; Vt12ced30 passes 1).
- [this+0x10/+0x14/+0x18] element count / capacity / array of 0x28-byte
  elements initialized with stride arg 0x118 (0x85EBE4-0x85EC30).
- [this+0x20] u8 = 1; [this+0x21] u8 = 0; pointers at +0x28/+0x40/+0x50 and
  u32s at +0x38/+0x48 zeroed (0x85EB64-0x85EBA0).
- Base size 0x58 (standalone extent unproven).

## Construction / init order

1. Derived factory 0x3836AC: operator new(0x680) (Vt12ceb70).
2. Base C1 FUN_710085eb3c(this, w1): id at +0x08, zero-fill, vptr 0x12ceee8
   at +0x00, flags, container fields, counted element loop.
3. Vt12ced30 phase: id +0x60 = w2, vptr 0x12ced30, +0x70 block, element
   array stride 0x130 (Vt12ced30 doc).
