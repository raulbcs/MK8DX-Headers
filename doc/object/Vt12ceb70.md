# object::Vt12ceb70

PLACEHOLDER name (identity not proven). vptr 0x12ceb70, 54 slots. GOT cell 0x1310e80 holds vptr-0x10 (cell+0x10 = installed vptr; the row address IS the vptr).

Exactly 0x680 bytes (factory `new 0x680` at 0x3836AC). Direct base: Vt12ced30.

## Member notes

- [this+0x00] vptr 0x12ceb70 (0x85D3F8); a further derived wrapper FUN at 0x396E44 re-installs vptr 0x125FEC0 (cell 0x1307528+0x10) over it right after C1 (0x396E58-0x396E64) — same size, one more override layer.
- [this+0x80] pointer array of 0x130-byte elements from the base C1.
- Intrusive singly-linked node chain built by C1: [this+0x4D8]=this+0x558, [this+0x4E8]=this+0x4F8, [this+0x4F0]=this+0x4F8, [this+0x4F8]=this+0x510, [this+0x510]=this+0x528, [this+0x528]=this+0x540, [this+0x540]=this+0x558, [this+0x558]=this+0x570, [this+0x570]=this+0x588, [this+0x588]=this+0x618, [this+0x5A0]=this+0x5B8, [this+0x5B8]=this+0x5D0, [this+0x5D0]=this+0x5E8, [this+0x5E8]=this+0x600 (0x85D3FC-0x85D468); [this+0x4E0], [this+0x600] zeroed (0x85D3E0/0x85D3F0).
- [this+0x678] u16 = 0x100 (0x85D470-0x85D474).
- C1 tail calls FUN_710060B918 with (this+0x4D8, w1=0xC, this+0x618) (0x85D438-0x85D46C) — links the chain (unverified).

## Construction / init order

- C1 = FUN_710085D3C4: base Vt12ced30 C1 FUN_710085D484 with (w1=1, w2=2) at 0x85D3DC; then node chain + vptr + u16 flag as above (0x85D3E0-0x85D474).
- Factory 0x383660 area: `new 0x680` (0x3836AC), then wrapper FUN_7100396E44 runs C1 and overrides the vptr to 0x125FEC0 (0x3836BC); result stored at [x19+0x238].
