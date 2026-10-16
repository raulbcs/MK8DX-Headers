# ItemSlotRecordSystem (gear::ItemSlotRecord)

Item-slot record system (0x5dbf48..0x79b854 cluster).

Item-slot record built by FUN_710079aee0 (0x710079aee0) — extent 0x78, proven via FUN_710060b234(0x78, arena, 8) zeroed at step 2. Counts are the 8-byte count headers FUN_710060b3fc(count*0x28 + 8, ...).

## Fields

- 0x00 count0 — sized stage->[0x1c]; 0x04 unproven count-header tail.
- 0x08 data0 — 0x28-byte entries, default {0, u8 1, 0, 0, 0xffff}.
- 0x10 count1 — sized stage->[0x24]; 0x14 unproven count-header tail.
- 0x18 data1 — 0x28-byte entries.
- 0x20 count2 — sized stage->[0x28]; 0x24 unproven count-header tail.
- 0x28 data2 — 0x28-byte entries.
- 0x30 auxCount; 0x34 unproven.
- 0x38 auxSlots — auxCount slots, 8B each (FUN_71007a3f20 targets).
- 0x40 snapshotCount; 0x44 unproven.
- 0x48 snapshotSlots — snapshot-count slots, 8B each.
- 0x50 slotCount — <- mgr->[0x3c] (FUN_710079bdec), only when >= 1; 0x54 unproven.
- 0x58 slotData — slotCount slots (FUN_71007a5484 targets).
- 0x60 extra0x20 — 0x20-byte alloc, only when stage->[0x28] != 0 (FUN_71007a4a84).
- 0x68 listCount — growable list; 0x6c listCap = stage->[0x14] + stage->[0x20] + 1 (FUN_710060b930).
- 0x70 listData — appended from the arrays above.

sizeof(ItemSlotRecord) == 0x78.

## Function cluster

- FUN_710079ca24 (0x710079ca24) — two-phase item-slot (re)assignment on the holder; writes an ItemSlotRecord into this+0x78 via FUN_710079aee0.
- FUN_71005dbf48 (0x71005dbf48, gap-split) — reassignment pass on a manager; record resolved from [this+0x228]+0x90 table, gate byte [rec+0x9].
- FUN_71005dc950 (0x71005dc950, gap-split) — string-keyed insert; node alloc 0x418 via [[this+0x230]]+0x10, name memcpy at node+8.
- FUN_710079edb4 (0x710079edb4, 78 bytes) — pending-entries predicate over [slot+0x50]+4 entries.
- FUN_71006c5598 (0x71006c5598, gap-split) — item-slot activation; entry = [this+0xd10] + idx*0xb80, arm = [target+0x10] + idx*0x3d68 (arm+0x5d8).

NOTE: class ownership unproven beyond the offsets cited above.
