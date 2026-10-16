#pragma once

#include <cstdint>

namespace object {
// ParamNodeVtaf38 — address-anchored name (vptr 0x12baf38, cell 0x130e4b0, n=38, site 0x6c3918, ctor 0x6c38b8, alloc UNPROVEN — cite refuted by ctor stores reaching 0xD24).
class ParamNodeVtaf38 {
 public:
  void* vtable;            // 0x00
  uint8_t mPad8[0x240];    // 0x8 — unproven gap
  uint64_t mField248;      // 0x248
  uint8_t mPad250[0xaa0];  // 0x250 — unproven gap
  uint64_t mFieldcf0;      // 0xcf0
  uint64_t mFieldcf8;      // 0xcf8
  uint8_t mPadd00[0x8];    // 0xd00 — unproven gap
  uint32_t mFieldd08;      // 0xd08
  uint8_t mPadd0c[0x4];    // 0xd0c — unproven gap
  uint64_t mFieldd10;      // 0xd10
  uint8_t mPadd18[0x8];    // 0xd18 — unproven gap
  uint32_t mFieldd20;      // 0xd20
};
}  // namespace object
