# nn::pia::nat::NatDetectionJob

Identity: typeinfo-row vtable, assigned address 0x12dbb80 (= typeinfo slot,
vptr-8); installed vptr **0x12dbb88**. GOT cell 0x1313248 holds vptr-0x10
(0x12dbb70 = offset-to-top 0). Typeinfo data 0x12dbbc0, name
"N2nn3pia3nat15NatDetectionJobE", base typeinfo 0x12f8d30
("N2nn3pia6common15StepSequenceJobE"). 6 slots (0x12dbb88..0x12dbbb8).

## Member notes

- Slot0 0x966bc0: D1, tail `b 0xb4a62c` (base D1). Slot1 0x966bc4: D0.
- Slot2/3 0xb4a654 / 0xb4a67c: shared pia-job stubs. Slot5 0xb4a7a4: `ret`.
- Slot4 0x966d14: reads [+0x58]; when non-null and [*x0] == 1 calls
  0x929f78, then continues with [+0x60] — subobject release pair.
- [this+0x08..0x57] — StepSequenceJob base subobject (base C1 0xb4a5e0).
- [+0x58]/[+0x60] subobject pointers (0x929ec0-shaped 0x19-byte struct
  zeroed inline by C2), [+0x70..+0x7f] and [+0x88] zeroed by C2 (last
  store reaches +0x8f).

## Construction / init order

1. C2 FUN_7100966b84 (0x966b84..0x966bc0): base C1 0xb4a5e0 (0x966b94),
   [+0x60] = 0, stp xzr,xzr [+0x70], [+0x88] = 0, vptr 0x12dbb88 = cell
   0x1313248 + 0x10 (0x966b98..0x966bac).
2. Only entry found is a tail-branch `b 0x966b84` at 0x966168 — the tail
   of a large aggregate ctor that builds the job in place as a member.
   No factory operator new found; extent 0x90 is a lower bound from the
   +0x88 field store.
