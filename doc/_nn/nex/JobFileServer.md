# nn::nex::JobFileServer

RTTI-named (typeinfo 0x12e76a0, mangled "N2nn3nex13JobFileServerE"; no base typeinfo entry — own MI secondary table). Typeinfo-slot variant: assigned row 0x12e6e30 is the typeinfo slot, offset-to-top 0 at 0x12e6e28, installed vptr = 0x12e6e38. GOT cell 0x1314c20 holds vptr-0x10. 15 primary slots (vt+0x08..vt+0x90).

Size 0x1d8: factory (block containing 0xa390b4-0xa3922c) allocates 0x1d8 via 0x573f04 (0xa390e0) and runs the inline C1 (0xa39100-0xa391f4).

## Member notes

- [this+0x08..0x9f] — nex job base region, shared ctor 0x588b04 with x1=2. Interior unverified.
- [this+0xa0] — own MI secondary vptr 0x12e6ed8 (vt+0xb0). Secondary table at vt+0xa0: offset-to-top -0xa0 (0xffffffffffffff60), typeinfo 0x12e76a0, vptr 0x12e6ed8, slots 0xa3d750, 0xa3d874 — unrecovered.
- [this+0xb0] — nn::nex::Job secondary vptr 0x128c698 (cell 0x130b4a8); the same vptr appears again at [this+0x1a8] (second Job-base subobject head).
- [this+0xb8] byte zero; [this+0xc8] self-pointer to +0xb8; [this+0xd0] = 0x10.
- [this+0xe8] — ForcedCriticalSection vptr (cell 0x130b618, the job-family critical-section base).
- [this+0xf0] u32 — atomic store-release of 1 (stlr).
- [this+0x108]/[this+0x110] — both set to this+0x108; the +0x108..+0x178 region is built by 0x5788e0(this+0x108, sp+0x8).
- [this+0x178..0x1a7] — subobject initialized by 0xa211f8(this+0x178); tail fields zeroed by ctor.
- [this+0x1a8] — Job vptr 0x128c698; +0x1b0 zero; +0x1c0 self-pointer to +0x1b0; +0x1c8 = 0x10; +0x1d0 = 0.

Slot map: slot0 = D1 0xa3d6c8 (restores +0xa0 and +0xb0 vptrs, tears down members, base destroy), slot1 = D0 0xa3d7e4; slots +0x18..+0x68 = shared nex::Job tail (0x5917a0, 0x58ff6c, 0x5917ac, 0x590148, 0x59014c, 0x5917b0, 0x5917cc, 0x58b7d8, 0x5917d4, 0x5917d8, 0x59189c); slots +0x70..+0x90 (0xa3dec0, 0xa3d87c, 0xa3dac0, 0xa3dbf4, 0xa3dd44) unrecovered — override set unverified.

## Construction / init order

- Factory: guard 0x5822fc → new(0x1d8) at 0xa390e0 (0x573f04) → shared job ctor 0x588b04(this, 2, sp+0x8) → inline init 0xa39100-0xa391f4 → virtual dispatch through [vtable+0x68] (slot12) at 0xa391f8-0xa3921c with the caller's variadic arguments, then error branch on the result.
- D1 0xa3d6c8 → D0 0xa3d7e4.
