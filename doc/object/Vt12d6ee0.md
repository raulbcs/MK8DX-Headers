# object::Vt12d6ee0

PLACEHOLDER name. 26-slot subclass of Vt12bfd58 (21 of 26 slots inherited
verbatim); table 0x12d6ee0..0x12d6fa8.

- Identity: no RTTI, no owned name string. Name stays PLACEHOLDER.
- vptr convention: GOT cell 0x1312088 holds 0x12d6ed0 (vt-0x10); installed
  vptr = cell+0x10 = 0x12d6ee0.
- Size: operator new(0x98, align 8) at 0x8f11c4 — same 0x98 footprint as the
  base class (subclass adds no fields; overrides only behavior).

## Member notes

- Layout identical to Vt12bfd58 (base sub-object at +0x00, derived state
  +0x60..+0x91); ctor 0x8f1128 runs base ctor 0x742048 then overwrites +0x00
  with 0x12d6ee0 (0x8f113c..0x8f1148).
- Overrides: slot0 = 0x8f1230 (D1, 0x208 bytes), slot2 = 0x8f1300,
  slot18 = 0x8f1158 (factory override: allocates 0x98, runs base ctor
  0x742048 on the block, then tail 0x742d0c — spawns embedded Vt12bfd58
  instances for its owner at [this+0x80]), slot23 = 0x8f1324.
- Inherited cluster: slots 1/3..17/19..22/24/25 shared verbatim with
  Vt12bfd58 (0x5a09c4..0x5a1d08, 0x742d0c, 0x5a0c28, 0x742d48, 0x742c8c,
  0x742bb8, 0x74378c, 0x7437ec, 0x7430bc, 0x743694).

## Construction / init order

1. `operator new(0x98, align 8)` at 0x8f11c4 inside 0x8f1158's allocation
   path (owner object holds the instance at its +0x88 slot chain).
2. base ctor 0x742048 (0x8f11d8), then vptr overwrite to 0x12d6ee0
   (0x8f11dc..0x8f11ec).
3. +0x88 = owner (0x8f11e4); remaining init inherited from 0x742048.
