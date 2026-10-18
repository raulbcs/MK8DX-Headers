# StationProtocol (nn::pia::transport::StationProtocol)

- Standard Itanium row: vptr 0x12df558; typeinfo pointer at 0x12df550 ->
  embedded pair 0x12df5b0 = {0x10, name 0xf82790
  "N2nn3pia9transport15StationProtocolE"}; offset-to-top 0 at 0x12df550-8.
  11 function slots at vptr+0x00..+0x50.
- GOT cell convention: cell 0x1313c70 holds addend 0x12df548 = vptr-0x10.
- Size 0x30 proven: pool allocation 0x9a7c5c with w1=0x30 (0x9b7ec0-0x9b7ecc)
  followed by in-place C1 0x9b5fcc (0x9b7ed4).

## Identity

pia transport station protocol (10000 ms period constant at +0x28 suggests a
timeout/interval in ms; unverified). Sibling of ReliableProtocol /
UnreliableProtocol / RttProtocol, all deriving from the abstract protocol
base (base C1 0x9a79c8, base extent 0x20).

## Member notes

- +0x28 u32 = 0x2710 (10000), written by C1 (0x9b5ff0). Slot 5 (0x9b6038)
  zeroes +0x2c and the caller-supplied out slot, hinting +0x2c is a status
  field (unverified).

## Construction / init order

- C1 = 0x9b5fcc (in-place): base C1 0x9a79c8, vptr install (0x9b5fe0-0x9b5fec),
  [0x28]=0x2710.
- D1 = slot 0, 0x9b6004 (tail `b` to base D1 0x9a79f0 — no own fields).
- D0 = slot 1, 0x9b6008 (base D1, then operator delete 0x60b470).
- Slots (11): 0=0x9b6004 (D1), 1=0x9b6008 (D0), 2=0x9b7d4c, 3=0x9b7d50,
  4=0x9b6038 (`str wzr,[x0,#0x2c]; str wzr,[x8]; ret`), 5=0x9a7a34
  (`str wzr,[x8]; ret`), 6=0x9b6044 (`str wzr,[x0,#0x2c]; ret`),
  7=0x9a7a40 (`ret`), 8=0x9b604c (large body, 0x80-byte frame),
  9=0x9a7a4c (`str wzr,[x8]; ret`), 10=0x9b7d44. Bodies 2/3/8/10
  unrecovered in functions.csv.
