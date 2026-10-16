# ParamContainerVtb448

 ParamContainerVtb448 — address-anchored name (vptr 0x12bb448, GOT cell
 0x130e470). Large container of the 0x647f40 hook-band cluster
 (param-cache super-family ring): n=27 slots, allocation
 0x1048 at site 0x6df16c. Shares the trivial hook band
 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare; compare 0x7100647f6c (paramNodeSharedTypeIdEquals) is slot 0x50 shared by 61 ParamNode vtables).
 Own fields mapped from the inlined construction at the quoted site
 (vptr stores at +0x0/+0x30, tail count block); interior array region unproven.
 Vtable slot facts :
 - Slot 14 (0x80): dispatches to children. Walks the child list backwards
   (head +0x268, end sentinel +0x260, node stride *(int*)(self+0x274), node
   +0x8 next); for each child with a non-null +0x18 handle: obj =
   [handle+0x10]; ORs bit 0x80 into obj+0xe28 halfword; calls the object's
   vtable method at 0xb8 (slot 23) with the original (x1, w4) arguments.
   true function size 0x98 bytes. [containerDispatchSlot14_71006fbc3c]

## Naming and additional notes

 Naming: container shell of the 0x647f40 hook-band cluster; no ctor strings and no per-class static identity (runtime param id only).

## Construction / init order

- ParamContainerVtb448 — address-anchored name (vptr 0x12bb448, GOT cell 0x130e470). Large container of the 0x647f40 hook-band cluster (param-cache super-family ring): n=27 slots, allocation 0x1048 at site 0x6df16c. Shares the trivial hook band 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare; compare 0x7100647f6c (paramNodeSharedTypeIdEquals) is slot 0x50 shared by 61 ParamNode vtables). Own fields mapped from the inlined construction at the quoted site (vptr stores at +0x0/+0x30, tail count block); interior array region unproven. Vtable slot facts : - Slot 14 (0x80): dispatches to children. Walks the child list backwards (head +0x268, end sentinel +0x260, node stride *(int*)(self+0x274), node +0x8 next); for each child with a non-null +0x18 handle: obj = [handle+0x10]; ORs bit 0x80 into obj+0xe28 halfword; calls the object's vtable method at 0xb8 (slot 23) with the original (x1, w4) arguments. true function size 0x98 bytes. [containerDispatchSlot14_71006fbc3c] Naming: container shell of the 0x647f40 hook-band cluster; no ctor strings and no per-class static identity (runtime param id only).
