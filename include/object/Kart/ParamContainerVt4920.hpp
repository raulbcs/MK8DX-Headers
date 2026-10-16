#pragma once

#include <cstdint>

namespace object {
// ParamContainerVt4920 — address-anchored name (vptr 0x12f4920, GOT cell
class ParamContainerVt4920 {
 public:
  void* vtable;            // 0x00
  uint8_t mPad8[0x28];     // 0x8 — unproven gap (pre-secondary-base)
  uint8_t mPad30[0x8];     // 0x30 — secondary hook-band vptr (ctor-written)
  uint8_t mPad38[0xe88];   // 0x38 — array/body region — unproven gap
  uint8_t mPadec0[0x20];   // 0xec0 — ctor-zeroed region (0xec0-0xed8 qword-zeroed)
  uint8_t mPadee0[0x798];  // 0xee0 — unproven gap
  uint8_t mPad1678[0x4];   // 0x1678 — ctor-written (param pass-through)
  uint8_t mPad167c[0x4];   // 0x167c — tail pad
                           // (0x1680 total, factory alloc)
  // extent 0x1680 (factory allocation size 0x1680)
};
}  // namespace object
