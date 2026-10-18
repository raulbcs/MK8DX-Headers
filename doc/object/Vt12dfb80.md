# Vt12dfb80

PLACEHOLDER name (address-anchored). Sibling of Vt12d9c20 / Vt12dc130: 8-byte
polymorphic object with a constant-getter vtable. Table row 0x12dfb80 is the
typeinfo slot: offset-to-top 0 at 0x12dfb78, typeinfo 0x12dfe10 at 0x12dfb80;
the installed vptr is 0x12dfb88.

- Identity: no RTTI name, no owned string. Name stays PLACEHOLDER.
- Extent 0x8: the factory allocates exactly 8 bytes.
- Ctor FUN_71009be110 (in-place): base ctor FUN_71009c3a44 (which itself calls
  FUN_710099b43c at 0x71009c3a54), then vptr 0x12dfb88 (GOT cell 0x1313d20
  holds 0x12dfb78; 0x71009be124..0x71009be130).
- Factory FUN_71009be1a0 (slot 11): allocator FUN_7100568aa0 with size 8
  (0x71009be1ac..0x71009be1b8), construct + vptr install
  (0x71009be1c4..0x71009be1d8).
- Slot 12 FUN_71009be1ec: virtual delete helper (slot-0 virtual call, then
  free FUN_7100568b64).
- Constant getters: slot 2 returns 8 (0x71009be168), slot 3 returns 0x1c
  (0x71009be170), slot 4 returns 1500 (0x71009be188), slot 5 returns 1500
  (0x71009be190), slot 29 returns 0x18 (0x71009be178), slot 30 returns 0
  (0x71009be180), slot 33 FUN_710099b4ac.
- Slots 8/9 (FUN_71009a4740 / FUN_71009a4748) and slot 68 (FUN_710099b500) are
  shared verbatim with the Vt12dc130 table; many other slots are the shared
  FUN_710099b4xx base implementations.
- D1 FUN_71009be140 and D0 FUN_71009be144 tail the pair
  FUN_71009c3a44 / FUN_71009c3a74.
- The immediately following static initializer FUN_71009becb4 fills nn::ldn
  IPv4 address globals via nn::ldn::MakeIpv4Address (PLT 0xb52760,
  0x71009becd0..0x71009becf4) and the Vt12dff50 ctor follows at
  0x71009bed44 - same local-communications neighborhood (unverified as a
  link beyond adjacency).

## Construction / init order

1. Base ctor FUN_71009c3a44 -> FUN_710099b43c (0x71009be120 or 0x71009be1c8).
2. vptr 0x12dfb88 at +0x00 (0x71009be124..0x71009be130).
