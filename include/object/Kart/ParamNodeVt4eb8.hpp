#pragma once

#include <cstdint>

namespace object {
// ParamNodeVt4eb8 — address-anchored name (vptr 0x12b4eb8, GOT cell
class ParamNodeVt4eb8 {
 public:
  void* vtable;          // 0x00
  uint32_t mField8;      // 0x8 — ctor: call result
  uint8_t mPadc[0x4];    // 0xc — unproven gap
  uint64_t mZero10;      // 0x10 — ctor zero
  uint8_t mPad18[0x18];  // 0x18 — unproven gap
  char mChan30[0x20];    // 0x30 — recorder channel-pair member
                         // (0x50 total)
  // extent 0x50 (in-place node partition: next node's vptr stored at +0x50 — construction site 0x6850cc)
};
}  // namespace object
