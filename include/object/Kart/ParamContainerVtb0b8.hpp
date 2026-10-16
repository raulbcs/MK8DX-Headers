#pragma once

#include <cstdint>

namespace object {
// ParamContainerVtb0b8 — address-anchored name (vptr 0x12bb0b8, GOT cell
class ParamContainerVtb0b8 {
 public:
  void* vtable;           // 0x00
  uint8_t mPad8[0x28];    // 0x8 — unproven gap (pre-secondary-base)
  uint8_t mPad30[0x8];    // 0x30 — secondary hook-band vptr (ctor-written)
  uint8_t mPad38[0x228];  // 0x38 — array/body region — unproven gap
  uint8_t mPad260[0x8];   // 0x260 — ctor-zeroed pair (0x260/0x268)
  uint8_t mPad268[0x4];   // 0x268 — unproven gap
  uint8_t mPad26c[0x4];   // 0x26c — unproven gap
  uint8_t mPad270[0x4];   // 0x270 — ctor-zero (param)
  uint8_t mPad274[0x4];   // 0x274 — ctor-written (param w22)
  uint8_t mPad278[0x78];  // 0x278 — unproven gap
                          // (0x2f0 total, factory alloc)
  // extent 0x2f0 (prior-survey total 0x2f0)
};
}  // namespace object
