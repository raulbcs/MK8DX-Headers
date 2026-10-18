# nn::pia::common::FixedString256 (FixedString&lt;256&gt;)

Identity: typeinfo-row vtable, assigned address 0x12dabd0 (= typeinfo slot,
vptr-8); installed vptr **0x12dabd8**. GOT cell 0x1312b88 holds vptr-0x10
(0x12dabc0 = offset-to-top 0). Typeinfo data 0x12dac10, name
"N2nn3pia6common11FixedStringILj256EEE", base typeinfo 0x12d9648
("N2nn3pia6common6StringE"). 6 slots (0x12dabd8..0x12dac08).

## Member notes

- Slot0 0x9118d8 and slot2 0x92a7e8 (size 0x396) are shared with
  FixedString&lt;16&gt; (template methods folded by the linker); slot0 does not
  match a D1 signature — role unverified. Slot1 0x93b9d4 is the deleting
  dtor (tail `b operator delete`), so the object dtor is trivial.
- Slot3 0x93b778: reset — zeroes +0x1c..+0x41b (loop bound 0x400), then
  [+0x08] = this+0x1c and stur xzr [+0x14].
- Slot4 0x92adac: `ret` stub. Slot5 0x93b9d8: reads capacity [+0x10],
  unrecovered.
- Layout mirrors FixedString16 with a 0x400-byte buffer at +0x1c. Capacity
  0x400 at +0x10 is verified: the embedded-member init at 0x93b610..0x93b63c
  stores `orr w9, wzr, #0x400` to member+0x10.

## Construction / init order

1. No factory allocation found. Size 0x41c is a lower bound from the
   reset() buffer stores (+0x1c + 0x400).
2. Init at 0x93b60c..0x93b63c materializes vptr 0x12dabd8 (cell 0x1312b88
   + 0x10) into a member at owner+0x40, sets member+0x10 = 0x400,
   member+0x14 = 0, and zeroes owner+0x48/+0x58 (sibling fields).
