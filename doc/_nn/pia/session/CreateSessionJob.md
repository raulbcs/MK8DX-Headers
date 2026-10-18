# nn::pia::session::CreateSessionJob

Identity: typeinfo-row vtable, assigned 0x12dd980; installed vptr
**0x12dd988**. GOT cell 0x13136a8 holds vptr-0x10 (0x12dd978 = offset-to-top
0). Typeinfo data 0x12dd9e0, name "N2nn3pia7session16CreateSessionJobE" (name
ptr 0xf812f0). 7 slots (0x12dd988..0x12dd9b8). Common base of the
LocalMatchCreateSessionJob / LanMatchCreateSessionJob /
NexMatchCreateSessionJob family (their docs already cite base C1 0x97e8f4).

## Member notes

- Slots: 0x97e934 (D1: vptr store, member dtor 0x929ee0 at +0x60, base D1
  0xb4a62c), 0x97e968 (D0, then operator delete), 0xb4a654 / 0xb4a67c /
  0x933314 (shared stubs), 0x97efe8, 0x97ef8c — all unrecovered.
- [this+0x58] u64 — zeroed (0x97e910).
- [this+0x60] — member constructed by 0x929ec0 (0x97e920); released via the
  [x0] count-guard + 0x929f78 path in D-tors (0x97e8c4-0x97e8d4). Size
  unverified; 0x20 assumed.
- [this+0x80] u32 — zeroed (0x97e924).

## Construction / init order

1. C1 FUN_710097e8f4 (0x97e8f4..0x97e930): base C1 0xb4a5e0 (0x97e904), then
   +0x58 = 0, then vptr 0x12dd988 = cell 0x13136a8 + 0x10
   (0x97e908-0x97e91c), then the +0x60 member ctor 0x929ec0, then +0x80 = 0.
2. Derived wrappers (0x93dd48 / 0x9d1a84 callers) call this C1 then
   re-install their own vptr and add fields from +0x88.
3. No bare-base factory found; extent 0x88 is a lower bound from the +0x80
   store (derived layouts start at +0x88).
