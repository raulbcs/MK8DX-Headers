#pragma once

#include <cstdint>

namespace object {
// ParamNodeVt32a8 — address-anchored name (vptr 0x12f32a8, cell 0x13152b8, n=23, site 0x9c633c, ctor 0x9c6310).
class ParamNodeVt32a8 {
 public:
  void* vtable;         // 0x00
  uint8_t mPad8[0x28];  // 0x8 — unproven gap
  uint16_t mField30;    // 0x30
};
}  // namespace object
