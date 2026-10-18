# nn::nex::ClientProtocolRequestBroker

RTTI-named (typeinfo 0x12e74a0, mangled "N2nn3nex27ClientProtocolRequestBrokerE"; base typeinfo 0x12e64a0 = nn::nex::ProtocolRequestBrokerInterface). Typeinfo-slot variant: assigned row 0x12e6ba8 is the typeinfo slot, offset-to-top 0 at 0x12e6ba0, installed vptr = 0x12e6bb0. GOT cell 0x1314c08 holds vptr-0x10. 18 slots (vt+0x08..vt+0x90), no secondary table. All slots unrecovered in functions.csv except as noted below.

Size 0xd0: allocation new(0xd0) at 0xa38a90 (via 0x573f04) in the factory containing the inline C1 block 0xa38ab0-0xa38b00.

## Member notes

- [this+0x08..0x8f] — base ProtocolRequestBrokerInterface region (base C1 0xa2c4cc); interior unverified.
- [this+0x88] — pointer to the subobject head at +0x90 (ctor stores this+0x90 there).
- [this+0x90]/[this+0x98] — zeroed by ctor; D1 (0xa37838) tears the pair down via 0xa4258c(this+0x88, [this+0x90]).
- [this+0xa0] u32 — written by virtual slot2 0xa378b8 (stores its w2 argument, then tail-calls 0xa378e0).
- [this+0xa8] — member vptr 0x128d720 (cell 0x130b898), then initialized by 0x58fe98 with w1=3 (x0 left at this+0xa8 via pre-indexed store).
- [this+0xb0] = 0; [this+0xb8] = -1; [this+0xc0] = 1; [this+0xc8] = -1 (sentinel fields written by the ctor).

Slot map: slot0 = D1 0xa37838, slot1 = D0 0xa37874 (then operator delete 0x573f48), slot2 = 0xa378b8; slots 3-17 (0xa37c80, 0xa37fb8, 0xa38928, 0xa38930, 0xa38934, 0xa3893c, 0xa38944, 0xa38484, 0xa3867c, 0xa38808, 0xa3894c, 0xa3897c, 0xa389ac, 0xa381c8, 0xa38328) unrecovered — override set unverified.

## Construction / init order

- Factory (encloses 0xa38a4c-0xa38b14): asserts via 0x575b90, new(0xd0) at 0xa38a90, base C1 0xa2c4cc at 0xa38aa8, then the inline C1 block: vptr install (0xa38ab0-0xa38ab8), +0x88 self-subobject pointer, +0xa8 member vptr, sentinel fields, member init 0x58fe98, result stored to [x19+8].
- D1 0xa37838 → D0 0xa37874 → operator delete.
