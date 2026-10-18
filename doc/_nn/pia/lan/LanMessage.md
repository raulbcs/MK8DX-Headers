# nn::pia::lan::LanMessage

Identity: typeinfo-row vtable, assigned row 0x12dd420 = typeinfo slot;
installed vptr **0x12dd428**; GOT cell 0x1313658 holds vptr-0x10; typeinfo
record 0x12dd570 ("N2nn3pia3lan10LanMessageE", base
nn::pia::common::ISerializable ti 0x12dd558). 7 slots
(0x12dd428..0x12dd447), last slot null. Base of the lan message family
(LanGetHostMessage / LanHostMessage / LanGetSessionMessage).

## Member notes

- ISerializable base extent 0x18 (vptr, u32 +0x8, char[11] +0xc).
- +0x18 u32 written by the C1-with-arg (w1), 0 by the default C1. Message
  type tag lives at base +0x8: LanMessage = 3 (0x97cfc0 / 0x97d020);
  GetHost = 4, Host = 5, GetSession = 6 (see their docs).
- slot4 = 0x97d9bc (`orr w0, wzr, #0x10; ret`) - fixed payload size 0x10.
- Size 0x20 (stores end at 0x1c; alignment tail unverified).

## Construction / init order

1. Default C1 0x97cf74 (0x92 bytes): ISerializable base init (cell
   0x1313650, zero +0x8, memset +0xc 0xb, 0x97cf84-0x97cfa4), store 0 at
   +0x18 (0x97cfb0), install own vptr (cell 0x1313658 + 0x10, 0x97cfac),
   tag 3 at +0x8 (0x97cfc0).
2. C1 0x97cfd0 (0x96 bytes): same base init (0x97cfe8), w1 -> +0x18
   (0x97d010), vptr (0x97d00c), tag 3 (0x97d020).

Slots 2/3 = 0x97d030 (0x90 B) / 0x97d0c0 (0x88 B), unrecovered (serialize /
deserialize candidates).
