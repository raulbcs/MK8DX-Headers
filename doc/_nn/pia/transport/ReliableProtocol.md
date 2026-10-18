# ReliableProtocol (nn::pia::transport::ReliableProtocol)

- Standard Itanium row: vptr 0x12df238; typeinfo pointer at 0x12df230 ->
  embedded pair 0x12df290 = {0x10, name 0xf825d0
  "N2nn3pia9transport16ReliableProtocolE"}; offset-to-top 0 at 0x12df228.
  11 function slots at vptr+0x00..+0x50.
- GOT cell convention: cell 0x1313bf8 holds addend 0x12df228 = vptr-0x10
  (= the typeinfo-pointer word, 0x12df230); C1/D1 sites do
  `ldr x8, [cell]; add x8, x8, #0x10`.
- Size 0x58 proven: pool allocation 0x9a7c5c (pool obj x0, size w1=0x58,
  0x9235f0-0x9235fc) followed by in-place C1 0x9aecb0 (0x923604); second
  caller 0x925040 identical.

## Identity

pia transport reliable-delivery protocol. One of the four transport protocol
classes registered beside the PacketHandler family
(nn::pia::transport::StationPacketHandler vt 0x12df470 is adjacent). Shares
the abstract protocol base (base C1 0x9a79c8, base extent 0x20) with
MonitoringDataProtocol and NatTraversalProtocol.

## Member notes

- +0x28 u32 = 0xfd (253), protocol id/parameter written by C1 (0x9aece0).
  UnreliableProtocol writes the same 0xfd at its own +0x38.
- +0x30 u64, +0x38 u64, +0x40..+0x4f, +0x50 u64: zeroed by C1 (0x9aeccc-
  0x9aece8); semantics unverified.

## Construction / init order

- C1 = 0x9aecb0 (in-place): base C1 0x9a79c8, then [0x30]=0, [0x38]=0,
  [0x40..0x4f]=0, vptr install (0x9aecc4-0x9aecdc), [0x28]=0xfd, [0x50]=0.
  Also logs via cell 0x13138d0 logger (0x9aecf0-0x9aed1c).
- D1 = slot 0, 0x9aed40 (re-installs vptr, saves x19-x23).
- Slots (11): 0=0x9aed40 (D1);
  1=0x9aee8c; 2=0x9af864; 3=0x9af868; 4=0x9af0f0; 5=0x9a7a34
  (`str wzr,[x8]; ret`); 6=0x9af194; 7=0x9a7a40 (`ret`); 8=0x9af210;
  9=0x9af4bc; 10=0x9a7a54 (`orr w0,wzr,#1`). Slot bodies 1-9 unrecovered
  in functions.csv.
