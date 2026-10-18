# LeaveSessionJob (nn::pia::session::LeaveSessionJob)

- vptr 0x12ddeb8 = first slot row; offset-to-top 0 at 0x12ddea8 (= GOT cell
  0x13137f0 addend), typeinfo 0x12ddf40 at 0x12ddeb0
  ("N2nn3pia7session15LeaveSessionJobE"). GOT cell 0x13137f0 holds vptr-0x10.
- Size >= 0x98 (lower bound): C1 0x985060 stores up to +0x90 (0x985094) and no
  factory `operator new` call site was found — the three C1 callers are
  derived-class C1s (below), unverified beyond 0x98.

## Identity

pia session job that leaves a session; same job-framework family as
JoinMeshJob (vt 0x12ddb58): shares job-base slots 0xb4a654/0xb4a67c and the
0x20-byte subobject ctor 0x929ec0. Derived C1s calling base C1 0x985060:
0x94de24 (adds +0x118 flag + u16[0x20] zero loop at +0x11a, vptr cell
0x1313010), 0x977da4 (vptr cell 0x13135c0), 0x9d27f4 (stores arg at +0x98,
vptr cell 0x1314508). functions.csv names nearby functions
LeaveWithHostMigrationJob::* — the derived jobs are host-migration leave
variants (unverified which C1 is which).

## Member notes

- +0x60 pointer-sized subobject, 0x20 bytes (ctor 0x929ec0 at 0x98508c;
  released by 0x929ee0 in D1/D0 path).
- +0x80/+0x90 zeroed by C1 (0x985090-0x985094).

## Construction / init order

- C1 = 0x985060: vptr 0x12ddeb8 at [this] (0x985084-0x985088), +0x58 zeroed,
  subobject ctor 0x929ec0 at +0x60, +0x80/+0x90 zeroed.
- D1 = slot 0, 0x9850a4 (vptr swap, subobject D1 0x929ee0, tail `b` to job-base
  D1 0xb4a62c). D0 = slot 1, 0x9850d8 (same, then operator delete 0x60b470).
- Slots (17): 0=0x9850a4 (D1), 1=0x9850d8 (D0), 2=0xb4a654, 3=0xb4a67c (job
  base), 4=0x933314, 5=0x985dd4, 6=0x9854cc, 7=0x985844, 8=0x9858ac,
  9=0x985ac4, 10=0x985ae0, 11=0x985838, 12=0x985d4c, 13=0x977e24,
  14=0x94e9e4, 15=0x985d68. Slots 4-15 absent from functions.csv
  (unrecovered); slot 4 named LeaveSessionJob::WaitForcedTerminatingOfJointSessionJob
  region nearby (0x985114) but exact mapping unverified.
