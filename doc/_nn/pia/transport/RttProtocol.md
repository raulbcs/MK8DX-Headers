# RttProtocol (nn::pia::transport::RttProtocol)

- Standard Itanium row: vptr 0x12df908; typeinfo pointer at 0x12df900 ->
  embedded pair 0x12df960 = {0x10, name 0xf82b00
  "N2nn3pia9transport11RttProtocolE"}; offset-to-top 0 at 0x12df900-8.
  11 function slots at vptr+0x00..+0x50.
- GOT cell convention: cell 0x1313ce0 holds addend 0x12df8f8 = vptr-0x10.
- Size 0x58 proven: pool allocation 0x9a7c5c with w1=0x58 (0x9b7f18-0x9b7f24)
  followed by in-place C1 0x9bc6ec (0x9b7f28).

## Identity

pia transport RTT (round-trip time) measurement protocol. Sibling of
ReliableProtocol / StationProtocol / UnreliableProtocol, all deriving from
the abstract protocol base (base C1 0x9a79c8, base extent 0x20). Writes the
shared 0xfd (253) constant at +0x38 like UnreliableProtocol.

## Member notes

- +0x38 u32 = 0xfd (253), written by C1 (0x9bc700).
- +0x40..+0x4f u64[2], +0x50 u16, +0x52 u8: zeroed by C1 (0x9bc710-0x9bc720);
  RTT sample store candidates, unverified.
- +0xc4 read by a nearby helper (0x9bc6cc: `ldr w8,[x0,#0xc4]`, wraps at 0xff)
  — but that is beyond 0x58 and likely belongs to a different (derived or
  unrelated) object; not a member of this class.

## Construction / init order

- C1 = 0x9bc6ec (in-place): base C1 0x9a79c8, [0x38]=0xfd, [0x40..0x4f]=0,
  [0x50..0x51]=0, vptr install (0x9bc708-0x9bc71c), [0x52]=0.
- D1 = slot 0, 0x9bc730 (tail `b` to base D1 0x9a79f0 — no own fields).
- D0 = slot 1, 0x9bc734 (base D1, then operator delete 0x60b470).
- Slots (11): 0=0x9bc730 (D1), 1=0x9bc734 (D0), 2=0x9bd244, 3=0x9bd248,
  4=0x9bc8b4, 5=0x9a7a34 (`str wzr,[x8]; ret`), 6=0x9bc964, 7=0x9a7a40
  (`ret`), 8=0x9bc9e0, 9=0x9bce3c, 10=0x9a7a54 (`orr w0,wzr,#1`). Bodies
  2-9 unrecovered in functions.csv.
