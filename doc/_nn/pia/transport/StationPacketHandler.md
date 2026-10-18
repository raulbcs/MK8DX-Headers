# StationPacketHandler (nn::pia::transport::StationPacketHandler)

- vt row 0x12df468 is the typeinfo slot; real vptr 0x12df470 (vptr-8 ->
  typeinfo 0x12df530, "N2nn3pia9transport20StationPacketHandlerE"). GOT cell
  0x1313c68 holds addend 0x12df460 = vptr-0x10.
- Size 0x518, proven by the nothrow-new factory 0x71009a4790
  (`operator new(0x518)` -> C1 0x71009b4a2c).

## Identity

pia transport station packet handler; base class is
nn::pia::transport::PacketHandler (base C1 0x71009a5700, base vptr 0x12dee18
via cell 0x1313b48, typeinfo 0x12deeb0). RelayStationPacketHandler derives
from this class (size 0x520 = 0x518 + one pointer).

## Slots

Primary vtable 0x12df470, 23 slots:
- slot 0 = 0x71009b4a68 (D1 deleting dtor: reinstall vptr, tear down +0x508
  via 0x71009bb53c, +0x500 via 0x71009bb5d4, base D2 0x71009a576c, delete).
- slot 1 = 0x71009b4aa8 (D0 complete dtor, same chain then operator delete
  0x710060b470).
- slot 2 = 0x71009b4b70, slots 5/6 = 0x71009b4be4/9b4bf8, slot 7 =
  0x71009b4e20, slot 8 = 0x71009b5e78, slot 19 = 0x71009b4af0 (handler: builds
  a bitmask from the +0x58 station list, entries tested for kind==5 and
  bit<=0x1f; clears one bit from +0x268 when bit0 of arg1 is clear), slots
  20..22 = 0x71009b51f4/9b582c/9b5b38; shared base slots 11..14/16 =
  0x71009a676c/9a67a8/9a67c0/9a67c0/9b5cb0/9a6938; slot 17/13 shared with the
  Relay override set. Remaining slots unrecovered.

## Construction / init order

C1 0x71009b4a2c:
1. base C1 0x71009a5700 (vptr 0x12dee18, +0x10 = 0, +0x18 subobject ctor
   0x71009a89e0, +0x418 ctor 0x71009a859c, +0x478..0x4b0 zeroes, +0x490 =
   this, +0x4b8 ctor 0x7100929fc4, +0x4d0..0x4e0 zero).
2. vptr 0x12df470 at [this].
3. +0x500 subobject via 0x71009bb5c0; +0x508 subobject via 0x71009bb530.
