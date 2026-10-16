# ParamNodeEnvObjName

 ParamNodeEnvObjName — named from ctor string evidence: ctor params env 'name'/object-name JP + 'enable' display block (0xef8f59-0xef8f86) (was address-anchored ParamNodeVt1fc0) (vptr 0x12b1fc0, cell 0x130d900, n=22, site 0x646de0, ctor 0x646dac).
 Node class of the 0x647f40 hook-band cluster (shared trivial band
 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
 [this+0x1c]).
 Vtable slot facts :
 - Slots 0 (0x10) / 1 (0x18), complete/deleting destructor: install the
   static vptr from cell 0x710130d900 (+0x10) with its +0xd8 secondary
   into self+0x30; reset the member sub-vptrs (0xb8, 0x60, 0x40) to
   [0x710130d918]+0x10; call member cleanup FUN_71006617b8(self). Slot 0
   then restores the derived vptr from cell 0x710130d920 (+0x10) and
   returns self; slot 1 tail-calls operator delete(self).
   true function sizes 0x5c/0x54 bytes (gap-split artifacts).
   [envObjNameCompleteDtorSlot0_71006472c8,
    envObjNameDeletingDtorSlot1_71006473b0]
 - Slot 9 (0x58): is-static-instance test. One-time-guarded initialisation
   of the singleton slot at 0x71012fd03e8 (guard at 0x71012fd03e0) to
   [0x710012fade0]+0x10, then returns whether the second argument equals
   that static instance pointer. true function size 0x6c bytes.
   [paramNodeEnvObjNameIsStaticInstance_7100647f80]
 - Slot 10 (0x60): guard-protected static accessor. Uses the guard object
   loaded from cell 0x712fd3e0; on first init stores cell 0x712fade0
   (+0x10) into the static slot pointed to by cell 0x712fd3e8 (a default
   vtable-holder instance) and returns that slot. true function size 0x58 bytes.
   [envObjNameStaticInstanceSlot10_7100647ff0]

## Naming and additional notes

 Naming: no ctor strings.

## Construction / init order

- ParamNodeEnvObjName — named from ctor string evidence: ctor params env 'name'/object-name JP + 'enable' display block (0xef8f59-0xef8f86) (was address-anchored ParamNodeVt1fc0) (vptr 0x12b1fc0, cell 0x130d900, n=22, site 0x646de0, ctor 0x646dac). Node class of the 0x647f40 hook-band cluster (shared trivial band 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs [this+0x1c]). Vtable slot facts : - Slots 0 (0x10) / 1 (0x18), complete/deleting destructor: install the static vptr from cell 0x710130d900 (+0x10) with its +0xd8 secondary into self+0x30; reset the member sub-vptrs (0xb8, 0x60, 0x40) to [0x710130d918]+0x10; call member cleanup FUN_71006617b8(self). Slot 0 then restores the derived vptr from cell 0x710130d920 (+0x10) and returns self; slot 1 tail-calls operator delete(self). true function sizes 0x5c/0x54 bytes (gap-split artifacts). [envObjNameCompleteDtorSlot0_71006472c8, envObjNameDeletingDtorSlot1_71006473b0] - Slot 9 (0x58): is-static-instance test. One-time-guarded initialisation of the singleton slot at 0x71012fd03e8 (guard at 0x71012fd03e0) to [0x710012fade0]+0x10, then returns whether the second argument equals that static instance pointer. true function size 0x6c bytes. [paramNodeEnvObjNameIsStaticInstance_7100647f80] - Slot 10 (0x60): guard-protected static accessor. Uses the guard object loaded from cell 0x712fd3e0; on first init stores cell 0x712fade0 (+0x10) into the static slot pointed to by cell 0x712fd3e8 (a default vtable-holder instance) and returns that slot. true function size 0x58 bytes. [envObjNameStaticInstanceSlot10_7100647ff0] Naming: no ctor strings.
