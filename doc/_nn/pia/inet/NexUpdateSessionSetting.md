# NexUpdateSessionSetting (nn::pia::inet::NexUpdateSessionSetting)

- RTTI-named: word at 0x12da3e0 is the typeinfo pointer -> embedded pair at
  0x12da440 = {0x10, name 0x12f7ea10 "N2nn3pia4inet23NexUpdateSessionSettingE"}.
- GOT cell 0x13129b0 holds 0x12da3d8 = vptr-0x10; installed vptr = 0x12da3e8,
  10 function slots at vptr+0x00..+0x48.
- Size 0x630 stride-proven: enclosing C1 FUN_7100912cc0 constructs identical
  members at enclosing+0x2b8 and enclosing+0x8e8 (0x916504-0x916510), both via
  this class's C1.

## Identity

pia inet Nex session setting record. Two instances live side by side inside a
larger session/matchmake object (also holding an InetCreateMeshJob-family
member at +0xf38, C1 0x922af4).

## Member notes

- +0x0c/+0x0e = 0xffff (C1 0x935424-0x93542c, after base C1 0x99f488).
- Two 43-entry arrays at +0x25c and +0x2fc (stride 3, u16+u8), zeroed by C1
  loops (0x935478-0x935488, 0x9354c0-0x9354d0); each preceded by self-pointer
  (+0x248/+0x2e8) and a 0x80 count/cap word (+0x250/+0x2f0).
- Secondary vptrs: +0x240 and +0x2e0 = cell 0x1312850 + 0x10; +0x380 = cell
  0x1312968 + 0x10; +0x3a8 = cell 0x1312848 + 0x10; +0x3d8/+0x418/+0x458/
  +0x4c8 = cell 0x1312858 + 0x10 (0x9354f8-0x9355b8). Semantics unverified.

## Construction / init order

- C1 = FUN_7100935408: base C1 0x99f488 (0x935420); 0xffff halves (0x935428);
  vptr install 0x935448; +0x10/+0x14 zero; first array block (0x935454-
  0x93548c); second array block (0x935498-0x9354d8); remaining vptrs and
  zero words through 0x9355xx.
- Allocation sites: in-place only (as enclosing-object members).

## Slots (10, at vptr 0x12da3e8..+0x48)

0x935894, 0x9358a8, 0x935f2c (244B, unrecovered), 0x935fb4, 0x936018,
0x936028, 0x99f4a8, 0x99f4b0, 0x99f4c8 (base-family slots), 0x9358bc. Slot
bodies unrecovered in functions.csv; dtor pair not separately identified.
Nearby trivial getters 0x9353d4-0x9353f0 (u32 [this+0x978]; u8
[this+0x97d..0x97f]) belong to the enclosing object, not this class.
