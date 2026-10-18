# object::Vt12e5c28 (UserMessage, PROVISIONAL)

26-slot class whose ctor is handed the string "UserMessage" (0xf15048) as a
name argument; table row 0x12e5c28 is the typeinfo slot — the installed vptr
is 0x12e5c30 (see below). Instances are tree nodes holding a message-like
record with a flags word and an embedded +0x88/+0x90 self-referential node.

- Identity: PROVISIONAL name from the "UserMessage" SafeString passed to base
  ctor 0x587544 in the owning factory (0xa2a7c0..0xa2a7e8); no RTTI.
- vptr convention: GOT cell 0x1314980 holds 0x12e5c20 (vt-0x10); installed
  vptr = cell+0x10 = **0x12e5c30**. The vt_ctors row 0x12e5c28 is the
  typeinfo slot at vptr-8 (its addend 0x12e6400 is a data pointer), so all
  slot numbers below start at 0x12e5c30.
- Size: operator new(0xa8) at 0xa2a79c/0xa2a7a0 (inlined factory ctor
  0xa2a780); placement variant 0xa2a620 region uses the same 0xa8 layout.

## Member notes

- +0x48 halfword = 0; +0x50..+0x5f = 0; +0x60 flags = 9 (0xa2a838); +0x68 =
  0; +0x70 byte = 0; +0x78 = 0; +0x80 = 0.
- +0x88 = this+0x90 (self-pointer), +0x90 = 0, +0x98 = ctor x20 param
  (0xa2a830..0xa2a840) — intrusive node trio torn down by D1 0xa2a6c8 via
  0xa30890 on +0x88 and +0x90.
- +0x60 flag OR-setter at 0xa2a6b8 (`orr w8, w8, w1`).
- Slots (from 0x12e5c30): slot0 = D1 0xa2a6c8, slot1 = D0 0xa2a72c (tail
  0x58773c base dtor), slot2 = 0xa303a8, slot3 = 0xa303b4, slot4 = 0xa30414,
  slots 5..7 = 0x591864/0x591868/0x591874, slot8 = 0xa2bd80, slot9 = 0x591880,
  slot10 = 0xa2bdb4, slot11 = 0x591888, slot12 = 0x5901e8 (0x272 bytes;
  also called in ctor tail 0xa2a690/0xa2a85c with a stack-built argument),
  slot13 = 0x5902dc, slots 14..19 = 0x591890/0x591898/0xa30418/0xa30390/
  0xa30394, slot20 = 0xa2a780 (virtual clone: news a 0xa8 copy and runs the
  full ctor), slot21 = 0xa303a0, slot22 = 0xa2a950 (0x348 bytes), slots
  23/24 = 0xa30420/0xa30424, slot25 = 0xa2a888 (unverified groupings; most
  slots unrecovered in functions.csv).

## Construction / init order

1. `operator new(0xa8)` (0xa2a79c); base ctor 0x587544 with a stack argument
   built around SafeString "UserMessage" (0xa2a7b4..0xa2a7e8).
2. +0x48 halfword 0, +0x50..+0x5f = 0, +0x68 = 0, +0x70 = 0, +0x78 = 0,
   +0x80 = 0 (0xa2a7f8..0xa2a81c).
3. vptr = cell 0x1314980 + 0x10 = 0x12e5c30 (0xa2a820..0xa2a828).
4. +0x88 = this+0x90, +0x90 = 0, +0x60 = 9, +0x98 = param (0xa2a82c..0xa2a840).
5. Slot12 method 0x5901e0-registration call with a rebuilt stack argument
   (0xa2a844..0xa2a85c) closes the ctor.
