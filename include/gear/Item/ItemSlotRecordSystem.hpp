#pragma once

#include <cstdint>

namespace gear {
// Item-slot record system (0x5dbf48..0x79b854 cluster).

// Item-slot record built by FUN_710079aee0 (0x710079aee0) — extent 0x78,
// PROVADO via FUN_710060b234(0x78, arena, 8) zeroed at step 2.
// Counts are the 8-byte count headers FUN_710060b3fc(count*0x28 + 8, ...).
struct ItemSlotRecord {
    uint32_t count0;          // 0x00 sized stage->[0x1c]
    uint8_t pad_04[4];        // unproven count-header tail
    void* data0;              // 0x08 0x28-byte entries, default {0, u8 1, 0, 0, 0xffff}
    uint32_t count1;          // 0x10 sized stage->[0x24]
    uint8_t pad_14[4];        // unproven count-header tail
    void* data1;              // 0x18 0x28-byte entries
    uint32_t count2;          // 0x20 sized stage->[0x28]
    uint8_t pad_24[4];        // unproven count-header tail
    void* data2;              // 0x28 0x28-byte entries
    uint32_t auxCount;        // 0x30
    uint8_t pad_34[4];        // unproven
    void* auxSlots;           // 0x38 auxCount slots, 8B each (FUN_71007a3f20 targets)
    uint32_t snapshotCount;   // 0x40
    uint8_t pad_44[4];        // unproven
    void* snapshotSlots;      // 0x48 snapshot-count slots, 8B each
    uint32_t slotCount;       // 0x50 <- mgr->[0x3c] (FUN_710079bdec), only when >= 1
    uint8_t pad_54[4];        // unproven
    void* slotData;           // 0x58 slotCount slots (FUN_71007a5484 targets)
    void* extra0x20;          // 0x60 0x20-byte alloc, only when stage->[0x28] != 0 (FUN_71007a4a84)
    uint32_t listCount;       // 0x68 growable list
    uint32_t listCap;         // 0x6c = stage->[0x14] + stage->[0x20] + 1 (FUN_710060b930)
    void* listData;           // 0x70 appended from the arrays above
};
static_assert(sizeof(ItemSlotRecord) == 0x78);

// FUN_710079ca24 (0x710079ca24) — two-phase item-slot (re)assignment on the
// holder; writes an ItemSlotRecord into this+0x78 via FUN_710079aee0.
// FUN_71005dbf48 (0x71005dbf48, gap-split) — reassignment pass on a manager;
// record resolved from [this+0x228]+0x90 table, gate byte [rec+0x9].
// FUN_71005dc950 (0x71005dc950, gap-split) — string-keyed insert; node alloc
// 0x418 via [[this+0x230]]+0x10, name memcpy at node+8.
// FUN_710079edb4 (0x710079edb4, 78 bytes) — pending-entries predicate over
// [slot+0x50]+4 entries.
// FUN_71006c5598 (0x71006c5598, gap-split) — item-slot activation; entry =
// [this+0xd10] + idx*0xb80, arm = [target+0x10] + idx*0x3d68 (arm+0x5d8).
// NOTE: class ownership unproven beyond the offsets cited above.
}  // namespace gear
