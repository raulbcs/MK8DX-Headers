# NatTraversalProtocol (nn::pia::nat::NatTraversalProtocol)

- vptr 0x12dbe50 = first slot row; offset-to-top 0 at 0x12dbe40, typeinfo
  0x12dbeb0 at 0x12dbe48 ("N2nn3pia3nat20NatTraversalProtocolE"). GOT cell
  0x13132b0 holds addend 0x12dbe40 = vptr-0x10 (C1 store 0x9692b8-0x9692c8,
  D1 reinstall 0x96955c-0x969568).
- Size 0xe78, proven by the factory at 0x964d98: pool allocation
  0x9a7c5c(ptr, 0xe78) (0x964de0-0x964de8) then C1 0x96929c (0x964df0), then
  0x9a7ccc handshake (0x964df4-0x964e00). Consistent with the last member at
  +0xe68 (0x10 bytes).

## Identity

pia NAT traversal protocol. Derives from the abstract pia protocol base
(base C1 0x9a79c8, base vptr cell 0x1313b90, base fields +0x00..+0x1a).
Registered in the protocol descriptor map at startup: node
{0x128d9f8, cell value, 0, name string 0xed6af8} built at 0x90d41c-0x90d434
(cell 0x13132b0) with a twin site for cell 0x13132d0 at 0x90e440.

## Member notes

- +0x28 u32 flag, zeroed by C1.
- +0x30 / +0x68 / +0xe18: member subobjects with C1/D 0x9b38b8.
- +0xa0: member subobject, C1 0x929ec0.
- +0xc0: member subobject, C1 0x967960. +0x110 / +0x160: 0x9689a4.
  +0x1b0: 0x969450.
- +0xc8/+0xd8/+0xe0, +0x118/+0x128/+0x130, +0x168/+0x194, +0x1b8/+0x1e4:
  intrusive node lists (head, u32 count, pool ptr) — D1 0x969540 walks and
  frees them (0x96956c-0x9695c0, 0x9695c4-0x969618, 0x9693bc-0x9693fc,
  0x969400-0x96944c).
- +0xe50 u8 / +0xe58 / +0xe60 zeroed by C1 (0x969324-0x96932c); +0xe68 last
  member, C1 0x573c38.

## Construction / init order

- C1 = 0x96929c: base C1 0x9a79c8 (0x9692b0), vptr swap (0x9692b8-0x9692c8),
  then the members above in ascending offset order (0x9692cc-0x969330).
- D1 = slot 0, 0x969540 (reinstall vptr, free the four node lists, ...).
  D0 = slot 1, 0x9697e8.
- Slots (11): 0=0x969540 (D1), 1=0x9697e8 (D0), 2=0x96be34, 3=0x96be3c,
  4=0x9a7a2c (base stub), 5=0x9a7a34, 6=0x9a7a3c, 7=0x9a7a40, 8=0x96a418,
  9=0x9a7a4c, 10=0x96be1c. Slot bodies unrecovered.
- Factory 0x964d98 region (pool alloc 0xe78 -> C1 0x96929c -> 0x9a7ccc).
