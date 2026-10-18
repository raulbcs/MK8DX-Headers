# nn::pia::common::FixedString<N>

Identity: typeinfo-row vtables, assigned address = typeinfo slot (vptr-8);
installed vptr = assigned+8; GOT cells hold vptr-0x10. All derive from
nn::pia::common::String (typeinfo base 0x12d9648).

## FixedString<2>

- Assigned row 0x12d96e0; installed vptr **0x12d96e8**; cell 0x1312848;
  typeinfo record 0x12d9720
  ("N2nn3pia6common11FixedStringILj2EEE"). 6 slots (0x12d96e8..0x12d970f).
- Slots: 0x9118d8 (slot0, shared `ret` stub), 0x92c3b4 (slot1, deleting
  dtor - tail-branch `operator delete` clone), 0x92a7e8 (slot2, shared
  assign/copy; reads [x1+0x8]; unverified), 0x92ba38 (slot3, reset-to-empty,
  unrecovered), 0x92adac (slot4, shared `ret` stub), 0x92c3b8 (slot5,
  unrecovered). All absent from functions.csv.

## FixedString<8>

- Assigned row 0x12d9740; installed vptr **0x12d9748**; cell 0x1312858;
  typeinfo record 0x12d9780 ("N2nn3pia6common11FixedStringILj8EEE"). 6 slots
  (0x12d9748..0x12d976f).
- Slots: 0x9118d8 (slot0), 0x92c5a0 (slot1, deleting-dtor clone),
  0x92a7e8 (slot2, shared), 0x92c5a4 (slot3, reset-to-empty), 0x92adac
  (slot4), 0x92c5f8 (slot5). All absent from functions.csv.

## FixedString<32>

- Assigned row 0x12d95b0; installed vptr **0x12d95b8**; cell 0x1312850
  (12 code references); typeinfo record 0x12d95f0
  ("N2nn3pia6common11FixedStringILj32EEE"). 6 slots (0x12d95b8..0x12d95df).
- Slots: 0x9118d8 (slot0), 0x92a44c (slot1, deleting-dtor clone),
  0x92a7e8 (slot2, shared), 0x92a450 (slot3, reset-to-empty:
  0x92a450..0x92a478 clears the inline buffer at this+0x1c, repoints +0x08
  to this+0x1c, zeroes +0x14), 0x92adac (slot4), 0x92a47c (slot5; loads
  capacity [this+0x10] and compares w2, 0x92a47c..0x92a49c - bounds-checked
  copy-out or compare, unverified).

## FixedString<64>

- Assigned row 0x12d97a0; installed vptr **0x12d97a8**; cell 0x1312860;
  typeinfo record 0x12d97e0 ("N2nn3pia6common11FixedStringILj64EEE"). 6
  slots (0x12d97a8..0x12d97cf).
- Slots: 0x9118d8 (slot0), 0x92c7e0 (slot1, deleting-dtor clone), 0x92a7e8
  (slot2, shared), 0x92c7e4 (slot3, reset-to-empty), 0x92adac (slot4),
  0x92c818 (slot5). All absent from functions.csv.

Common member notes and construction order (shared by all N): see below;
per-N sites appended per commit.

## Member notes (all N)

- +0x00 vptr; +0x08 data pointer -> this+0x1c (inline buffer).
- +0x10 capacity = 4*N: 8 at +0x260 for N=2 (0x92b658).
- +0x14/+0x18 zeroed at init; +0x1c inline buffer.
- Size: lower bound 0x20 verified (field stores). The buffer zero-fill in
  FUN_710092b5f0 clears 0x183 B from +0x1c (0x92b6ac loop, 129 x 3 B) which
  spans several neighboring members - full per-object inline extent
  unverified.

## Construction / init order

Value subobjects initialized inline inside big consumer ctors; no
allocating factory found.

1. N=2: FUN_710092b5f0 installs vptr 0x12d96e8 at member +0x250
   (0x92b644-0x92b654), data ptr +0x258 -> +0x26c (0x92b670), capacity 8 at
   +0x260 (0x92b658), zero-fill +0x26c..+0x274 (0x92b64c).
2. N=8: same ctor installs vptr 0x12d9748 at member +0x370 (0x92b6cc-0x92b6f8,
   cell 0x1312858 + 0x10); also embedded at nn::pia::inet::NexFacade+0x10
   (see doc/_nn/pia/inet/NexFacade.md).
3. N=32: FUN_710092b5f0 installs vptr 0x12d95b8 at member +0x288
   (0x92b684-0x92b6a0, cell 0x1312850 + 0x10); capacity 0x80 at +0x298
   (0x92b6a4); data ptr +0x290 -> +0x2a4 written later (0x92b6f4).
4. N=64: same ctor installs vptr 0x12d97a8 at member +0x460
   (0x92b878-0x92b888, cell 0x1312860 + 0x10); capacity 0x100 at +0x470
   (0x92b88c-0x92b894); data ptr +0x468 zeroed (0x92b898).
