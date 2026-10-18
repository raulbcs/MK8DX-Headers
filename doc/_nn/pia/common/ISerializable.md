# nn::pia::common::ISerializable

Identity: typeinfo-row vtable, assigned row 0x12dd3e0 = typeinfo slot;
installed vptr **0x12dd3e8**; GOT cell 0x1313650 holds vptr-0x10; typeinfo
record 0x12dd558 ("N2nn3pia6common13ISerializableE", no base). 7 slots
(0x12dd3e8..0x12dd417), last slot null.

Abstract interface base of nn::pia::lan::LanMessage (ti 0x12dd570). No
standalone constructor found; only inline base-init sequences inside derived
ctors (e.g. 0x97cea4: store vptr at [this], zero u32 +0x8,
memset(this+0xc, 0, 0xb)).

## Member notes

- +0x00 vptr; +0x08 u32 zeroed by every base-init; +0x0c char[11] buffer,
  memset(0, 0xb) at every site (11 = fixed base payload size).
- Size 0x18 (fields end at 0x17; 8-alignment tail unverified).
- Slot table: 0x97da50 (slot0, `ret` stub), 0x97d9b4 (slot1, tail `b
  operator delete`), 0x97cecc (slot2, 0x5c bytes, unrecovered), 0x97cf28
  (slot3, 0x4c bytes, unrecovered), 0x97d140 (slot4, unrecovered), 0x97cf70
  (slot5, `ret` stub), slot6 = 0 (null sentinel).

## Construction / init order

Base-init only, always immediately overridden by the derived vptr:

1. LanMessage inits: 0x97cea4 (gap fn), 0x97cf74/0x97cfd0 (LanMessage C1s),
   0x97d148/0x97d1ac (LanGetHostMessage), 0x97d394/0x97d3f0
   (LanHostMessage), 0x97d560/0x97d5c8 (LanGetSessionMessage) - all load
   cell 0x1313650, add 0x10, store, zero +0x8, memset +0xc for 0xb.
