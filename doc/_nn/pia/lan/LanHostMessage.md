# nn::pia::lan::LanHostMessage

Identity: typeinfo-row vtable, assigned row 0x12dd4a0 = typeinfo slot;
installed vptr **0x12dd4a8**; GOT cell 0x1313660 holds vptr-0x10; typeinfo
record 0x12dd5b0 ("N2nn3pia3lan14LanHostMessageE", base LanMessage ti
0x12dd570). 7 slots (0x12dd4a8..0x12dd4c7), last slot null.

## Member notes

- No fields beyond the LanMessage base (extent 0x20): both C1s store only
  the tag 5 at +0x8 and 0/w1 at +0x18. No embedded member (unlike
  LanGetHostMessage / LanGetSessionMessage).
- Slot table: 0x97da50 (slot0, `ret` stub), 0x97da28 (slot1, tail `b
  operator delete`), 0x97d450 (slot2, 0x90 B, unrecovered), 0x97d4e0
  (slot3, unrecovered - functions.csv size 0x408 erroneously merges the
  LanGetSessionMessage C1 TU starting 0x97d560), 0x97da2c (slot4, fixed
  payload size 0x10), 0x97cf70 (slot5, `ret` stub), slot6 = 0.

## Construction / init order

1. Default C1 0x97d394 (0x92 bytes): ISerializable base init (cell
   0x1313650, 0x97d3a4-0x97d3c4), 0 at +0x18 (0x97d3d0), own vptr (cell
   0x1313660 + 0x10, 0x97d3cc), tag 5 (0x97d3dc).
2. C1 0x97d3f0 (0x96 bytes): base init (0x97d408), w1 -> +0x18 (0x97d430),
   vptr (0x97d42c), tag 5 (0x97d43c).
