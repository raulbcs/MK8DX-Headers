# nn::pia::lan::LanMatchRandomMatchmakeJob

## Identity

RTTI typeinfo `N2nn3pia3lan26LanMatchRandomMatchmakeJobE` (name string 0xf80fc0, typeinfo object 0x12dd150, meta 0x12de3a0). Typeinfo-row vtable variant: assigned row 0x12dd0b0, real vptr = assigned+8 = **0x12dd0b8**, 18 slots (0x12dd0b8..0x12dd148). GOT cell 0x13135d0 holds vptr-0x10 (0x12dd0a8).

size 0x158 — proven by the sole factory 0x96d210: `mov w0,#0x158; bl 0x568aa0` (0x96d224-0x96d228), then ctor.

## Member notes

- Named slots (functions.csv): slot10 0x978608 `LanMatchRandomMatchmakeJob::RandomMatchmake`; slot14 0x978b74 `LanMatchRandomMatchmakeJob::CompleteFailure`; slot15 0x9789f4 `LanMatchRandomMatchmakeJob::CompleteFailure#2`.
- Slots 2/3/4 (0xb4a654/0xb4a67c/0x933314) shared across all four mapped pia matchmake jobs; slot7 (0x953688) and slot12 (0x996ab8) shared with nn::pia::inet::NexMatchRandomMatchmakeJob.
- Base ctor 0x9957dc / dtor base 0x99582c shared with the inet twin — same RandomMatchmakeJob base.
- +0x120: subobject initialized by member-init call 0x929ec0 (dtor twin 0x929ee0); +0x140..+0x14f zeroed; byte +0x150 = 1 (ctor 0x97857c-0x978580).
- D1 (slot0, 0x978590) and D0 (0x9785c8): re-install vptr (cell 0x13135d0+0x10), run 0x929ee0(this+0x120), then base 0x99582c — D0 adds `operator delete` (0x60b470).
- Remaining slots unrecovered in functions.csv.

## Construction / init order

- Factory 0x96d210: heap = 0x563b70(); obj = 0x568aa0(0x158, heap); ctor(obj); return obj.
- Ctor 0x97854c: base ctor 0x9957dc(this); install vptr 0x12dd0b8 (cell 0x13135d0+0x10) at [this]; member-init 0x929ec0(this+0x120); zero [this+0x140..+0x14f]; byte [this+0x150] = 1.
