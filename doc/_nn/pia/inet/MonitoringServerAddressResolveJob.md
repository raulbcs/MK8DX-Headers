# nn::pia::inet::MonitoringServerAddressResolveJob

Identity: typeinfo-row vtable, assigned address 0x12daa40 (= typeinfo slot,
vptr-8); installed vptr **0x12daa48**. GOT cell 0x1312b78 holds vptr-0x10
(0x12daa30 = offset-to-top 0). Typeinfo data 0x12daa80, name
"N2nn3pia4inet33MonitoringServerAddressResolveJobE", base typeinfo 0x12f8d30
("N2nn3pia6common15StepSequenceJobE"). 6 slots (0x12daa48..0x12daa78).

## Member notes

- Slot0 0x93b38c: D1 — re-installs vptr 0x12daa48 (cell 0x1312b78 + 0x10),
  calls stub 0x929ee0 at this+0x58, then tail `b 0xb4a62c` (base D1).
  Slot1 0x93b3c0: D0, same shape.
- Slot2/3 0xb4a654 / 0xb4a67c and slot4 0x933314: shared pia-job stubs.
  Slot5 0xb4a7a4: `ret`.
- [this+0x08..0x57] — StepSequenceJob base subobject (base C1 0xb4a5e0).
- [+0x58..+0x70] — 0x19-byte subobject inited by 0x929ec0 (ptrs +0x58/+0x60,
  bool +0x68).
- [+0x78] u64, [+0x80] u32, [+0x88] u64 — zeroed by C2 (last store reaches
  +0x8f; size 0x90 lower bound).

## Construction / init order

1. C2 FUN_710093b340 (0x93b340..0x93b388): base C1 0xb4a5e0 (0x93b350),
   vptr install (0x93b354..0x93b368), member init 0x929ec0 at this+0x58
   (0x93b36c), then str xzr [+0x78] / str wzr [+0x80] / str xzr [+0x88],
   tail `b 0x929ed0(this+0x58)`.
2. Constructed in-place as a member at owner+0xa8 of a manager aggregate
   (add x0, x19, #0xa8; bl 0x93b340 at 0x93a9a4). No factory operator new
   found — extent 0x90 is a lower bound from the +0x88 field store.
