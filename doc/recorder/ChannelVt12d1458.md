# recorder::ChannelVt12d1458 (0x12d1458)

PLACEHOLDER name. Read-side recorder channel derived from the
recorder::QuantChannelReadVt (0x12c3da0) family.

- Identity: 35 slots (0x12d1458..0x12d1570). No RTTI. GOT cell 0x13111e0
  holds 0x12d1448 (vt-0x10); vptr = cell+0x10. Single code site 0x889c8c.
- Ctor: FUN_7100889c6c(this, numValues w1, kind w2) — tail-initializes via
  0x7ad494 (the read-channel head ctor, called with quantum w1 = 0x18 and
  numValues w2), then installs vptr 0x12d1458 at [this] (0x889c98).
- Factories: FUN_7100888ed4 (site 0x8890f8) allocates `new 0x288` with
  numValues = 30; FUN_710088ce2c (site 0x88ce58) allocates `new 0x288` with
  numValues = 10.
- Extent: 0x288 — both factory allocations are exactly 0x288.

## Member notes

- Slots 0/1 = 0x3a8564/0x3a8630 — the read-channel dtor pair shared with
  row 0x12c3da0 (cf. doc/recorder/QuantChannelReadVt.md).
- Read-side override block: slot10 0x7ad508, slot11 0x7ad978, slot13
  0x3a86e0, slot14 0x7ad67c, slot16 0x3a86e8, slot17 0x7ad688, slot19
  0x88a20c, slot21 0x7ada68, slot23 0x7adaa8, slot24 0x7adb1c, slot25
  0x7ad6cc, slot29 0x7adb28, slot31 0x88a184, slot33 0x7ad770 — most shared
  verbatim with the 0x12c3da0 table; slot18/19 (0x88a99c/0x88a20c) are this
  class's own overrides.
- Slots 2-8 = 0x88a948..0x88a990 (csv U, 0x88a948 is 464 B).
- Shared tail slot9 0x7ab904, slot12 0x1ac84, slot15 0x1ac98, slots 20/22
  0x1acd4/0x1acf4, slots 26-28/30/32 (0x3a86f8/0x3a86fc/0x3a8704/0x1ade8/
  0x1adf8), slot34 0x7ac020.

## Construction / init order

1. Factory allocates 0x288.
2. 0x7ad494 initializes the read-channel head (quantum 0x18, caller's
   numValues) — see doc/recorder/QuantChannelReadVt.md.
3. vptr 0x12d1458 installed at [this] (0x889c98).
