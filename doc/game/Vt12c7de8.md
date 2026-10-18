# Vt12c7de8

Unnamed class, sibling of Vt12c7de8-family member Vt12c7c70. No RTTI.
Hierarchy: root ctor 0x6155bc (vptr 0x12b0058 via cell 0x130d298) → base
init 0x7d34d8 (vptr 0x12c7cc0 via cell 0x130fff0) → this init 0x7d5164
(vptr 0x12c7de8 via cell 0x1310018; cells hold vptr-0x10, installed vptr
= cell + 0x10).

## Init / sites

- Init C1: 0x7d5164 (site 0x7d5188). Signature like 0x7d3184: (this,
  floats s0/s1, struct* x1). Calls base 0x7d34d8 first.
- Heap: `mov w0, #0xe8; bl _Znwm` at 0x804e20 then init (FUN_7100804db0).
  Size 0xe8 EXACT.
- Other callers: 0x44128, 0x441bc, 0xcc9e4, 0x139d14 (static init),
  0x7fadd4, 0x805558.
- The vt_ctors.tsv second site 0x870918 is a FALSE POSITIVE: the
  `ldr x8, [x21]` / `ldr x8, [x8, #0x18]` there reads a vtable slot of a
  guard-protected singleton, not GOT cell 0x1310018.

## Member notes

- Base part identical to Vt12c7c70 (base init 0x7d34d8 writes
  0x20..0x68, zeroes 0x6c..0xac; see doc/game/Vt12c7c70.md).
- Derived init: s8→0xac; [x1+8] (u32)→0xb8; [x1] 8 bytes→0xb0; s8→0xbc;
  [x1+8] (u32)→0xc8; [x1] 8 bytes→0xc0; global 0x12fb148: [x8+8]→0xd4,
  [x8] 8 bytes→0xcc, [x8+8]→0xe0, [x8] 8 bytes→0xd8; byte 0xe4=0;
  state 0x20=1.
- Getter cluster at 0x7d513c..0x7d5160: read/write [this+0xcc] and
  [this+0xd0]; 0x7d515c reads [this+0xc8].

## Slots (8)

+0x00 0x7c6e1c (shared with base/sibling; fmul [this+0x5c], dispatch
0x2576d8 with 1<<(arg&0x1f)), +0x08 0x7d541c, +0x10 0x7d525c (500B
update), +0x18 0x7d5270, +0x20 0x7d34c4, +0x28 0x7d5440, +0x30 0x7d5164
(the init), +0x38 0x7d5448. All unrecovered FUN_*.

## Construction / init order

1. Root ctor 0x6155bc (vptr 0x12b0058; registry insert → +0x8).
2. Base init 0x7d34d8 (vptr 0x12c7cc0).
3. Derived init 0x7d5164 (vptr 0x12c7de8; params + global copies;
   state=1).
