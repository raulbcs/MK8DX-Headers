# object::NexProtocolCallContext

Identity: RTTI'd `nn::nex::ProtocolCallContext` (typeinfo 0x12e62a0). Six-slot vtable;
row label 0x12e5de0 is the typeinfo slot, installed vptr 0x12e5de8 (GOT cell 0x13149c0
holds vptr-0x10). Size lower bound 0xc0 (last field store [0xb8]); no heap allocation
observed - the ctor FUN_7100a2bf88 is sret-style and every observed caller constructs it
into a stack slot (e.g. 0x8351e8 `add x0, sp, #0x20`). Class chain:
RefCountedObject -> CallContext -> ProtocolCallContext (ctor installs vptr 0x128c798,
then 0x128cc20, then 0x12e5de8). Consistent with the existing typed header
include/_nn/nex/ProtocolCallContext.hpp (Credentials* at 0xB8, base CallContext body).

## Member notes

- [this+0x8] atomic flag stored with release semantics (stlr 1).
- [this+0x20]/[this+0x28] waiter list head, both set to this+0x20.
- [this+0x58] member (0x18 bytes) inited by 0x5788e0(this+0x58, sp+0xc) where [sp+0xc] =
  0x80010000 (timeout/epoch word); size unverified.
- [this+0xb8] = Credentials* (ctor arg x1); the ctor then LDAR/LDAXR-checks arg+8
  (credentials refcount/state) when the arg is non-null.
- Slots: D1 0xa2c1e8 is a merged ctor/dtor function (1554B) that re-installs vptr
  0x12e5de8 at entry; D0 0xa2c3b0 and slot 4 0xa2c3d4 are mid-entries of the same
  function. Slot 3 = 0x587530 (32B). Slot 5 = 0x59179c (mid-entry of FUN_7100591764,
  96B).

## Construction / init order

- Ctor 0xa2bf88(x0=storage, x1=Credentials*): RefCountedObject vptr -> atomic flag ->
  [0xc]=0 -> zeros [0x10]/[0x18]/[0x30..0x50] -> CallContext vptr -> waiter list
  self-ref at +0x20 -> 0x5788e0(this+0x58, ...) -> zeros [0x70]/[0x78]/[0x80..0xb0] ->
  ProtocolCallContext vptr 0x12e5de8 -> [0xb8]=Credentials*.
