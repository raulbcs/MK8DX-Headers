# object::PiaPacketHeader

nn::pia::common::Packet::Header (RTTI typeinfo record 0x12f8be0,
mangled name at 0xf8a730 "N2nn3pia6common6Packet6HeaderE").

- Member notes: vtable record 0x12f8ba8 = [typeinfo 0x12f8be0][5 slots
  0x97da50 (FUN_710097da0c+0x44), 0xb49448, 0xb48c04, 0xb48d6c,
  0xb4944c]; vptr = 0x12f8bb8. Slot 3 is the ctor FUN_7100b48d6c
  itself. Neighbor typeinfo/vtable rows in the same data region
  (0x12f8bf8 ISerializable-derived record, 0x12f8c08
  nn::pia::common::Sha256Context with 6 slots 0xb49758..0xb4983c) are
  unmapped and not part of this class.
- Ctor FUN_7100b48d6c writes magic 0x986432ab at +0x8, flag bytes at
  +0xc/+0xd, zeroes at +0xe/+0x12, memsets +0x14 (8 bytes) and +0x1c
  (0x10 bytes), and constructs two members at +0x600/+0x618 via
  0x92a1e0. Max direct store +0x618+8 = 0x620: extent 0x620 is a size
  lower bound (exact extent unverified).
- Install: single site 0xb48ed8-0xb48ef0 loads GOT cell 0x1315f60
  (holds 0x12f8ba8 = typeinfo slot) and stores cell + 0x10 = 0x12f8bb8
  at [this].

## Construction / init order

1. Ctor FUN_7100b48d6c: vptr 0x12f8bb8 at [this] (0xb48ef0).
2. Header magic/flags at +0x8..+0x12, memset regions +0x14/+0x1c.
3. Members at +0x600 and +0x618 via 0x92a1e0 (0xb48ef4/0xb48f00).
