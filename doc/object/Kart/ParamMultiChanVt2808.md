# ParamMultiChanVt2808

 ParamMultiChanVt2808 — address-anchored name (vptr 0x12b2808). Multi-channel
 class of the 0x647f40 hook-band cluster: channel-pair members
 (ctor 0x7100662f30/0x7100662f70) at 0x110, 0x130, 0x150, 0x170, 0x198,
 constructed in place at 0x64c994. EXTENT APPROXIMATE: last channel

## Vtable and extent facts

 vtable facts (paramMultiChan2808InitVt_710064cbe0,
 multiChanVt2808DeletingDtorSlot1_710064cc1c,
 multiChanVt2808IsStaticMatchSlot9_710064cc78,
 multiChanVt2808StaticInstanceSlot10_710064cd44,
 multiChanSlot14_tailCompute_710064cbc4,
 multiChanGetGlobalShort_710064cda0):
   slot 0 (0x10): vtable-init ctor stub — sets self+0x0 / self+0x30 from
     cell 0x710130d9b0 (+0x10 / +0xd8), fans the cell 0x710130d918 (+0x10)
     vptr into self+0x110/0x130/0x150/0x170/0x198, then tail-calls the
     base ctor envObjNameCompleteDtorSlot0_71006472c8 (ParamNodeEnvObjName
     slot 0).
   slot 1 (0x18): deleting dtor — same vptr/sub-vptr reset, base cleanup
     0x71006472c8, then operator delete(this).
   slot 9 (0x58): static-singleton match — guard-initialises two singletons
     (guard 0x7101307cc8 → cell 0x7101307cd0 = [0x71012fd3d0]+0x10;
     guard 0x71012fd3e0 → cell 0x71012fd3e8 = [0x71012fade0]+0x10) and
     returns whether `other` equals the second.
   slot 10 (0x60): guard-protected static accessor — guard 0x71307cc8,
     static slot 0x71307cd0 = [0x712fd3d0]+0x10 (a default
     vtable-holder instance); returns the slot.
   slot 14 (0x80): loads floats at self+0x128 / self+0x148 into s0/s1 and
     tail-calls 0x71006479e0 (x3 = self+0x1b0, x4 = self+0x188).
   slot 22 (0xc0): loads the global config pointer at 0x7101307cc0,
     dereferences it, returns the signed 16-bit value at offset 0.

## Naming and additional notes

 Naming: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash, not statically resolvable.

## Construction / init order

- ParamMultiChanVt2808 — address-anchored name (vptr 0x12b2808). Multi-channel class of the 0x647f40 hook-band cluster: channel-pair members (ctor 0x7100662f30/0x7100662f70) at 0x110, 0x130, 0x150, 0x170, 0x198, constructed in place at 0x64c994. EXTENT APPROXIMATE: last channel vtable facts (paramMultiChan2808InitVt_710064cbe0, multiChanVt2808DeletingDtorSlot1_710064cc1c, multiChanVt2808IsStaticMatchSlot9_710064cc78, multiChanVt2808StaticInstanceSlot10_710064cd44, multiChanSlot14_tailCompute_710064cbc4, multiChanGetGlobalShort_710064cda0): slot 0 (0x10): vtable-init ctor stub — sets self+0x0 / self+0x30 from cell 0x710130d9b0 (+0x10 / +0xd8), fans the cell 0x710130d918 (+0x10) vptr into self+0x110/0x130/0x150/0x170/0x198, then tail-calls the base ctor envObjNameCompleteDtorSlot0_71006472c8 (ParamNodeEnvObjName slot 0). slot 1 (0x18): deleting dtor — same vptr/sub-vptr reset, base cleanup 0x71006472c8, then operator delete(this). slot 9 (0x58): static-singleton match — guard-initialises two singletons (guard 0x7101307cc8 → cell 0x7101307cd0 = [0x71012fd3d0]+0x10; guard 0x71012fd3e0 → cell 0x71012fd3e8 = [0x71012fade0]+0x10) and returns whether `other` equals the second. slot 10 (0x60): guard-protected static accessor — guard 0x71307cc8, static slot 0x71307cd0 = [0x712fd3d0]+0x10 (a default vtable-holder instance); returns the slot. slot 14 (0x80): loads floats at self+0x128 / self+0x148 into s0/s1 and tail-calls 0x71006479e0 (x3 = self+0x1b0, x4 = self+0x188). slot 22 (0xc0): loads the global config pointer at 0x7101307cc0, dereferences it, returns the signed 16-bit value at offset 0. Naming: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash, not statically resolvable.
