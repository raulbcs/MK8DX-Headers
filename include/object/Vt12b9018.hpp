#pragma once

#include <cstdint>

// Vt12b9018 - PLACEHOLDER name (agl/gl resource-handler entry keyed by the file
// extension "aglenv", rodata 0xef903e; resource-type id 0x24 (36)).
// 0x50-byte object built inline in the resource registry factory
// FUN_71006ceab0.
// extent 0x50 - details: doc/object/Vt12b9018.md

namespace object {
class Vt12b9018 {
 public:
  void* vtable;            // 0x00 - installed 12b9018 (row itself; vt-0x10 and
                           //        vt-8 are zero, no typeinfo; adrp/add
                           //        materialized, no GOT cell)
  void* mManager_08;       // 0x08 - registry/manager ptr (x22 in factory)
  uint32_t mId_10;         // 0x10 - resource-type id 0x24 (36)
  char mPad14[4];          // 0x14 - alignment padding
  void* mEntry_18;         // 0x18 - manager table entry (x25 + idx*0x38,
                           //        clamped by count; stride 0x240)
  void* mSelf_20;          // 0x20 - this+0x20 (twice)
  void* mSelf_28;          // 0x28
  uint64_t mZero_30;       // 0x30 - zeroed
  uint64_t mZero_38;       // 0x38 - zeroed
  uint32_t mIndex_40;      // 0x40 - table slot index 0x27 (39)
  uint32_t mExtHash_44;    // 0x44 - hash("aglenv") via FUN_710062fd48
  uint32_t mEntryHash_48;  // 0x48 - hash(entry+0x10 string) via
                           //        FUN_710062fd48
  char mPad4C[4];          // 0x4c - padding to alloc size 0x50
};
}  // namespace object
