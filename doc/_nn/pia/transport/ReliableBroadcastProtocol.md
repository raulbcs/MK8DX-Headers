# ReliableBroadcastProtocol (nn::pia::transport::ReliableBroadcastProtocol)

- vptr 0x12df168 = first slot row; offset-to-top 0 at 0x12df158 (= GOT cell
  0x1313bf0 addend), typeinfo 0x12df1c0 at 0x12df160
  ("N2nn3pia9transport25ReliableBroadcastProtocolE"). GOT cell 0x1313bf0
  holds vptr-0x10.
- Size 0xb0, proven by the creation sites at 0x923670 and 0x9250ac: pool
  allocation 0x9a7c5c with size 0xb0 (`mov w1, #0xb0`, 0x923670-0x923678 /
  0x9250ac-0x9250b4) then C1 0x9ac784 (0x923680/0x9250bc), registered via
  0x9a7ccc; a u8 at [x21, #0x214] is OR'd into the registration flags
  (0x8400).

## Identity

pia transport reliable-broadcast protocol; abstract-protocol-base derived
(base C1 0x9a79c8, base D1 0x9a79f0). Created from two call sites
(0x923680/0x9250bc) inside separate setup paths, unlike the four protocols
created by the aggregated setup function.

## Member notes

- +0x2c u32 = 0x10000 (64 KiB, likely max broadcast payload), +0x30 u32 =
  0xfd (shared protocol constant), +0x40 u16 = 0x1a (26).
- +0xa0: pointer zeroed by C1 (0x9ac7c8); D1 slot 0x9ac7e4 frees it
  (0x568bb0/0x568b64 delete pair, 0x9ac808-0x9ac818) when non-null.

## Construction / init order

- C1 = 0x9ac784: base C1 0x9a79c8 (0x9ac794), +0x28 = 0 / +0x2c = 0x10000
  (stp, 0x9ac79c), +0x30 = 0xfd, +0x40 = 0x1a, vptr swap from cell 0x1313bf0
  (0x9ac7b0-0x9ac7cc), zero stores +0x50/+0x70/+0x78/+0x7c/+0x90, +0xa0
  stp xzr.
- D1 = slot 0, 0x9ac7e4 (vptr swap, frees +0xa0 when non-null). D0 = slot 1,
  0x9ac898 (base D1, then operator delete).
- Slots (11): 0=0x9ac7e4 (D1), 1=0x9ac898 (D0), 2=0x9ae058 (4-byte stub),
  3=0x9aeca0, 4=0x9aca84, 5=0x9a7a34 (shared stub), 6=0x9acba0, 7=0x9a7a40
  (shared stub), 8=0x9acc30 (860-byte body), 9=0x9adee8, 10=0x9a7a54
  (`orr w0,wzr,#1`). Slots 3/4/6/9 absent from functions.csv (unrecovered).
