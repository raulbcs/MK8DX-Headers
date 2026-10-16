#pragma once

#include <cstdint>

namespace gear {
// Item-slot record system (0x5dbf48..0x79b854 cluster). Record extent 0x78
// (builder FUN_710079aee0; zeroed via FUN_710060b234(0x78, arena, 8)); counts
// are 8-byte count headers FUN_710060b3fc(count*0x28 + 8, ...).
// Details: doc/gear/Item/ItemSlotRecordSystem.md
struct ItemSlotRecord {
  uint32_t count0;         // 0x00 sized stage->[0x1c]
  uint8_t pad_04[4];       // 0x04 — unproven count-header tail
  void* data0;             // 0x08 0x28-byte entries, default {0, u8 1, 0, 0, 0xffff}
  uint32_t count1;         // 0x10 sized stage->[0x24]
  uint8_t pad_14[4];       // 0x14 — unproven count-header tail
  void* data1;             // 0x18 0x28-byte entries
  uint32_t count2;         // 0x20 sized stage->[0x28]
  uint8_t pad_24[4];       // 0x24 — unproven count-header tail
  void* data2;             // 0x28 0x28-byte entries
  uint32_t auxCount;       // 0x30
  uint8_t pad_34[4];       // unproven
  void* auxSlots;          // 0x38 auxCount slots, 8B each (FUN_71007a3f20 targets)
  uint32_t snapshotCount;  // 0x40
  uint8_t pad_44[4];       // unproven
  void* snapshotSlots;     // 0x48 snapshot-count slots, 8B each
  uint32_t slotCount;      // 0x50 <- mgr->[0x3c] (FUN_710079bdec), only when >= 1
  uint8_t pad_54[4];       // unproven
  void* slotData;          // 0x58 slotCount slots (FUN_71007a5484 targets)
  void* extra0x20;         // 0x60 0x20-byte alloc, only when stage->[0x28] != 0 (FUN_71007a4a84)
  uint32_t listCount;      // 0x68 growable list
  uint32_t listCap;        // 0x6c = stage->[0x14] + stage->[0x20] + 1 (FUN_710060b930)
  void* listData;          // 0x70 appended from the arrays above
};
static_assert(sizeof(ItemSlotRecord) == 0x78);

// FUN_710079ca24 — two-phase item-slot (re)assignment; writes an ItemSlotRecord
// into this+0x78 via FUN_710079aee0. Related fns 0x5dbf48/0x5dc950/0x79edb4/
// 0x6c5598 — see doc/gear/Item/ItemSlotRecordSystem.md. Class ownership
// unproven beyond the offsets cited above.
}  // namespace gear
