# nn::pia::lan::LanMatchJoinSessionJob

## Identity

RTTI typeinfo `N2nn3pia3lan22LanMatchJoinSessionJobE` (name string 0xf80f00, typeinfo object 0x12dce10, meta 0x12ddc70). Typeinfo-row vtable variant: assigned row 0x12dcd70, real vptr = assigned+8 = **0x12dcd78**, 18 slots (0x12dcd78..0x12dce08). GOT cell 0x1313480 holds vptr-0x10 (0x12dcd68).

size 0x130 — proven by the sole factory 0x96d288: `mov w0,#0x130; bl 0x568aa0` (0x96d29c-0x96d2a0), then ctor.

## Member notes

- slot12 (0x976398) is named `LanMatchJoinSessionJob::JoinMatchmakeSession` in functions.csv.
- Slots 2/3/4 (0xb4a654/0xb4a67c/0x933314) shared across all four mapped pia matchmake jobs; slots 8/9 (0x983158/0x983180) shared with nn::pia::inet::NexMatchJoinSessionJob; slot11 (0x941184) also appears in the inet twin.
- Base ctor 0x9823d8 / dtor base 0x98242c shared with NexMatchJoinSessionJob — same join-job base.
- Ctor zeroes +0x120 qword and +0x128 w32 (0x976354-0x976358).
- Remaining slots unrecovered in functions.csv.

## Construction / init order

- Factory 0x96d288: heap = 0x563b70(); obj = 0x568aa0(0x130, heap); ctor(obj); return obj.
- Ctor 0x976338: base ctor 0x9823d8(this); zero [this+0x120]; w32 [this+0x128] = 0; install vptr 0x12dcd78 (cell 0x1313480+0x10) at [this].
