# nn::pia::inet::NexMatchJoinSessionJob

## Identity

RTTI typeinfo `N2nn3pia4inet22NexMatchJoinSessionJobE` (name string 0xf7f350, typeinfo object 0x12dafb0, meta 0x12ddc70). Typeinfo-row vtable variant: assigned row 0x12daf10 holds [&typeinfo] at +0 and offset-to-top 0 at assigned-8 (0x12daf08); the real vptr is assigned+8 = **0x12daf18**, 18 slots (0x12daf18..0x12dafa8). GOT cell 0x1312d60 holds vptr-0x10 (0x12daf08); every install site computes cell+0x10.

size 0x160 — proven by the sole factory 0x931bb0: `bl 0x563b70` (heap), `mov w0,#0x160; bl 0x568aa0` (0x931bc4-0x931bc8), then ctor.

## Member notes

- Slots 2/3/4 (0xb4a654/0xb4a67c/0x933314) are shared across all four mapped pia matchmake jobs; slots 8/9/10 (0x983158/0x983180/0x9831a4) are shared with nn::pia::lan::LanMatchJoinSessionJob.
- slot0 0x93f46c: `b 0x98242c` (complete-dtor tail); slot1 0x93f470: tail-calls 0x98242c then `operator delete` (0x60b470) — deleting dtor.
- 0x120 qword and 0x128-0x12f block zeroed by ctor; 0x150 qword zeroed (0x93f44c-0x93f45c).
- Slots 0x9407xx-0x940bc8 and 0x9411xx are unrecovered in functions.csv; only slot identities above are documented.

## Construction / init order

- Factory 0x931bb0: heap = 0x563b70(); obj = 0x568aa0(0x160, heap); ctor(obj); return obj.
- Ctor 0x93f430: base ctor 0x9823d8(this); zero [this+0x120]; zero [this+0x128..+0x12f]; install vptr 0x12daf18 (cell 0x1312d60+0x10) at [this]; zero [this+0x150].
