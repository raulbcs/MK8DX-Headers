# UnreliableProtocol (nn::pia::transport::UnreliableProtocol)

- Standard Itanium row: vptr 0x12df6e8; typeinfo pointer at 0x12df6e0 ->
  embedded pair 0x12df740 = {0x10, name 0xf82960
  "N2nn3pia9transport18UnreliableProtocolE"}; offset-to-top 0 at 0x12df6e0-8.
  11 function slots at vptr+0x00..+0x50.
- GOT cell convention: cell 0x1313cc8 holds addend 0x12df6d8 = vptr-0x10.
- Size 0x40 proven: pool allocation 0x9a7c5c with w1=0x40 (0x923578-0x923580)
  followed by in-place C1 0x9ba8a0 (0x923588); second caller 0x924fc4
  identical.

## Identity

pia transport unreliable-delivery protocol. Sibling of ReliableProtocol /
StationProtocol / RttProtocol, all deriving from the abstract protocol base
(base C1 0x9a79c8, base extent 0x20). Writes the same 0xfd (253) constant as
ReliableProtocol, at +0x38.

## Member notes

- +0x28..+0x37: zeroed by C1 (0x9ba8c0). Slot 0 (0x9ba908) reads [x19+0x30] (0x9ba920),
  so +0x30 holds a pointer/handle set post-construction (unverified).
- +0x38 u32 = 0xfd (253), written by C1 (0x9ba8c8).

## Construction / init order

- C1 = 0x9ba8a0 (in-place): base C1 0x9a79c8, [0x28..0x37]=0, vptr install
  (0x9ba8b4-0x9ba8c4), [0x38]=0xfd; then logs via cell 0x13138d0 logger
  (0x9ba8d0-0x9ba8e4).
- Slot 0 = 0x9ba908: re-entrant init/recover — re-installs vptr, if [0x30]
  nonzero re-writes [0x38]=0xfd and calls 0x9baf2c (0x9ba92c-0x9ba938).
- Slots (11): 0=0x9ba908, 1=0x9ba9e8, 2=0x9bb2f8, 3=0x9bb2fc, 4=0x9bae40,
  5=0x9a7a34 (`str wzr,[x8]; ret`), 6=0x9baeb0, 7=0x9a7a40 (`ret`),
  8=0x9baa7c, 9=0x9babdc, 10=0x9a7a54 (`orr w0,wzr,#1`). Bodies 1-9
  unrecovered in functions.csv.
