# object::NexRelayStream

Identity: RTTI'd `nn::nex::RelayStream` (typeinfo 0x12e3fe0). Six-slot vtable; row label
0x12e3650 is the typeinfo slot, installed vptr 0x12e3658 (GOT cell 0x1314670 holds
vptr-0x10). Size 0x60 exact (operator new w0=0x60 at 0x9face8 -> 0x573f04, ctor inlined in
outer factory 0x9facb4). Derives from `nn::nex::RefCountedObject` (base ctor 0x9e4484
installs vptr 0x12e3410 from cell 0x13142d8 and sets [this+8] = initial refcount 11).

## Member notes

- [this+0x0] vptr 0x12e3658, installed last (0x9fad14) after the base ctor.
- [this+0x10] zeroed (0x9fad0c).
- [this+0x20] = this+0x28 with [this+0x28] = [this+0x30] = 0: intrusive list-head trio.
- [this+0x38] = 3*n where n comes from a global table ([0x1312528]+0x2c0, row stride 0x148,
  entry+0xb8; 0x9fad58-0x9fad70).
- [this+0x40] member inited by 0x575b3c; [this+0x48]/[this+0x4c] = -1,-1; [this+0x50] and
  [this+0x58] zeroed.
- The 0x60 object is stored at outer+0x8 by the containing class (vptr 0x12e35e0 via cell
  0x1314668) constructed at 0x9facb4 (owner embeds it at owner+0x8).
- Slots: D1 0xa191f8 (tears down the +0x20 list via 0xa1b1f4(this+0x20, [this+0x28]) then
  restores vptr) and D0 0xa19218 (same + operator delete). Slot 3 = 0x9fc130 (1330B, reads
  args from an x3 object: [0xfc] w, [0x104] h, [0x100] w, [0x138] p - packet/relay build).
  Slot 4 = 0x9fc344 (534B, iterates the +0x20 list against this+0x10). Slot 5 = 0xa191c4
  stub `return 0`.

## Construction / init order

- Outer factory 0x9facb4: `operator new(0x60)` -> RefCountedObject ctor 0x9e4484(this, 11)
  -> [0x10]=0 -> vptr 0x12e3658 -> list trio +0x20/+0x28/+0x30 -> [0x38]=3*n ->
  0x575b3c(this+0x40) -> [0x48]=[0x4c]=-1 -> [0x50]=[0x58]=0 -> store at outer+0x8.
