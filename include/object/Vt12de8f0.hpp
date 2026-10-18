#pragma once

#include <cstdint>

// Vt12de8f0 — PLACEHOLDER name; 5-slot packet-like row (installed vptr
// 0x12de8f8), stack-constructed; slot4 returns payload size 0x10.
// extent 0x18 - details: doc/object/Vt12de8f0.md

namespace object {
class Vt12de8f0 {
 public:
  void* mVtable;      // 0x00 — 0x12de8f8 (GOT cell 0x1313a30 holds 0x12de8e8 = row-0x8)
  uint64_t mPayload;  // 0x08 — serialized byte-wise by slot 0x99f3d0
  uint32_t mField10;  // 0x10 — filled by slot 0x99f0ec (parse/build)
  uint8_t mPad14[0x4];   // 0x14 — pad to 0x18 footprint (unverified contents)
};
}  // namespace object
