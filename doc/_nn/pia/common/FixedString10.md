# nn::pia::common::FixedString<10>

Identity: typeinfo-row vtable, assigned row 0x12dc910 = typeinfo slot;
installed vptr **0x12dc918**; GOT cell 0x13133e0 holds vptr-0x10; typeinfo
record 0x12dc950 ("N2nn3pia6common11FixedStringILj10EEE", base
nn::pia::common::String ti 0x12d9648). 6 slots (0x12dc918..0x12dc93f).

Slots: 0x9118d8 (slot0, shared `ret` stub), 0x973824 (slot1, deleting dtor -
tail `b operator delete`), 0x92a7e8 (slot2, shared assign, identical impl to
all FixedString<N>), 0x973828 (slot3, reset-to-empty: `strb wzr,[x0,#0x1c]!`
then strb/strh sweep of the inline buffer at +0x1c), 0x92adac (slot4, shared
`ret` stub), 0x97388c (slot5, reads capacity [this+0x10] and compares w2 with
mode-dependent stride, like String slot5 0x92a6e4 - unverified).

## Member notes

- Layout identical to the family (doc/_nn/pia/common/FixedString.md):
  +0x00 vptr, +0x08 data pointer -> +0x1c, +0x10 capacity = 4*N = 0x28,
  +0x14/+0x18 zeroed, +0x1c inline buffer of 0x28 bytes.
- Size 0x48 (computed: 0x1c + 0x28 buffer + 4 alignment pad; allocation-size
  evidence not found - unverified).

## Construction / init order

No allocating factory; value subobjects initialized inline at four sites
(all load cell 0x13133e0, add 0x10, store vptr):

1. 0x9733a0 (inside FUN_7100972b54 region): member init in a large consumer
   object.
2. 0x9735e8: stack temp at sp+0x30 - vptr (0x9735f4), cursor = 0 (sp+0x38),
   capacity 0x28 (sp+0x40, 0x973608), `stp wzr,wzr` +0x14/+0x18 (0x9735e4);
   then assign via 0x92aa70(this, sp+0x78, 1) at 0x97360c.
3. 0x974914 (FUN_71009748f8): member at this+0x10 of an object whose own vptr
   comes from cell 0x13133f0; capacity 0x28 at +0x20 (0x97490c-0x974910);
   buffer zeroed from +0x2c (0x974934-0x974948).
4. 0x97b9d8 (FUN_7100972b54 region): member at +0x2e0; capacity 0x28 at
   +0x2f0 (0x97b9ec-0x97b9f4); buffer zeroed from +0x2fc (0x97b9f8+).
