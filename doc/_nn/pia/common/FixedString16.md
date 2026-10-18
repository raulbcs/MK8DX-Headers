# nn::pia::common::FixedString16 (FixedString&lt;16&gt;)

Identity: typeinfo-row vtable, assigned address 0x12d99a0 (= typeinfo slot,
vptr-8); installed vptr **0x12d99a8**. GOT cell 0x13128d8 holds vptr-0x10
(0x12d9998 = offset-to-top 0). Typeinfo data 0x12d99e0, name
"N2nn3pia6common11FixedStringILj16EEE", base typeinfo 0x12d9648
("N2nn3pia6common6StringE"). 6 slots (0x12d99a8..0x12d99d8).

## Member notes

- Slot0 0x9118d8: shared with FixedString&lt;256&gt;; takes (this, x1, x2, w3) and
  does not match a D1 signature — role unverified. Slot1 0x92efcc is a
  deleting dtor (tail `b operator delete`), so the object dtor is trivial.
- Slot2 0x92a7e8: shared with FixedString&lt;256&gt;, size 0x396, unrecovered.
- Slot3 0x92ee5c: reset — zeroes +0x1c..+0x5b in 4-byte strides, then
  [+0x08] = this+0x1c and stur xzr [+0x14].
- Slot4 0x92adac: `ret` stub. Slot5 0x92efd0: reads capacity [+0x10],
  compares against x2, unrecovered.
- Layout: +0x00 vptr, +0x08 cursor, +0x10 capacity (0x40 bytes for the
  16-element / 4-byte-element instantiation), +0x14/+0x18 counters,
  +0x1c inline buffer (0x40 bytes).

## Construction / init order

1. Factory FUN_7100932114 (0x932114..0x932180): allocator 0x563b70, then
   `orr w0, wzr, #0x60`; operator new 0x568aa0 — size 0x60 EXACT.
2. Inlined ctor (0x932130..0x932180): [+0x00] = vptr 0x12d99a8 (cell
   0x13128d8 + 0x10), [+0x08] = 0, [+0x10] = 0x40, [+0x14] = 0,
   [+0x18] = 0 (0x932138), then zeroes +0x1c..+0x5b in 4-byte strides.
3. Also installed as a member subobject at owner+0xb8 by the shared init
   FUN_710092ed98 region (0x92ed94..0x92edac, owner fields around it).
