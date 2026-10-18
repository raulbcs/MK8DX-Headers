# nn::pia::session::JointSessionJob

Identity: typeinfo-row vtable, assigned address 0x12ddcf8 (= typeinfo slot,
vptr-8); installed vptr **0x12ddd00**. GOT cell 0x1313798 holds vptr-0x10
(0x12ddcf0 = offset-to-top 0). Typeinfo data 0x12dddc0, name
"N2nn3pia7session15JointSessionJobE", base typeinfo 0x12f8d30
("N2nn3pia6common15StepSequenceJobE"). 21 slots (0x12ddd00..0x12dddb8).

## Member notes

- Slot0 0x983380: D2 — reinstalls own vptr (cell 0x1313798) and releases
  the +0xd8 subobject. Slot1 0x983430: D1 -> D2 -> operator delete.
- Slot2/3 0xb4a654/0xb4a67c: shared StepSequenceJob stubs (slot3 is the
  wait/poll path over +0x30/+0x38). Slot4 0x933314: shared stub.
- Slot5 0x984350: reset — re-runs base C1 0xb4a5e0 on this.
- Slot7 0x983454: progression step; C2 tail-calls it (`br [vptr+0x38]`).
  Slot8 0x983560: reads the +0xd8 subobject pointer.
- Slots 16-19: 0x977d94-0x977da0 `ret` stubs. Slot6 and slots 9-15, 20:
  null (pure/unimplemented).
- [this+0x60..0x77] — member built in place by 0x929ec0 (size unverified).
- [this+0x98]/[this+0xb0] — pointer fields zeroed then passed to 0x56810c.
- [this+0xd8] — subobject pointer released by D2 via slot8-shaped path.
- [this+0xe4..0xef] — packed flag bytes (strh 0xe4, strb 0xe6/0xe8,
  strh 0xea, u32 0xec), all zeroed by C2.

## Construction / init order

1. C2 FUN_71009832e4 (0x9832e4..0x98337c): base C1 0xb4a5e0 (0x9832f4),
   [+0x58] = 0, vptr 0x12ddd00 = cell 0x1313798 + 0x10 (0x9832f8..0x983308),
   in-place member ctor 0x929ec0 at +0x60, then the zero-fill sequence
   listed above; finally tail-calls slot7.
2. Caller 0x94118c uses it as a base ctor and overrides the vptr again with
   cell 0x1312e00 + 0x10 (a further-derived subclass), then constructs a
   member at +0x118 of its own (larger) frame. No dedicated factory
   operator new found; extent 0x110 is a lower bound from the +0x108 store.
