# ConnectStationJob (nn::pia::transport::ConnectStationJob)

- vptr 0x12dec38 installed from GOT cell 0x1313ac8 (RELATIVE addend 0x12dec28 =
  vt-0x10; code does `cell+0x10`). vt_ctors.tsv row 0x12dec30 is the typeinfo
  slot. Typeinfo 0x12dec80, name "N2nn3pia9transport17ConnectStationJobE",
  base nn::pia::common::StepSequenceJob.
- Size 0x80, proven by two derived-class inline ctors (0x93602c at
  `_ZdaPvRKSt9nothrow_t+0x32ab90`, 0x974ca4) that run this C2 and then place a
  member subobject at [this+0x80].

## Identity

pia transport job that opens a connection to a single station; derives from
StepSequenceJob (same base family as the session Browse/Join jobs).

## Slots

Primary vtable 0x12dec38, 9 slots:
- slot 0 = 0x9a22a8 (D1, tail `b 0xb4a62c` shared D2)
- slot 1 = 0x9a22ac (D0: D2 then `operator delete` 0x60b470)
- slot 2 = 0xb4a654, slot 3 = 0xb4a67c (shared with
  LocalMatchBrowseMatchmakeJob; unrecovered)
- slot 4 = 0x933314, slot 5 = 0x9a2eb4, slot 7 = 0x9a2eb0,
  slot 8 = 0x9a2b98 (unrecovered)
- slot 6 = 0x9a22e4 "ConnectStationJob::SendConnectionRequest"
  (config/functions.csv label, quality U, 644 bytes)

## Member notes

- 0x00 — vptr.
- 0x08..0x27 — StepSequenceJob base subobject: base C2 0xb4a5e0 runs grandbase
  ctor 0x567cb8, installs the base vptr (cell 0x13150f70, no RELATIVE reloc —
  runtime-filled; unverified) and a secondary vptr 0x12db178
  (cell 0x1313040 + 0x10) at [this+0x28]; zeroes 0x30..0x40, byte 0x48, 0x50.
- 0x58 — zero.
- 0x60 — 0x2710 (10000, timeout-ish constant); 0x64 — zero (stp pair).
- 0x68..0x79 — zeroed by C2 (stp xzr,xzr at 0x68, byte at 0x79).

## Construction / init order

1. C2 0x9a2264 calls base C2 0xb4a5e0.
2. Stores [this+0x60]=0x2710, [this+0x64]=0, zeroes 0x68..0x78, byte 0x79,
   [this+0x58]=0, then installs vptr 0x12dec38 at [this].
3. D1 0x9a22a8 / D0 0x9a22ac tear down via shared D2 0xb4a62c (grandbase D
   0x567cdc); D0 adds `operator delete`.
