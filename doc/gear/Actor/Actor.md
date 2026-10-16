# gear::Actor

Inherits sead::hostio::Node and SeadGameDeallocator.

The constructor (0x71000001b4) calls a base ctor with its own vtable before writing Actor's, and the vtable at .data:0x11ad018 is followed by a second sub-vtable at 0x11ad098 — multiple inheritance, matching the sead hostio base.

sead::hostio::Node resolves to the MK8DX fork override (sead/hostio/seadHostIONode.hpp — hostio disabled, size 0x38); the open-ead Node does not match the 4.0.0 binary. Node supplies the fields at 0x08..0x30.

## Construction / init order

1. Ctor entry 0x71000001b4.
2. Base ctor (sead::hostio::Node) called with its own vtable first.
3. Actor vtable written: .data:0x11ad018, followed by second sub-vtable at 0x11ad098 (multiple inheritance).
