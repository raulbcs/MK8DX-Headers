#pragma once

#include <math/seadVector.h>

#include <cstdint>

#include "KartVehicleControl.hpp"

namespace object {
// Size 0x90: operator new(0x90) in the KartVehicle ctor (0x71001701b4,
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
  uint8_t mPad70[0x14];   // 0x70  // unproven
  // Full 3-float Vector3f: copied as a unit from the owner's KartVehicleMove
  // subobject (owner = [this+0x10], Move = [owner+0x28]; sources Move+0x308/
  // +0x30C/+0x310) by 0x710017a000, which stores all three words together
  // (0x710017a01c..0x710017a02c). Ctor 0x7100179f5c pre-zeroes only x/y via
  // the stp at 0x7100179f94 (z is left for the copy). Unit-length or exact
  // drive-direction semantics not proven — neutral name.
  sead::Vector3f mMoveVector;  // 0x84
};
}  // namespace object
