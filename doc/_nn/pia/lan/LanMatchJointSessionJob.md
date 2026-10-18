# nn::pia::lan::LanMatchJointSessionJob

## Identity

- RTTI: typeinfo 0x12dcf00, name string "N2nn3pia3lan23LanMatchJointSessionJobE" at 0xf80f30; base nn::pia::session::JointSessionJob (typeinfo 0x12dddc0).
- Row layout: 0x12dce30 is the typeinfo slot; installed vptr = 0x12dce38 (assigned+8); GOT cell 0x13134d0 holds 0x12dce28 (vptr-0x10).
- 24 slots (0x12dce38..0x12dcef0).

## Slots (config/functions.csv)

- slot0 0x97702c (D1), slot1 0x977064 (D0) — blocks inside ctor cluster 0x976ff8 (unrecovered, 232B).
- slots 2-4: 0xb4a654 / 0xb4a67c / FUN_71009332bc — JointSessionJob family trio (shared with NexMatchJointSessionJob).
- slots 5-8: 0x977d78/0x977d70 then 0x983454/0x983560.
- slots 9-13: 0x9770a4..0x9770d4 (ICF-folded stubs inside 0x976ff8).
- slots 14-23: all carry the config name "LanMatchJointSessionJob::CallSessionEvent" (0x9770e0/0x977d7c/0x977334/0x977d84..0x977da0/0x977d6c). That name is an ICF fold artifact: functions.csv assigns one representative name per folded group; the CallSessionEvent-sized (3268B) entries are indistinguishable clones.

## Member notes

- 0x118: JointSessionJob base subobject; ctor tail-calls 0x9b1fe8 with this+0x118 (block 0x977020).

## Construction / init order

1. Factory 0x96d378: alloc 0x190 (`mov w0, #0x190; bl 0x568aa0` — pia heap alloc), null-check, `bl 0x976ff8` (ctor).
2. Ctor 0x976ff8 stores vptr from cell 0x13134d0 and tail-calls the base subobject ctor at +0x118.

Size 0x190 proven by the factory allocation.
