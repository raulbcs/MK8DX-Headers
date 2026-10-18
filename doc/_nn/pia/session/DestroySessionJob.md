# nn::pia::session::DestroySessionJob (vtable 0x12dda68)

Identity: typeinfo-row vtable, assigned 0x12dda68; installed vptr
**0x12dda70**. GOT cell 0x13136c8 holds vptr-0x10 (0x12dda60 = offset-to-top
0). Typeinfo data 0x12ddac0, name "N2nn3pia7session17DestroySessionJobE"
(name ptr 0xf81350). 7 slots (0x12dda70..0x12ddaa0). Common base of the
LocalMatchDestroySessionJob / LanMatchDestroySessionJob /
NexMatchDestroySessionJob family (their docs already cite base C1 0x97f094).

NOTE: include/_nn/pia/session/DestroySessionJob.hpp already defines
nn::pia::session::DestroySessionJob (behavioral model of the concrete job),
so this base-vtable layout is recorded as `DestroySessionJobBase` in
include/_nn/pia/session/DestroySessionJobBase.hpp to avoid a redefinition.

## Member notes

- Slots: 0x97f0d4 (D1: vptr store, member dtor 0x929ee0 at +0x60, base D1
  0xb4a62c), 0x97f108 (D0, then operator delete), 0xb4a654 / 0xb4a67c /
  0x933314 (shared stubs), 0x97f5cc, 0x97f57c — all unrecovered.
- [this+0x58] u64 — zeroed (0x97f0b0).
- [this+0x60] — member constructed by 0x929ec0 (0x97f0c0); size unverified,
  0x20 assumed.
- [this+0x80] u64 — zeroed (0x97f0c4).

## Construction / init order

1. C1 FUN_710097f094 (0x97f094..0x97f0d0): base C1 0xb4a5e0 (0x97f0a4), then
   +0x58 = 0, then vptr 0x12dda70 = cell 0x13136c8 + 0x10
   (0x97f0a8-0x97f0bc), then the +0x60 member ctor 0x929ec0, then +0x80 = 0.
2. Derived wrapper 0x93ec8c calls this C1 (0x93ec9c) then re-installs its own
   vptr (cell 0x1312d00); LocalMatchDestroySessionJob's ctor installs vptr
   0x12e1ae8 instead (0x9d1f94 caller chain).
3. No bare-base factory found; extent 0x88 is a lower bound from the +0x80
   store.
