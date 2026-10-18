# nn::pia::session::ClearMatchmakeSystemPasswordJob

Identity: typeinfo-row vtable, assigned 0x12dd6a0; installed vptr
**0x12dd6a8**. GOT cell 0x1313680 holds vptr-0x10 (0x12dd698 = offset-to-top
0). Typeinfo data 0x12dd6f0, name "N2nn3pia7session31ClearMatchmakeSystemPasswordJobE"
(name ptr 0xf811d0). 7 slots (0x12dd6a8..0x12dd6d8). Base of the
NexMatchClearSystemPasswordJob / LanMatchClearSystemPasswordJob family.

## Member notes

- Slots: 0x97ddfc (D1: vptr store, member dtor 0x929ee0 at +0x68, base D1
  0xb4a62c), 0x97de30 (D0, then operator delete), 0xb4a654 / 0xb4a67c /
  0x933314 (shared stubs), 0x97df44, 0x97dee8 — all unrecovered.
- [this+0x58] u32 — zeroed (0x97dddc).
- [this+0x60] u64 — zeroed (0x97dde0).
- [this+0x68] — member constructed by 0x929ec0 (tail call in C1, 0x97ddf8);
  size unverified, 8 bytes assumed.

## Construction / init order

1. C1 FUN_710097ddc0 (0x97ddc0..0x97ddf8): base C1 0xb4a5e0 (0x97ddd0), then
   +0x58 = 0, +0x60 = 0, then vptr 0x12dd6a8 = cell 0x1313680 + 0x10
   (0x97ddd4-0x97dde8), tail-calling the +0x68 member ctor 0x929ec0.
2. Derived wrapper 0x93c58c calls this C1 then re-installs its own vptr
   (cell 0x1312bd8) and adds fields at +0x88 (0x93c59c-0x93c5a8).
3. No bare-base factory found; extent 0x70 is a lower bound from the +0x68
   member.
