#pragma once

#include <cstdint>

namespace object {
// ParamNodeVt47a0 — address-anchored name (vptr 0x12f47a0, cell 0x13154e8, n=38, site 0xaf25b8, ctor 0xaf259c, alloc UNPROVEN — cite refuted by ctor stores reaching 0xEB4).
class ParamNodeVt47a0 {
 public:
  void* vtable;           // 0x00
  uint8_t mPad8[0x28];    // 0x8 — unproven gap
  uint64_t mField30;      // 0x30
  uint8_t mPad38[0xe58];  // 0x38 — unproven gap
  uint64_t mZeroe90;      // 0xe90 — ctor zero
  uint64_t mZeroe98;      // 0xe98 — ctor zero
  uint64_t mZeroea0;      // 0xea0 — ctor zero
  uint64_t mZeroea8;      // 0xea8 — ctor zero
  uint32_t mZeroeb0;      // 0xeb0 — ctor zero
};
}  // namespace object
