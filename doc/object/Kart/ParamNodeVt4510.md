# ParamNodeVt4510

 ParamNodeVt4510 — address-anchored name (vptr 0x12f4510, cell 0x13154d8, n=22, site 0xaef788, ctor 0xaef760).
 Node class of the 0x647f40 hook-band cluster (shared trivial band
 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
 [this+0x1c]).
 Vtable slot facts :
 - Slots 0 (0x10) / 1 (0x18), deleting destructors: install the static
   vptr from cell 0x7101514d8 (+0x10) with its +0x148 secondary into
   self+0x30; free self+0x118 via operator delete (zeroing it and word
   self+0x110); call FUN_7100af9c28(self+0x170); base complete destructor
   envObjNameCompleteDtorSlot0_71006472c8, then operator delete(self).
   true function sizes 0x54/0x58 bytes (gap-split artifacts).
   [vt4510DeletingDtorSlot0_7100aef8f4,
    vt4510DeletingDtorSlot1_7100aef9a0]
 - Slot 10 (0x60): guard-initialised static vtable getter. Stores
   descriptor cell 0x71012fade0 (+0x10) into cache cell 0x710130e318
   (guard byte 0x710130e310) on first call. true function size 0x5c bytes.
   [vt4510VtGetterSlot10_7100af4684]

## Naming and additional notes

 Naming: no ctor strings.

## Construction / init order

- ParamNodeVt4510 — address-anchored name (vptr 0x12f4510, cell 0x13154d8, n=22, site 0xaef788, ctor 0xaef760). Node class of the 0x647f40 hook-band cluster (shared trivial band 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs [this+0x1c]). Vtable slot facts : - Slots 0 (0x10) / 1 (0x18), deleting destructors: install the static vptr from cell 0x7101514d8 (+0x10) with its +0x148 secondary into self+0x30; free self+0x118 via operator delete (zeroing it and word self+0x110); call FUN_7100af9c28(self+0x170); base complete destructor envObjNameCompleteDtorSlot0_71006472c8, then operator delete(self). true function sizes 0x54/0x58 bytes (gap-split artifacts). [vt4510DeletingDtorSlot0_7100aef8f4, vt4510DeletingDtorSlot1_7100aef9a0] - Slot 10 (0x60): guard-initialised static vtable getter. Stores descriptor cell 0x71012fade0 (+0x10) into cache cell 0x710130e318 (guard byte 0x710130e310) on first call. true function size 0x5c bytes. [vt4510VtGetterSlot10_7100af4684] Naming: no ctor strings.
