# nn::nex::PseudoGlobalVariableU16

RTTI-confirmed: typeinfo 0x12e4f00 -> mangled
`N2nn3nex20PseudoGlobalVariableItEE` =
nn::nex::PseudoGlobalVariable<unsigned short>. Growable u16 id-list
object; no allocation of the object itself was found - instances are
initialized in place inside a global table by FUN_71009f7434.

- Identity: slot2 doubles the array at +0x10 (alloc 2 x count through
  realloc-style helper 0x576368, copy loop, store back).
- Vtable: vptr = 0x12e4eb8. GOT cell 0x1314578 holds 0x12e4ea8 =
  vptr-0x10; every site does `ldr cell; add #0x10; str [this]`. Row
  layout: [0x12e4ea8] = 0 (offset-to-top), [0x12e4eb0] typeinfo slot.
- Sites: 0x9f46a0 (slot0/D1 body), 0x9f7598 (in-place init inside
  FUN_71009f7434), 0xa1ba8c (slot1/D0 body).

## Member notes

- Slots (8): +0x00 D1 0x9f4690 (installs vptr, runs virtual +0x18, then
  delete wrapper 0x58c5b8), +0x08 D0 0xa1ba7c (D1 body then
  `operator delete` 0x573f48), +0x10 0xa1bad4 (116 B - array grow),
  +0x18..+0x38 slots 3-7 all 0xa1bb48 (188 B, shared stub).
- Size: lower bound 0x20 (max init store +0x1b); array allocation is
  external (realloc), so the full object size is unproven.

## Construction / init order

1. In-place inside FUN_71009f7434 (global table init): [this+0x10] = 0,
   halfwords 0x23f3 -> +0x18 and +0x1a, vptr installed at +0x00.
2. Helper call 0x58c448(global cell 0x130b940, this) then virtual slot2
   (+0x10) - initial array allocation.
