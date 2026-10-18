# object::Vt12bfd58

PLACEHOLDER name. 26-slot game class (table 0x12bfd58..0x12bfe20) that shares
21 of its slots verbatim with subclass Vt12d6ee0; instances embed a base
sub-object whose vtable is 0x12accb0 (GOT cell 0x130c930).

- Identity: no RTTI, no owned name string in the slots. Name stays PLACEHOLDER.
- vptr convention: GOT cell 0x130ecf0 holds 0x12bfd48 (vt-0x10, RELA addend);
  installed vptr = cell+0x10 = 0x12bfd58 (ctor 0x742048: `ldr [0x130ecf0+0xcf0]`,
  `add #0x10`, `str [this]`).
- Primary table 0x12bfd58: 26 slots; no offset-to-top/typeinfo words precede it
  (0x12bfd48/0x12bfd50 have no RELA entries).
- Size: operator new(0x98, align 4) at 0x74379c inside the inlined factory
  0x74378c; deepest store is the halfword at +0x90.

## Member notes

- Base sub-object (base ctor 0x5a0994): +0x00 base vptr 0x12accb0,
  +0x08 = this+0x08 (self pointer), +0x10 = this+0x08, +0x18..+0x2f = 0,
  +0x40 = 0, +0x48 = this+0x48, +0x50 = this+0x48, +0x58 = 0. Base size 0x58.
- Derived: +0x60..+0x7f zeroed (ctor 0x742048 stp xzr,xzr pairs),
  +0x80 = ctor x1 parameter (owner/handle), +0x90 = 0x200 (halfword).
- Slots: slot0 = 0x743b84 (guard-protected singleton getter returning
  [0x130ed00], unusual for slot0 — possibly a `instance()`-style override),
  slot1 = 0x5a09c4 (base-vptr rewrite stub), slot2 = 0x743c14; shared base
  cluster 0x5a09c4/0x5a14f8/0x5a15dc/0x5a1600/0x5a1610/0x5a1664/0x5a16a8/
  0x5a1b2c/0x5a1ba8/0x5a1c38/0x5a22d0/0x5a1ad8/0x5a1d08/0x5a0c28 identical in
  Vt12d6ee0; own overrides 0x743b84/0x743c14/0x742d0c/0x742d48/0x743698/
  0x742c8c/0x742bb8/0x74378c/0x7437ec/0x7438fc/0x7430bc/0x743694 (most
  unrecovered in functions.csv; dtor pair unverified).

## Construction / init order

1. `operator new(0x98, align 4)` at 0x74379c (inlined factory 0x74378c);
   base ctor 0x5a0994 on the raw block (0x7437b4).
2. vptr = cell 0x130ecf0 + 0x10 (0x7437bc..0x7437c8).
3. +0x70..+0x7f = 0, +0x60..+0x6f = 0, +0x80 = x1 (0x7437d4), +0x90 = 0x200.
4. Direct ctor 0x742048 (site 0x742064) performs the same sequence without
   the allocation; both bodies end at +0x91.
