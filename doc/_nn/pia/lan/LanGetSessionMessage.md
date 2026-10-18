# nn::pia::lan::LanGetSessionMessage

Identity: typeinfo-row vtable, assigned row 0x12dd4e0 = typeinfo slot;
installed vptr **0x12dd4e8**; GOT cell 0x1313668 holds vptr-0x10; typeinfo
record 0x12dd5d0 ("N2nn3pia3lan20LanGetSessionMessageE", base LanMessage ti
0x12dd570). 7 slots (0x12dd4e8..0x12dd507), last slot null. A further family
member, LanSelfKeepAliveMessage (ti 0x12dd610), follows at row 0x12dd520
(unmapped, out of this batch).

## Member notes

- Base LanMessage extent 0x20; tag 6 at +0x8 (0x97d5b0 / 0x97d650).
- +0x18 u32: 0 by default C1, w1 by the C1-with-arg.
- +0x1c u16 (0 by default C1; w24 by the arg C1), +0x1e u8 (0 / w23),
  +0x1f u8 (w21, arg C1 only; not zeroed by the default C1).
- +0x20 inline payload buffer, 0x320 bytes: NOT zeroed by either C1; the
  arg C1 copies the x5 payload into +0x20 with length `csel w2, w6, 0x320,
  lo` (cap 800) and stores it at +0x340. Semantics of the buffer contents
  unverified (raw bytes).
- +0x340 u32 payload size: 0 by default C1, capped value by the arg C1.
  slot4 (0x97da38) returns [this+0x340] + 0x18 (wire size = payload + base
  header).
- Size 0x348 (stores end at 0x344; alignment tail unverified).

## Construction / init order

1. Default C1 0x97d560 (gap before 0x97d678; ends 0x97d5c4): ISerializable
   base init (cell 0x1313650, 0x97d570-0x97d590), 0 at +0x18 (0x97d59c),
   strh 0 at +0x1c and +0x1e (0x97d5a0-0x97d5a4), own vptr (cell 0x1313668,
   0x97d598), 0 at +0x340 (0x97d5b4), tag 6 (0x97d5b0).
2. C1 0x97d5c8 (gap, ends 0x97d674; called at 0x9705f0 with payload ptr in
   x5): base init (0x97d5f0-region), vptr + tag 6 (0x97d624-0x97d654),
   w1 -> +0x18 (w25), x5 payload copy to +0x20 (0x97d658+), length
   min(w6, 0x320) -> +0x340 (0x97d628-0x97d640), w3 -> +0x1e, w4 -> +0x1f,
   w24(?) -> +0x1c.
