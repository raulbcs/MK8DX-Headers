# nn::pia::inet::NexMatchJointSessionJob

## Identity

- RTTI: typeinfo at 0x12dafd0+0 (slot row holds typeinfo ptr 0x12db0a0-family layout; name string "N2nn3pia4inet23NexMatchJointSessionJobE"), base nn::pia::session::JointSessionJob.
- Row layout (this family): assigned address 0x12dafd0 is the typeinfo slot; installed vptr = 0x12dafd8 (assigned+8), offset-to-top 0 at 0x12dafd0-8.
- GOT cell 0x1312e00 holds 0x12dafc8 (vptr-0x10); all ctor/dtor blocks materialize `ldr [cell]; add #0x10; str [this]`.
- 23 recovered slots (0x12dafd8..0x12daf88); the next word 0x12daf90 reads 0x94dd78 (typeinfo-vptr of the neighboring typeinfo, not a slot).

## Slots (config/functions.csv)

- slot0 0x941218 (D1), slot1 0x941250 (D0) — unrecovered.
- slots 2-4: 0xb4a654 (40B), 0xb4a67c (108B), FUN_71009332bc (92B) — shared across the JointSessionJob family (same trio in LanMatchJointSessionJob).
- slots 5/6: 0x94de20/0x94de18 (unrecovered; CallSessionEvent-style pair by slot symmetry with the LAN sibling).
- slots 7/8: 0x983454 (268B), 0x983560 (148B) — shared family.
- slots 9-22: 0x941290..0x942e04, unrecovered.

## Member notes

- 0x118: JointSessionJob base subobject (ctor 0x9b1fe8 / D2 0x9b20b4, same cells as the LAN sibling).
- 0x190..0x1ff zeroed by ctor (8x stp xzr,xzr).
- 0x236 = 1, 0x2b8 = 0, 0x2ba..0x2d9 zeroed by an unroll-4 loop (cmp x8,#0x20).

## Construction / init order

1. Ctor cluster at 0x941190 (unrecovered function): first bl 0x9832e4, then vptr store from cell 0x1312e00.
2. Base subobject ctor 0x9b1fe8 at this+0x118.
3. Field init as above. Deleting-dtor blocks 0x941228/0x941260 reinstall the same vptr and chain 0x9b20b4 at +0x118.

Size: no operator-new factory found (no bl-0x941190 callers); extent >= 0x2da is the max field store, unverified.
