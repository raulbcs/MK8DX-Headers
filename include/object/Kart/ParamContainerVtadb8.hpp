#pragma once

#include <cstdint>

namespace object {
// ParamContainerVtadb8 — address-anchored name (vptr 0x12badb8, GOT cell
class ParamContainerVtadb8 {
 public:
  void* vtable;            // 0x00
  uint8_t mPad8[0x28];     // 0x8 — unproven gap (pre-secondary-base)
  uint8_t mPad30[0x8];     // 0x30 — secondary hook-band vptr (ctor-written)
  uint8_t mPad38[0x1640];  // 0x38 — array/body region — unproven gap
                           // (0x1678 total, factory alloc)
  // extent 0x1678 (factory allocation size 0x1678)
};
}  // namespace object
