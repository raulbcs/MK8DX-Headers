#pragma once

#include <cstdint>

namespace object {
// ParamContainerVtb448 — address-anchored name (vptr 0x12bb448, GOT cell
class ParamContainerVtb448 {
 public:
  void* vtable;            // 0x00
  uint8_t mPad8[0x28];     // 0x8 — unproven gap (pre-secondary-base)
  uint8_t mPad30[0x8];     // 0x30 — secondary hook-band vptr (ctor-written)
  uint8_t mPad38[0x748];   // 0x38 — array/body region — unproven gap
  uint8_t mPad780[0x8];    // 0x780 — ptr — ctor-written
  uint8_t mPad788[0x8c0];  // 0x788 — unproven gap
                           // (0x1048 total, factory alloc)
  // extent 0x1048 (factory allocation size 0x1048)
};
}  // namespace object
