#pragma once

#include <cstdint>

namespace object {
// ParamNodeVtde48 — address-anchored name (vptr 0x12bde48, cell 0x130e920, n=27, site 0x6e66a4, ctor 0x6e6644).
class ParamNodeVtde48 {
 public:
  void* vtable;          // 0x00
  uint8_t mPad8[0x54c];  // 0x8 — unproven gap
  uint32_t mField554;    // 0x554
};
}  // namespace object
