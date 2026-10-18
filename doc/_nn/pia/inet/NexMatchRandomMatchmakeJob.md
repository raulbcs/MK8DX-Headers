# nn::pia::inet::NexMatchRandomMatchmakeJob

## Identity

RTTI typeinfo `N2nn3pia4inet26NexMatchRandomMatchmakeJobE` (name string 0xf7f9f0, typeinfo object 0x12db370, meta 0x12de3a0). Typeinfo-row vtable variant: assigned row 0x12db2d0, real vptr = assigned+8 = **0x12db2d8**, 18 slots (0x12db2d8..0x12db368). GOT cell 0x1313080 holds vptr-0x10 (0x12db2c8); two further code references hit the same cell at 0x9b8d5c/0x9b8d98 (secondary install/read sites, unrecovered functions).

size 0x170 — proven by the sole factory 0x931b38: `mov w0,#0x170; bl 0x568aa0` (0x931b4c-0x931b50), then ctor.

## Member notes

- slot14 (0x952994) is named `RandomMatchmakeJob::CompleteProcess` in functions.csv.
- Slots 2/3/4 (0xb4a654/0xb4a67c/0x933314) shared across all four mapped pia matchmake jobs; slot7 (0x953688) shared with nn::pia::lan::LanMatchRandomMatchmakeJob.
- Base ctor family 0x9957dc / dtor base 0x99582c is shared with LanMatchRandomMatchmakeJob — same RandomMatchmakeJob base as the lan twin.
- Ctor zeroes +0x120 qword, +0x130..+0x13f, +0x140 qword, byte +0x15d, +0x160 qword (0x951730-0x951750).
- Remaining slots unrecovered in functions.csv.

## Construction / init order

- Factory 0x931b38: heap = 0x563b70(); obj = 0x568aa0(0x170, heap); ctor(obj); return obj.
- Ctor 0x95171c: base ctor 0x9957dc(this); zero [this+0x120]; zero [this+0x130..+0x13f]; install vptr 0x12db2d8 (cell 0x1313080+0x10) at [this]; zero [this+0x140]; byte [this+0x15d] = 0; zero [this+0x160].
