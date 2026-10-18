# recorder::ModelMatrixChannel (vtable 0x12d1c70)

## Identity

0x2e0-byte child channel of recorder::ModelChannelGroup (0x12d1b48). 35
slots, no RTTI. Single construction site: 0x88b9c0..0x88ba14 inside the
ModelChannelGroup ctor's +0x280 branch — `operator new(0x2e0)` (0x88b9c0/
0x88b9e4), folded ctor 0x7b100c(this, stackParam) (0x88b9f0), then primary
vptr override at +0x00 from GOT cell 0x13113c8 (cell holds 0x12d1c60 =
vptr-0x10; installed vptr = cell + 0x10 = 0x12d1c70, store 0x88ba10), then
registered nameless via recorderAddChannel_71007ac0cc(group, ch, 0) (0x88ba14).

Note: 0x7b100c is an ICF-folded ctor shared by several recorder classes (11
call sites, e.g. 0x1e6a0, 0x2e884, 0x1b2d90, 0x305c7c/b8/f4, 0x3adabc,
0x3ae264, 0x3c3ef4, 0x7ef460); it installs base row vptr *(GOT cell
0x130fb08) + 0x10 = 0x12c4788 before the derived override. doc/recorder/
MatrixChannel.md describes 0x7b100c as a "setup" routine that allocates
channels; per this site it is a ctor (the allocation happens in the caller).

All slot addresses are VMAs (add 0x7100000000); every slot is absent from
functions.csv (unrecovered).

## Member notes

- +0x278/+0x280/+0x288/+0x290: four pointers copied from the stack param
  ([x1+0x00..0x18]; built by the group ctor from [group+0x280], group+0x288/
  +0x28c and byte +0x290) — ctor stores at 0x7b1044..0x7b1060.
- +0x298..0x2d0: zeroed by the folded ctor (0x7b107c/0x7b1080/0x7b1064..);
  +0x298 also receives -1 (w8 = -1, 0x7b1084) and +0x2a0..+0x2ac receive three
  words from the serial counter object at 0x12fb148 (0x7b1088..0x7b10ac).
- +0x2d8: owning ModelChannelGroup pointer (0x88b9fc).
- +0x88/+0x98 slots 0x88ba74/0x88ba78 are shared with the group row's thunk
  cluster; slot 10 (0x7b1438) differs from the 0x7abca8 used by the sibling
  rows — unverified reason.

## Construction / init order

1. Group ctor builds the stack param (sp..sp+0x1b) from its +0x280/+0x288/
   +0x28c fields and byte +0x290 (0x88b9b4..0x88b9e0).
2. `ch = operator new(0x2e0)` (0x88b9c0/0x88b9e4).
3. `FUN_71007b100c(ch, param)` — Binder head, param copies, zeroed tail,
   counter init, base vptr 0x12c4788 (0x88b9f0).
4. vptr override to 0x12d1c70 (0x88b9f8/0x88ba10); parent stored at +0x2d8
   (0x88b9fc).
5. `recorderAddChannel_71007ac0cc(group, ch, 0)` — nameless registration
   (0x88ba14).
