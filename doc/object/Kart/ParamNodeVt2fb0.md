# ParamNodeVt2fb0

 ParamNodeVt2fb0 — address-anchored name (vptr 0x12b2fb0, cell 0x130d9f8, n=23, site 0x606b60, ctor 0x606ab0).
 Node class of the 0x647f40 hook-band cluster (shared trivial band
 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
 [this+0x1c]).
 Vtable slot facts :
 - Slots 0 (0x10) / 1 (0x18), complete/deleting destructor: free self+0x268
   (clear 0x268/0x260) and self+0x258 (clear 0x258/0x250) via operator
   delete; install the static vptr from cell 0x710130d9f8 (+0x10) with its
   +0xd8 secondary into self+0x30; reset the member sub-vptrs (0x110,
   0x138, 0x160, 0x180, 0x1a0, 0x1c8, 0x1f0, 0x210, 0x230) to
   [0x710130d918]+0x10; call base cleanup 0x71006472c8. Slot 1
   additionally tail-calls operator delete(self). true function sizes 0x90/0x98
   bytes (gap-split artifacts).
   [paramNodeVt2fb0CompleteDtorSlot0_710064ebc0,
    paramNodeVt2fb0DeletingDtorSlot1_710064ece0]

## Naming and additional notes

 Naming: no ctor strings.

## Construction / init order

- ParamNodeVt2fb0 — address-anchored name (vptr 0x12b2fb0, cell 0x130d9f8, n=23, site 0x606b60, ctor 0x606ab0). Node class of the 0x647f40 hook-band cluster (shared trivial band 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs [this+0x1c]). Vtable slot facts : - Slots 0 (0x10) / 1 (0x18), complete/deleting destructor: free self+0x268 (clear 0x268/0x260) and self+0x258 (clear 0x258/0x250) via operator delete; install the static vptr from cell 0x710130d9f8 (+0x10) with its +0xd8 secondary into self+0x30; reset the member sub-vptrs (0x110, 0x138, 0x160, 0x180, 0x1a0, 0x1c8, 0x1f0, 0x210, 0x230) to [0x710130d918]+0x10; call base cleanup 0x71006472c8. Slot 1 additionally tail-calls operator delete(self). true function sizes 0x90/0x98 bytes (gap-split artifacts). [paramNodeVt2fb0CompleteDtorSlot0_710064ebc0, paramNodeVt2fb0DeletingDtorSlot1_710064ece0] Naming: no ctor strings.
