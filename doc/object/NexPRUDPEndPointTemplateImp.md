# object::NexPRUDPEndPointTemplateImp

Identity: RTTI'd `nn::nex::PRUDPEndPointTemplateImp` (typeinfo 0x12e46e0). Six-slot
vtable; row label 0x12e3b60 is the typeinfo slot, installed vptr 0x12e3b68 (GOT cell
0x1314710 holds vptr-0x10). Size 0xd0 exact (operator new w0=0xd0 at 0xa03880 in factory
FUN_7100a032b0; the sibling branch allocates 0x18 for PRUDPEndPointTemplatePRUDPLiteImp).

## Member notes

- [this+0x8] = endpoint id (ctor arg w22 of the factory), stored before the vptr.
- [this+0x10] embedded `nn::nex::RC4PacketEncDec` member (vptr 0x12e3240 from cell
  0x1314560, member ctor 0x9f3574 called on this+0x10 at 0xa038a4): member ctor zeroes
  [0x28], allocates an 8-byte node (0x576368) and builds a self-referential list trio at
  member+0x8/+0x10/+0x18.
- Slots: D1 0xa14248 and D0 0xa1425c (both inside the stub cluster after FUN_7100a141a0;
  both restore vptr 0x12e3b68 and tail into the RC4 member dtor continuation 0x9f36a0;
  D0 additionally operator-deletes). Slot 3 = 0xa14290 (1042B: zeroes an out-param, then a
  loop over global settings at 0x130b528 / endpoint tables - packet dispatch entry).
  Slot 4 = 0xa143fc (mid-entry of FUN_7100a14290; bit-packs a protocol header word:
  0x01000000 base, flags from w1/w2). Slot 5 = 0xa193f4 stub returning this+0x10 (packet
  enc/dec accessor).
- Non-virtual helper FUN_7100a141a0 (0xa141a0) dispatches through the member's vtable
  slot +0x28 and filters results (memcmp against +0x48/+0x58, nibble test on +0x60).
- Unrelated thunk 0xa14240 = `return [this+8]` (id getter used by callers, not a slot).

## Construction / init order

- Factory FUN_7100a032b0 (0xa0387c-0xa038a4): `operator new(0xd0)` -> [this+8]=id ->
  vptr 0x12e3b68 -> RC4PacketEncDec ctor 0x9f3574(this+0x10) -> stored at owner+0x320;
  the owner then calls slot 2 ([vptr+0x10]) with this and two out-params.
