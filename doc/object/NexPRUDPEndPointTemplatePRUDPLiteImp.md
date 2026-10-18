# object::NexPRUDPEndPointTemplatePRUDPLiteImp

Identity: RTTI'd `nn::nex::PRUDPEndPointTemplatePRUDPLiteImp` (typeinfo 0x12e4740).
Six-slot vtable; row label 0x12e3bf0 is the typeinfo slot, installed vptr 0x12e3bf8 (GOT
cell 0x1314700 holds vptr-0x10). Size 0x18 exact (operator new w0=0x18 at 0xa03848 in
factory FUN_7100a032b0, taken when the settings gate at 0xa0382c selects the lite path).

## Member notes

- [this+0x8] = endpoint id (factory arg w22), stored before the vptr.
- [this+0x10] embedded `nn::nex::DummyPacketEncDec` subobject: vptr 0x12e4bc8 installed
  directly from GOT cell 0x1314708 (holds 0x12e4bb8 = vptr-0x10); no member ctor call.
  Its 4 slots: 0x576b84 / 0xa1aa0c / 0xa1aa10 / 0xa1aa18 (no-op enc/dec family).
- Slots: D1 0xa14640 and D0 0xa14644 are mid-entries of FUN_7100a14588 (402B merged
  dtor; D1 path at +0xb8, D0 adds operator delete). Slot 3 = 0xa14648 (FUN_7100a14648
  start, 374B). Slot 4 = 0xa146d0 (mid-entry of the same function, +0x88). Slot 5 =
  0xa193fc stub returning this+0x10 (packet enc/dec accessor, same as the Imp sibling).
- Shared with the sibling: both slot-5 entries and the factory live in FUN_7100a032b0;
  the PRUDPEndPointTemplateImp branch stores its object at owner+0x320 too.

## Construction / init order

- Factory FUN_7100a032b0 (0xa03844-0xa03878): `operator new(0x18)` -> [this+8]=id ->
  vptr 0x12e3bf8 -> DummyPacketEncDec vptr at [this+0x10] -> stored at owner+0x320.
