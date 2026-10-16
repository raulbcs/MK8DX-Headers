#pragma once

#include <cstdint>

namespace object {
// ParamNodeVt25f0 — address-anchored name (vptr 0x12b25f0, GOT cell
class ParamNodeVt25f0 {
 public:
  void* vtable;          // 0x00
  uint32_t mField8;      // 0x8 — ctor: call result
  uint8_t mPadc[0x4];    // 0xc — unproven gap
  uint64_t mZero10;      // 0x10 — ctor zero
  uint8_t mPad18[0x18];  // 0x18 — unproven gap
  char mChan30[0x20];    // 0x30 — recorder channel-pair member
                         // (0x50 total)
  // extent 0x50 (in-place node partition: stur [elem-0x50] at site 0x64a88c)
};
}  // namespace object
