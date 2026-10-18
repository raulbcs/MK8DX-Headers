# Vt12d7ce8

Identity: installed vptr **0x12d7ce8** (no RTTI - typeinfo slot at vptr-8 is
0, offset-to-top 0). GOT cell 0x1312338 holds vptr-0x10 (0x12d7cd8).
9 slots (0x12d7ce8..0x12d7d08), slots 7/8 null. Row bounded by the next
published vptr row 0x12d7d30 (cell 0x13123b8).

## Member notes

- Slot targets: 0x91000c / 0x9100d8 / 0x910134 / 0x9101ac are interior
  entry points of FUN_710090fc08 (+0x404/+0x4d0/+0x52c/+0x5a4, not
  standalone-recovered); 0x556a98 (slot2) and 0x55686c (slot4) are
  recovered FUN_* in functions.csv; slot3 0x556abc is the tail of
  FUN_7100556a98+0x24.
- The vptr is installed at [x20+0x00] of a sub-object constructed inline by
  the enl::TaskThread::ThreadHeap ctor FUN_7100907d10 (32,504 B); the
  sub-object pointer is stored to the parent at [x19+0x30] (0x90f6b8).
- Ctor stores within the sub-object run through +0xe4 (strb +0xd8 0x90f6ac,
  str +0xe0 0x90f6b0), so size 0xe4 is a lower bound; the sub-object's real
  extent is unverified.

## Construction / init order

1. Inside FUN_7100907d10: members of the sub-object zero-initialized
   (0x90f674-0x90f690: +0x18, +0x2c, +0x78, +0x7c, +0x88), helper call
   0x628628 (0x90f680) with x0 = this+0x38.
2. vptr 0x12d7ce8 = cell 0x1312338 + 0x10 installed at [x20]
   (0x90f68c-0x90f6a0).
3. Sub-calls with x0 = this+0x90 (bl 0x91c984, 0x90f6a4) and this+0xe4
   (bl 0x91cd70, 0x90f6b4); byte/word zeros at +0xd8/+0xe0 (0x90f6ac-0x90f6b0).
4. Sub-object stored to parent+0x30 (0x90f6b8).
