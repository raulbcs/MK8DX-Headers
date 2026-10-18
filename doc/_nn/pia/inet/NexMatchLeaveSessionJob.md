# nn::pia::inet::NexMatchLeaveSessionJob

RTTI-named. typeinfo object 0x12db150 (name string 0xf7f820,
"N2nn3pia4inet23NexMatchLeaveSessionJobE", base typeinfo 0x12ddf40 =
nn::pia::session::LeaveSessionJob). size 0x140, proven by the factory
0x931bec: `mov w0, #0x140`; alloc via the pia wrapper 0x568aa0 (0x931c00);
ctor 0x94de24 (0x931c14).

- vptr 0x12db0c8 installed at +0x00 by ctor 0x710094de24 (GOT cell 0x1313010
  holds 0x12db0b8 = vt-0x10; offset-to-top 0 at 0x12db0b8, typeinfo at
  0x12db0c0). 17 slots ending at the typeinfo object (0x12db0c8..0x12db150).
- Base: nn::pia::session::LeaveSessionJob — base ctor 0x985060 (also reached
  from 0x977db4 and 0x9d2808), dtor body 0x9850a4.

## Member notes

- +0x08..+0x97 — LeaveSessionJob base region (unproven here).
- [this+0x98] — 16 u32 slots zeroed by the ctor (w-stride-8 loop,
  0x94de58-0x94de74).
- [this+0x118] — byte zeroed by the ctor; written with the bool result of
  slot6 (0x94deac), which calls [cell 0x13123e0]+0xb8 through 0x99ea44 with
  this+0x98.
- [this+0x119] — byte array (0x20 stride-2 zero loop in the ctor); slot6
  re-zeroes [+0x119 .. +0x119+count) with the same count (unroll-by-4).

## Construction / init order

- C2 = 0x710094de24: base ctor 0x985060, install vptr at +0x00, zero
  +0x98..+0x118 and +0x119 array, +0x118 = 0.
- D1 = 0x710094de84 (slot 0, tail-calls dtor body 0x9850a4); D0 =
  0x710094de88 (slot 1, body + operator delete).
- Factory: 0x931bec (new 0x140 + C2); additional vtable-install sites
  0x96fb20, 0x97f1e0, 0x98be6c, 0x9b834c, 0x9b9714, 0x9b9734 (in-place /
  clone-path constructions).
- Slot map (0x12db0c8): s0 0x94de84 (D1), s1 0x94de88 (D0), s2 0xb4a654,
  s3 0xb4a67c, s4 0x933314 (FUN_71009332bc+0x58), s5 0x94e9e0, s6 0x94deac,
  s7 0x985844 (inside the LeaveSessionJob::SendMonitoringData region),
  s8-s16 0x94e898/0x94e8f8/0x94e93c/0x94e980/0x94e87c/0x94e8b4/0x94e9a4/
  0x94e9e4/0x94e9ac — 8-byte unrecovered stubs in config/functions.csv.
