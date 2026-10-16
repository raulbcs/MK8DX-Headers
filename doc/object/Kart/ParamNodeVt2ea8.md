# ParamNodeVt2ea8

 ParamNodeVt2ea8 — address-anchored name (vptr 0x12b2ea8, cell 0x130d9f0, n=23, site 0x606ad8, ctor 0x606ab0).
 Node class of the 0x647f40 hook-band cluster (shared trivial band
 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
 [this+0x1c]).
 Vtable slot facts :
 - Slots 0 (0x10) / 1 (0x18), complete/deleting destructor: free self+0x1f0
   (operator delete) and clear 0x1f0/0x1e8; install the static vptr from
   cell 0x710130d9f0 (+0x10) with its +0xd8 secondary into self+0x30; reset
   the six member sub-vptrs (0x110, 0x138, 0x160, 0x188, 0x1a8, 0x1c8) to
   [0x710130d918]+0x10; call base cleanup 0x71006472c8. Slot 1 additionally
   tail-calls operator delete(self). true function sizes 0x6c/0x78 bytes
   (gap-split artifacts).
   [paramNodeVt2ea8CompleteDtorSlot0_710064e480,
    paramNodeVt2ea8DeletingDtorSlot1_710064e560]

## Naming and additional notes

 Naming: no ctor strings.

## Construction / init order

- ParamNodeVt2ea8 — address-anchored name (vptr 0x12b2ea8, cell 0x130d9f0, n=23, site 0x606ad8, ctor 0x606ab0). Node class of the 0x647f40 hook-band cluster (shared trivial band 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs [this+0x1c]). Vtable slot facts : - Slots 0 (0x10) / 1 (0x18), complete/deleting destructor: free self+0x1f0 (operator delete) and clear 0x1f0/0x1e8; install the static vptr from cell 0x710130d9f0 (+0x10) with its +0xd8 secondary into self+0x30; reset the six member sub-vptrs (0x110, 0x138, 0x160, 0x188, 0x1a8, 0x1c8) to [0x710130d918]+0x10; call base cleanup 0x71006472c8. Slot 1 additionally tail-calls operator delete(self). true function sizes 0x6c/0x78 bytes (gap-split artifacts). [paramNodeVt2ea8CompleteDtorSlot0_710064e480, paramNodeVt2ea8DeletingDtorSlot1_710064e560] Naming: no ctor strings.
