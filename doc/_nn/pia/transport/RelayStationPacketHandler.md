# RelayStationPacketHandler (nn::pia::transport::RelayStationPacketHandler)

- vt row 0x12df020 is the typeinfo slot; real vptr 0x12df028 (vptr-8 ->
  typeinfo 0x12df0e0, "N2nn3pia9transport25RelayStationPacketHandlerE"). GOT
  cell 0x1313bb8 holds addend 0x12df018 = vptr-0x10.
- Size 0x520, proven by the nothrow-new factory 0x710093151c
  (`operator new(0x520)` -> C1 0x71009ab8e0).

## Identity

pia transport relay-station packet handler; derives from
StationPacketHandler (C1 0x71009b4a2c, size 0x518) and appends a single
pointer-sized relay-context field at +0x518.

## Slots

Primary vtable 0x12df028, 23 slots:
- slot 0 = 0x71009ac4e8 (D1 deleting dtor; base-class slot0 trampoline
  0x71009ac4e4 at +0x48 of the dump is the inherited thunky variant).
- slot 1 = 0x71009ac608 (D0 complete dtor, 0x180 bytes: base D-chain then
  operator delete 0x710060b470).
- slot 2 = 0x71009ab914 (tail-call base D1 0x71009b4a68).
- slot 3 = 0x71009ab918 (D-variant: base D1 then delete — relay override of
  the dtor set; 0x38-byte wrapper).
- slot 4 = 0x71009ab980 (trampoline: [x0+0x518] = 0, tail-call base
  0x71009b4b70).
- slot 19 = 0x71009ab93c (handler override wrapping base 0x71009b4af0: runs
  base, and if the out flag is zero stores 0 at [this+0x518]).
- slot 3' (dump offset +0x60..) = 0x71009ab988 (multi-arg handler: forwards
  to base 0x71009b4b84 and stores arg x6 at [this+0x518] when the base returns
  zero). Remaining slots inherited from StationPacketHandler /
  transport::PacketHandler (0x71009a676c/9a67a8/9a67c0/9b5cb0/9a6938/9ac664
  etc.).

## Construction / init order

C1 0x71009ab8e0:
1. base C1 0x71009b4a2c (full StationPacketHandler init).
2. [this+0x518] = 0.
3. vptr 0x12df028 at [this].
