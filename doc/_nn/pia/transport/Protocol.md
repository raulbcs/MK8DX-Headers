# Protocol (nn::pia::transport::Protocol)

- Typeinfo slot 0x12e0360 -> typeinfo 0x12e03c0, name string 0xf82db0
  "N2nn3pia9transport8ProtocolE". Primary vptr 0x12e0368; GOT cell 0x1312470
  holds 0x12e0358 (vt-0x10, RELATIVE reloc).
- Size 0x30: factory allocates 0x30 (0x71009cc7b4 new via 0x7100568aa0) and
  no store beyond 0x2c.

## Identity

Small value-like protocol descriptor inside nn::pia transport; embedded as a
subobject (at +0x4b98) inside a larger job object whose ctor calls C1
0x710099d294 (site 0x7100912d4c).

## Slots

7 slots (0x12e0368..0x12e0398): slot 0 = 0x710099d2b0 (`ret` stub), slot 1 =
0x71009c235c (unrecovered), slot 2 = 0x710099d2e4 (copy helper: copies
+0x8/+0xc/+0x10), slot 3 = 0x71009c22b4, slot 4 = 0x71009c2380 (`ret`
stub), slot 5 = 0x71009c2384 (returns this+0x20), slot 6 = 0x71009c22f4
(unrecovered).

## Member notes

- 0x0c — u32 = 0x14 set by C1; 0x14/0x16 — u16 = 0xffff set by factory;
  0x18/0x19 — bool pair 1/0 set by factory.
- 0x20 — pointer, zero; 0x28/0x2c — u32 pair, zero.

## Construction / init order

1. Factory 0x71009cc7bc: new 0x30, C1 0x710099d294 (vptr at [this],
   +0x8 = 0, +0xc = 0x14, +0x10 = 0), then +0x14/-0x16 = 0xffff, +0x18 =
   1, +0x19 = 0, +0x20 = 0, +0x28/+0x2c = 0; result stored to [x19+0x28].
2. Embedded use: ctor at 0x7100912d4c runs C1 on this+0x4b98 then writes
   the same flag pattern at +0x4bac..+0x4bb1 of the outer object.
