# object::Vt12ce0b8

PLACEHOLDER name (address-anchored). vptr 0x12ce0b8, 44 slots, typeinfo NULL
(game-side); offset-to-top and typeinfo words at 0x12ce0a8/0x12ce0b0 are zero.
Note: the vt_ctors.tsv row for this class is 0x12ce0c8 = vptr + 0x10.

- vptr convention: GOT cell 0x1310de8 holds 0x12ce0a8 (vt-0x10); installed
  vptr = cell+0x10 = 0x12ce0b8 (0x852F78-0x852F7C).
- Table 0x12ce0b8: 44 slots (0x12ce0b8..0x12ce218); slots 32/33 are
  __cxa_pure_virtual (0x12ce1b8/0x12ce1c0); slots 42/43 are null.
- Abstract direct base of Vt12cdf48: its C1 is the helper FUN_7100852f44
  called with (this, w1=2) from Vt12cdf48's ctor FUN_71008513f4 (0x851408).
- No independent allocation: the only object is the derived Vt12cdf48
  (operator new 0x1d0 at 0x3836A8); the base sub-object spans +0x00..+0x57
  (derived fields start at +0x58, see Vt12cdf48 doc).
- Slot 0 (0x85238c) is the dtor-family head, shared verbatim with the
  Vt12cdf48 table; slot 1 (D0) is __cxa_pure_virtual.

## Member notes

Fields written by the base C1 FUN_7100852f44 (0x852F44..0x8530xx):

- [this+0x00] vptr 0x12ce0b8 (0x852F7C).
- [this+0x08] u8 id — C1 arg w1 (0x852F60; caller passes 2).
- [this+0x0C] u32 zeroed (0x852F74); +0x10 u32 element count, +0x14 u32
  capacity, +0x18 ptr to element array (ctor zeroes 0x14-0x1F via
  stur xzr[x19+0x14] + str wzr[x19+0x1C]) (0x85300C-0x85302C loop:
  operator new(0x28) elements initialized by FUN_7100396744 with stride arg
  0x170).
- [this+0x20] u8 = 1 (0x852F84); [this+0x21] u8 = 0 (0x852F88).
- [this+0x28] ptr = 0 (0x852F8C); [this+0x30] u8 = 0 (0x852F90).
- [this+0x38] u32 = 0 (0x852F94); [this+0x40] ptr = 0 (0x852FA0).
- [this+0x48] u32 = 0 (0x852FA4); [this+0x50] ptr = 0 (0x852FA8).
- Base size 0x58 (derived init starts at +0x58; standalone extent unproven).
- Shared slot 11 (0x8533e4) and slot 30 (0x8533e8) are thunk stubs also used
  by the sibling tables Vt12ce560/Vt12ce9f8/Vt12ceee8.

## Construction / init order

1. Derived factory 0x3835e8: operator new(0x1d0) (Vt12cdf48).
2. Base C1 FUN_7100852f44(this, 2): id at +0x08, zero-fill +0x0C and 0x14-0x1F,
   vptr 0x12ce0b8 at +0x00, flags +0x20/+0x21, container pointers, then the
   counted element loop (count/cap at +0x10/+0x14, array at +0x18).
3. Derived phase continues (Vt12cdf48 doc).
