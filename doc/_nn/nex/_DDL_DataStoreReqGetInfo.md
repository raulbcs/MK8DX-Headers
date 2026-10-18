# nn::nex::_DDL_DataStoreReqGetInfo

RTTI-confirmed (typeinfo object 0x12f86e0, captured mangled name
"..24_DDL_DataStoreReqGetInfoE"; full nesting unverified — header follows the
`nn::nex` `_DDL_AuthenticationInfo` precedent). vptr 0x12f85d8, n=24. Member
of the Vt12f7070 slot family: slots 2-23 identical to 0x12f7070 and to
_DDL_DataStoreCompletePostParamV1 (0x12f89f0); only the dtor pair and the
slot21/22 overrides differ.

- vptr convention: GOT cell 0x1315ed0 holds 0x12f85c8 (vt-0x10); installed
  vptr = cell+0x10 = **0x12f85d8**. A second cell 0x1315f00 holds 0x12f8698 →
  vptr 0x12f86a8 of a separate 3-slot element class (slots 0xb4ba2c/0xb44060/
  0xb42f60; 0x20-byte elements batch-constructed in FUN_7100b45e60-region
  code) — not a secondary base of this class.
- Size: operator new(0x90) at the virtual-new slot22 body 0xb440a8
  (0xb440b4); deepest stores reach +0x88.
- Slots (from 0x12f85d8): slot0 = shared D1 0xa3045c, slot1 = D0 0xb44084
  (D1 + operator delete), slot2 0xa30318, slots 3-20 shared stubs
  0xa30324/0xa30384/0x591864/0x591868/0x591874/0xa2bd80/0x591880/0xa2bdb4/
  0x591888/0x5901e8/0x5902dc/0x591890/0x591898/0xa30388/0xa30390/0xa30394/
  0xa30398/0xa303a0, slot21 = 0xb43588, slot22 = virtual-new 0xb440a8,
  slot23 = 0xa287c0.

## Construction / init order

1. Ctor 0xb4308c(this, u32 param): base ctor 0xa27e78 (SafeString
   "b::AllowParticipating", field zeroing +0x48/+0x50..+0x80, param → +0x60,
   base vptr, +0x88 = 0).
2. Derived vptr = cell 0x1315ed0 + 0x10 (0xb430b0..0xb430bc).
3. If (param & 0xffff) != 0: call 0xa28d3c(this, param) (0xb430c4).
4. Virtual slot22 call and manager tail, mirroring Vt12f7070 ctor 0xb33d54.
