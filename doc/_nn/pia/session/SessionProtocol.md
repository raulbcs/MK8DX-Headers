# SessionProtocol (nn::pia::session::SessionProtocol)

- vptr 0x12de6e8 = first slot row; offset-to-top 0 at 0x12de6d8 (= GOT cell
  0x13139f0 addend), typeinfo 0x12de740 at 0x12de6e0
  ("N2nn3pia7session15SessionProtocolE"). GOT cell 0x13139f0 holds vptr-0x10.
- Size 0x150, proven by the creation site at 0x9977a0: pool allocation
  0x9a7c5c with size 0x150 (0x9977a4-0x9977ac) then C1 0x99b534 (0x9977b4),
  result stored at [x8, #0xb8] and registered via 0x9a7ccc. Note: C1 only
  initializes +0x28..+0x49; the +0x4a..+0x14f region is part of the
  allocation but its field layout is unverified.

## Identity

pia session protocol (session-state handling); abstract-protocol-base
derived (base C1 0x9a79c8, base D1 0x9a79f0), created by the same aggregated
setup function as Mesh/SyncClock/BandwidthCheck protocols (creation sites
0x98679c/0x9977a0/0x986804/0x986854).

## Member notes

- +0x28 u32 = 0xfd (253) — matches the 0xfd constant also stored by
  SyncClockProtocol (+0x38) and ReliableBroadcastProtocol (+0x30), likely a
  protocol version/max-id constant.

## Construction / init order

- C1 = 0x99b534: base C1 0x9a79c8 (0x99b544), +0x30 zeroed (0x99b55c),
  +0x28 = 0xfd (0x99b554-0x99b558), +0x40 zeroed, +0x48/+0x38 strh wzr,
  vptr swap from cell 0x13139f0 (0x99b54c-0x99b568).
- D1 = slot 0, 0x99b57c (tail `b` to base D1 0x9a79f0). D0 = slot 1,
  0x99b580 (base D1, then operator delete 0x60b470).
- Slots (11): 0=0x99b57c (D1), 1=0x99b580 (D0), 2=0x99d288 (4-byte stub),
  3=0x99d28c, 4=0x99b774, 5=0x9a7a34 (shared stub), 6=0x99b808, 7=0x9a7a40
  (shared stub), 8=0x99b884, 9=0x99be98, 10=0x9a7a54 (`orr w0,wzr,#1`).
  Slots 3/4/6/8/9 absent from functions.csv (unrecovered).
