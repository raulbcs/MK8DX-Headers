# object::Vt12c4fb8

PLACEHOLDER name. s8 variant of the scalar quant-channel sibling set
(0x12c4d68 / 0x12c4e90 / 0x12c4fb8). Selected by the inlined scalar factory
FUN_71007b95a8 when the computed bit width is < 9; quantizes into an s8
domain with the fixed limits -128.0f / +127.0f.

- Identity: no RTTI; no owned string from the slots. Name stays PLACEHOLDER.
- vptr convention: GOT cell 0x130fe98 holds 0x12c4fa8 (vt-0x10, RELA addend);
  installed vptr = cell+0x10 = 0x12c4fb8.
- Primary table 0x12c4fb8: 35 slots (0x12c4fb8..0x12c50d0).
- Base: recorderBinderCtor_71007aae24 runs first, then the derived vptr
  overwrites +0x000.
- Size: operator new(0x288) at 0x71007b9698 inside FUN_71007b95a8 (shared
  allocation for the two quantized branches); deepest stores are the limit
  floats at +0x280/+0x284.

## Member notes

- +0x1c0 = 8, +0x1c4 = 2 (0x71007b9708..0x71007b9714, via w8 = 2 path).
- +0x280 = -128.0f (0xed6874), +0x284 = +127.0f (0xed6624)
  (0x71007b9718..0x71007b971c).
- +0x278: owner back-pointer, factory x19 (0x71007b970c).
- Tail: +0x1f0 = step, +0x1f4 = (2^7 - 1)/range, +0x1f8 = reciprocal
  (shared exp2f tail at 0x71007b9720..0x71007b974c, s0 = 7.0).
- Slots: slot 0 = 0x7b3ea4 (unrecovered, D1), slot 1 = FUN_71007b3f70 (D2),
  slot 2 = FUN_71007b3fcc; own override cluster 0x7b3ea4..0x7b40a0 and
  0x7b41cc..0x7b42bc; base/tail slots shared verbatim with the siblings.

## Construction / init order

Inlined in FUN_71007b95a8 (0x71007b96d8..0x71007b96fc), taken when
w21 (bit width) < 9:

1. `operator new(0x288)` (0x71007b9698); recorderBinderCtor_71007aae24
   (0x71007b96dc).
2. vptr = GOT cell 0x130fe98 + 0x10 (0x71007b96e4..0x71007b9704).
3. +0x278 = owner; +0x1c0 = 8; +0x1c4 = 2; +0x280/+0x284 = s8 limits
   (0x71007b970c..0x71007b971c).
4. Shared exp2f tail computes +0x1f4/+0x1f8 (0x71007b9720..).
