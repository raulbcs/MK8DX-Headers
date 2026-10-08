#pragma once

#include <cstdint>

#include "KartVehicleControl.hpp"

namespace object {
// Size 0x90: operator new(0x90) in the KartVehicle ctor (v400 0x71001701b4,
// stored at KartVehicle+0x18; ctor 0x7100179f5c). Evidenced inside the pad:
// +0x74 u64=0, +0x77 u8 and +0x78 u32 reset-zeroed (0x179fe0), +0x7C u8=1,
// +0x80 f32=0.25f.
class KartVehicleCpu : public KartVehicleControl {
 public:
  // Proven sub-offset map of 0x70..0x8F from ctor 0x7100179f5c
  // (base KartVehicleControl ctor 0x179660 covers 0x00..0x6B):
  //   0x06c u64 = 0 (write crosses the base/pad boundary)
  //   0x074 u64 = 0
  //   0x07c u8  = 1
  //   0x080 f32 = 0.25f, 0x084 u32 = 0 (x store pair)
  // Only 0x070..0x073 stays unproven (may be written by base ctor
  // 0x179660); extent from factory alloc 0x90 at 0x71001701b4.
  uint8_t mPad70[0x20];  // proven sub-offset map above (ctor 0x7100179f5c)
};
}  // namespace object
