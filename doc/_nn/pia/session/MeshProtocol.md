# MeshProtocol (nn::pia::session::MeshProtocol)

- vptr 0x12de0b8 = first slot row; offset-to-top 0 at 0x12de0a8 (= GOT cell
  0x13138c8 addend), typeinfo 0x12de110 at 0x12de0b0
  ("N2nn3pia7session12MeshProtocolE"). GOT cell 0x13138c8 holds vptr-0x10.
- Size 0xa0, proven by the creation site at 0x98679c: pool allocation
  0x9a7c5c with size 0xa0 (0x98679c-0x9867a4) then C1 0x98b888 (0x9867ac),
  result registered via 0x9a7ccc (mesh protocol descriptor path).

## Identity

pia session mesh protocol; one of the protocol classes derived from the
abstract pia protocol base (base C1 0x9a79c8, base D1 0x9a79f0 = `ret`;
cf. nn::pia::inet::MonitoringDataProtocol). Created alongside
SessionProtocol/SyncClockProtocol/BandwidthCheckProtocol by the same
aggregated setup function (creation sites 0x98679c/0x9977a0/0x986804/
0x986854). C1 tail loads a global via cell 0x13138d0 and calls logging
helpers 0x5677bc/0x568a18 with strings at 0xf122648/0xf12266d.

## Member notes

- +0x48 u32 = 10000, +0x4c u32 = 5000 (timeout/interval pair, 0x98b8b0-
  0x98b8dc); remaining fields zero-initialized (see header).

## Construction / init order

- C1 = 0x98b888: base C1 0x9a79c8 (0x98b898), vptr swap from cell 0x13138c8
  (0x98b89c-0x98b8b8), then zero stores +0x28..+0x98 and the 0x2710/0x1388
  pair at +0x48 (ascending).
- D1 = slot 0, 0x98b93c (tail `b` to base D1 0x9a79f0). D0 = slot 1,
  0x98b940 (base D1, then operator delete 0x60b470).
- Slots (11): 0=0x98b93c (D1), 1=0x98b940 (D0), 2=0x98fc90 (4-byte stub),
  3=0x98fc94, 4=0x98fc9c, 5=0x9a7a34 (shared stub), 6=0x9a7a3c (`ret`),
  7=0x9a7a40 (shared stub), 8=0x98bea8 (3172-byte body, main protocol
  handler), 9=0x98bd08, 10=0x9a7a54 (`orr w0,wzr,#1`). Slots 3/4/9 absent
  from functions.csv (unrecovered).
