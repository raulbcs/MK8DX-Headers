# object::NexRoutingStream

Identity: RTTI'd `nn::nex::RoutingStream` (typeinfo 0x12e47e0). Six-slot vtable; row
label 0x12e3c88 is the typeinfo slot, installed vptr 0x12e3c90 (GOT cell 0x13147d8 holds
vptr-0x10). Size 0xd0 exact (operator new w0=0xd0 at 0x9fc63c; result stored at owner
+0x450). Derives from `nn::nex::RefCountedObject` (base ctor 0x9e4484 installs vptr
0x12e3410 and sets [this+8] = initial refcount 8).

## Member notes

- [this+0x10] list-head trio ([0x10]=this+0x18, [0x18]=[0x20]=0); torn down last by D1
  (0xa1abc4(this+0x10, [this+0x18])).
- [this+0x28] second list-head trio ([0x28]=this+0x30, [0x30]=[0x38]=0); torn down by D1
  (0xa1ac24(this+0x28, [this+0x30])).
- [this+0x48] member inited by 0x574a70(this+0x48, 1, 1); torn down by D1
  (0x576340(this+0x48)).
- [this+0x98]/[this+0xa0] member pointers; D1 first tears down 0xa1b1f4(this+0x98,
  [this+0xa0]) after restoring vptr 0x12e3c90.
- Slots: D1 0xa19404 (530B dtor) and D0 0xa19458 (deleting variant, both standalone
  functions). Slot 3 = 0xa14ecc (6248B, the largest - stream routing/relay worker).
  Slot 4 = 0xa15a38 (264B). Slot 5 = 0xa191c4 stub `return 0`.
- The owner (same object that holds the RelayStream at +0x458) constructs this at
  +0x450 in the function around 0x9fc63c, right before the outer factory 0x9facb4.

## Construction / init order

- Owner factory ~0x9fc63c: `operator new(0xd0)` -> ctor 0xa14df8: RefCountedObject ctor
  0x9e4484(this, 8) -> vptr 0x12e3c90 -> list trios at +0x10 and +0x28 ->
  0x574a70(this+0x48, 1, 1) -> tail reads global settings gate 0x130b528 and the NPL
  table at 0x1312528 (same +0x2c0/0x148-stride pattern as RelayStream).
