# BandwidthCheckProtocol (nn::pia::transport::BandwidthCheckProtocol)

- vptr 0x12debb8 = first slot row; offset-to-top 0 at 0x12deba8 (= GOT cell
  0x1313ac0 addend), typeinfo 0x12dec10 at 0x12debb0
  ("N2nn3pia9transport22BandwidthCheckProtocolE"). GOT cell 0x1313ac0 holds
  vptr-0x10.
- Size 0xe0, proven by the creation site at 0x986854: pool allocation
  0x9a7c5c with size 0xe0 (0x986854-0x98685c) then C1 0x9a0f24 (0x986864),
  registered via 0x9a7ccc; result stored at [x20, #0x98].

## Identity

pia transport bandwidth-check protocol; abstract-protocol-base derived (base
C1 0x9a79c8, base D1 0x9a79f0), created by the same aggregated setup function
as the session Mesh/Session/SyncClock protocols (creation sites
0x98679c/0x9977a0/0x986804/0x986854).

## Member notes

- +0xb0: member subobject initialized by helper 0x92a1e0 (0x9a0f50-0x9a0f70);
  its D1 0x92a1dc is invoked by the creation-site cleanup paths
  (0x923650/0x92508c pattern).
- D1 0x9a0f84 also touches global cell 0x1312438 (0x9a0f98) after the vptr
  swap (purpose unverified).

## Construction / init order

- C1 = 0x9a0f24: base C1 0x9a79c8 (0x9a0f34), +0x28 byte zeroed, vptr swap
  from cell 0x1313ac0 (0x9a0f3c-0x9a0f58), zero stores +0x2c..+0xa0,
  subobject ctor 0x92a1e0 at +0xb0, +0xd0 zeroed.
- D1 = slot 0, 0x9a0f84 (vptr swap 0x9a0f8c-0x9a0fa8, subobject teardown at
  +0xb8 region, tail into base path). D0 = slot 1, 0x9a0fcc (base D1, then
  operator delete).
- Slots (11): 0=0x9a0f84 (D1), 1=0x9a0fcc (D0), 2=0x9a2258 (4-byte stub),
  3=0x9a225c, 4=0x9a7a2c (`str wzr,[x8]; ret`), 5=0x9a1158, 6=0x9a7a3c
  (`ret`), 7=0x9a1164, 8=0x9a1484, 9=0x9a213c, 10=0x9a7a54 (`orr w0,wzr,#1`).
  Slots 3/5/7/9 absent from functions.csv (unrecovered).
