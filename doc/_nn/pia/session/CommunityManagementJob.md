# nn::pia::session::CommunityManagementJob

Identity: typeinfo-row vtable, assigned 0x12dd870; installed vptr
**0x12dd878**. GOT cell 0x1313690 holds vptr-0x10 (0x12dd868 = offset-to-top
0). Typeinfo data 0x12dd8e0, name "N2nn3pia7session22CommunityManagementJobE"
(name ptr 0xf81270). 7 slots (0x12dd878..0x12dd8a8). Base of the
NexMatchCommunityManagementJob / LanMatchCommunityManagementJob family
(NexMatchCommunityManagementJob.md already cites this base).

## Member notes

- Slots: 0x97dff8 (D1: vptr store, member dtor 0x929ee0 at +0x60, base D1
  0xb4a62c), 0x97e02c (D0, then operator delete), 0xb4a654 / 0xb4a67c /
  0x933314 (shared stubs), 0x97e0b8, 0x97e068 — all unrecovered.
- [this+0x58] u64 — zeroed (0x97dfdc).
- [this+0x60] — member constructed by 0x929ec0 (tail call in C1, 0x97dff4);
  destroyed by 0x929f78-guarded path in D-tors (0x97e08c). Size unverified.

## Construction / init order

1. C1 FUN_710097dfc0 (0x97dfc0..0x97dff4): base C1 0xb4a5e0 (0x97dfd0), then
   +0x58 = 0, then vptr 0x12dd878 = cell 0x1313690 + 0x10
   (0x97dfd4-0x97dfe4), tail-calling the +0x60 member ctor 0x929ec0.
2. Derived ctor 0x93c8d4 calls this C1 (0x93c8e4), zeroes w +0x88, inits
   +0x90/+0x98 pairs and re-installs its own vptr (cell 0x1312c00).
3. No bare-base factory found; extent 0x68 is a lower bound from the +0x60
   member.
