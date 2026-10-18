# object::NexBackEndServices

Identity: RTTI'd `nn::nex::BackEndServices` (typeinfo 0x12e7480). Six-slot vtable; row
label 0x12e6b70 is the typeinfo slot, installed vptr 0x12e6b78 (GOT cell 0x1314bd0 holds
vptr-0x10). Size lower bound 0x1b4: never heap-allocated standalone - the only ctor call
(0xa3ecdc) is the base-subobject step of the RendezVous ctor 0xa42e30, whose object is
`operator new(0x270)` exact (0x916624/0x9169a4); RendezVous overwrites the vptr with
0x12e6f58 (cell 0x1314d40) after the base ctor and continues at this+0x1e0.

## Member notes

- [this+0x20..0x77] embedded `nn::nex::CallContext` member (0x58): ctor installs
  RefCountedObject vptr 0x128c798 (cell 0x130b618) then CallContext vptr 0x128cc20
  (cell 0x130b740); atomic 1 (stlr) at member+0x8; waiter list self-ref at member+0x20
  ([0x40]=[0x48]=this+0x40). Same layout as ProtocolCallContext's own head.
- [this+0x78] member (0x18 bytes) inited by 0x5788e0(this+0x78, sp+0xc) with timeout
  word 0x80010000 (same helper as ProtocolCallContext's +0x58 member).
- [this+0xb8] = 30000 (default timeout ms); [this+0xc0] backend pointer zeroed by ctor,
  read (and null-checked) by slots 4/5.
- [this+0x130] flag = 1; [this+0x138] member inited by 0x9f5754; [this+0x1ac] member
  inited by 0xa2a008.
- Slots: D1 0xa359b8 (2176B merged ctor/dtor, re-installs vptr at entry; reads [0xc0]);
  D0 0xa35f18 (mid-entry of FUN_7100a35dc4, whose prologue operates on global
  [0x130b760] - behavior unverified). Slot 3 = 0xa369b0 (tail 0xa2b7cc when [0xd0]
  non-null; note the preceding 22B stub 0xa369a0 reads [this+0xd0] - a +0xd0 field is
  referenced, so the lower bound likely extends past 0xd8). Slot 4 = 0xa376ac (mid-entry
  of FUN_7100a375f4; reads [0xc0]/[0xd0]). Slot 5 = 0xa37780 (mid-entry of the same
  function).

## Construction / init order

- Base ctor 0xa35698 (called from RendezVous ctor via 0xa3eccc): [0x10]=0 -> [0x18]=0 ->
  BackEndServices vptr 0x12e6b78 -> CallContext member base-init + atomic at +0x28 ->
  member zeros [0x2c]/[0x30]/[0x38]/[0x50]/[0x60]/[0x70] -> member vptr swap to
  0x128cc20 -> waiter list self-ref +0x40 -> 0x5788e0(this+0x78, ...) -> zeros
  [0x90..0xb0] -> [0xb8]=30000 -> [0xc0]=0 -> [0x118]=0 -> zeros [0x120..0x12f] ->
  [0x130]=1 -> 0x9f5754(this+0x138) -> 0xa2a008(this+0x1ac).
