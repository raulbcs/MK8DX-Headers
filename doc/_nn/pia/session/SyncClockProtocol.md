# SyncClockProtocol (nn::pia::session::SyncClockProtocol)

- vptr 0x12de878 = first slot row; offset-to-top 0 at 0x12de868 (= GOT cell
  0x1313a28 addend), typeinfo 0x12de8d0 at 0x12de870
  ("N2nn3pia7session17SyncClockProtocolE"). GOT cell 0x1313a28 holds
  vptr-0x10.
- Size 0x80, proven by the creation site at 0x986804: pool allocation
  0x9a7c5c with size 0x80 (0x986804-0x98680c) then C1 0x99eb2c (0x986814),
  registered via 0x9a7ccc (creation site also stores the result pointer at
  [x20, #0x88]).

## Identity

pia session clock-synchronization protocol; abstract-protocol-base derived
(base C1 0x9a79c8, base D1 0x9a79f0), created by the same aggregated setup
function as Mesh/Session/BandwidthCheck protocols (creation sites
0x98679c/0x9977a0/0x986804/0x986854).

## Member notes

- +0x28: 0x10-byte member initialized by helper 0x99eaac (0x99eb4c-0x99eb54).
- +0x38 u32 = 0xfd, +0x3c u32 = 0x7d0 (2000) — version/interval pair
  (0x99eb58-0x99eb60).

## Construction / init order

- C1 = 0x99eb2c: base C1 0x9a79c8 (0x99eb3c), vptr swap from cell 0x1313a28
  (0x99eb40-0x99eb50), subobject helper 0x99eaac at +0x28, then +0x38/+0x3c
  pair and zero stores to +0x40/+0x48/+0x4c.
- D1 = slot 0, 0x99eb7c (tail `b` to base D1 0x9a79f0). D0 = slot 1,
  0x99ebb0 (base D1, then operator delete 0x60b470).
- Slots (11): 0=0x99eb7c (D1), 1=0x99ebb0 (D0), 2=0x99f3cc (4-byte stub),
  3=0x99f474, 4=0x99ebec, 5=0x9a7a34 (shared stub), 6=0x99ec5c, 7=0x9a7a40
  (shared stub), 8=0x99ec6c (404-byte body), 9=0x99f2e0, 10=0x9a7a54
  (`orr w0,wzr,#1`). Slots 3/4/6/9 absent from functions.csv (unrecovered).
