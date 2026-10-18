# nn::pia::inet::NexNatServerAddressResolveJob

Identity: typeinfo-row vtable, assigned address 0x12d9bc0 (= typeinfo slot,
vptr-8); installed vptr **0x12d9bc8**. GOT cell 0x13128f0 holds vptr-0x10
(0x12d9bb0 = offset-to-top 0). Typeinfo data 0x12d9c00, name
"N2nn3pia4inet29NexNatServerAddressResolveJobE", base typeinfo 0x12f8d30
("N2nn3pia6common15StepSequenceJobE"). 6 slots (0x12d9bc8..0x12d9bf8).

## Member notes

- Slot0 0x930f50: D1, tail `b 0xb4a62c` (base D1). Slot1 0x930f54: D0.
- Slot2/3 0xb4a654 / 0xb4a67c: shared pia-job stubs (see
  doc/_nn/pia/session/BrowseMatchmakeJob.md). Slot5 0xb4a7a4: `ret`.
- Slot4 0x9310e0: reads [+0x58]; when non-null checks [*x0] == 1 and
  releases — the same +0x58/+0x60 subobject-pair pattern as
  NatDetectionJob slot4 0x966d14.
- [this+0x08..0x57] — StepSequenceJob base subobject built by base C1
  0xb4a5e0 (base D1 0xb4a62c).
- [+0x58]/[+0x60] pointers and [+0x68] u32, all zeroed by C2; the +0x58
  subobject is the 0x19-byte struct inited by 0x929ec0 elsewhere in the
  family.

## Construction / init order

1. C2 FUN_7100930f18 (0x930f18..0x930f4c): base C1 0xb4a5e0 first
   (0x930f28), then stp xzr,xzr [+0x58], str wzr [+0x68], then vptr
   0x12d9bc8 = cell 0x13128f0 + 0x10 (0x930f2c..0x930f40).
2. Factory at 0x92ce38..0x92ce5c: `orr w0, wzr, #0x70`; operator new
   0x568aa0 (0x92ce48); C2 0x930f18; result stored [x20+0x138] in a
   manager aggregate — size 0x70 EXACT.
