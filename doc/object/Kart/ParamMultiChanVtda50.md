# ParamMultiChanVtda50

 ParamMultiChanVtda50 — address-anchored name (vptr 0x12bda50). Multi-channel
 class of the 0x647f40 hook-band cluster: channel-pair members
 (ctor 0x7100662f30/0x7100662f70) at 0x2c8, 0x2f0, 0x318, 0x340, 0x360,
 constructed in place at 0x72cd5c. EXTENT APPROXIMATE: last channel

## Vtable and extent facts

 vtable facts (multiChanDa50BindParamsSlot30_710072da50,
 paramMultiChanVtda50StaticInstanceSlot10_710072e2ec):
   slot 10 (0x60): guard-protected static singleton getter — guard cell
     0x710130e1a0, instance cell 0x710130e1a8 initialised to
     [0x710130e180]+0x10; returns the instance pointer.
   slot 30 (0x100): (self, void* src) — binds src into member parameters:
     for each offset in {0x4f0, 0x530, 0x2c8, 0x2f0, 0x318, 0x460, 0x488,
     0x510, 0x360, 0x380} runs FUN_71006630bc(self+off, &scratch) then
     FUN_7100664e94(self+off, src, &scratch); offsets 0x4b0 and 0x4d0 bind
     without the guard call, passing a stack key pair (cell
     0x12fae28+0x10, string 0xeffd2b). Then switches on *(s32*)(self+0x358):
     0 -> bind +0x3a0 with (0x130d918+0x10, 0xf04680) and +0x3c0 with
     (0x130d918+0x10, 0xf03162); 1 -> bind +0x3e0 (0x12fae28+0x10,
     0xf03162), +0x400 (0x12fae28+0x10, 0xf06dd5), +0x440 (0x12fae28+0x10,
     0xf03162), +0x420 (0x12fae28+0x10, 0xf06dd5).

## Naming and additional notes

 Naming: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash, not statically resolvable.

## Construction / init order

- ParamMultiChanVtda50 — address-anchored name (vptr 0x12bda50). Multi-channel class of the 0x647f40 hook-band cluster: channel-pair members (ctor 0x7100662f30/0x7100662f70) at 0x2c8, 0x2f0, 0x318, 0x340, 0x360, constructed in place at 0x72cd5c. EXTENT APPROXIMATE: last channel vtable facts (multiChanDa50BindParamsSlot30_710072da50, paramMultiChanVtda50StaticInstanceSlot10_710072e2ec): slot 10 (0x60): guard-protected static singleton getter — guard cell 0x710130e1a0, instance cell 0x710130e1a8 initialised to [0x710130e180]+0x10; returns the instance pointer. slot 30 (0x100): (self, void* src) — binds src into member parameters: for each offset in {0x4f0, 0x530, 0x2c8, 0x2f0, 0x318, 0x460, 0x488, 0x510, 0x360, 0x380} runs FUN_71006630bc(self+off, &scratch) then FUN_7100664e94(self+off, src, &scratch); offsets 0x4b0 and 0x4d0 bind without the guard call, passing a stack key pair (cell 0x12fae28+0x10, string 0xeffd2b). Then switches on *(s32*)(self+0x358): 0 -> bind +0x3a0 with (0x130d918+0x10, 0xf04680) and +0x3c0 with (0x130d918+0x10, 0xf03162); 1 -> bind +0x3e0 (0x12fae28+0x10, 0xf03162), +0x400 (0x12fae28+0x10, 0xf06dd5), +0x440 (0x12fae28+0x10, 0xf03162), +0x420 (0x12fae28+0x10, 0xf06dd5). Naming: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash, not statically resolvable.
