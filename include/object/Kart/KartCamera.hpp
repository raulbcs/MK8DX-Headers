#pragma once

#include <math/seadVector.h>

#include <gear/Math/Matrix.hpp>

namespace object {
// extent 0x1A0 (cited in doc/object/Kart/KartCamera.md)
class KartCamera {
 public:
  uint8_t mPad00[0x158];       // 0x00 — unproven padding (fields before
  sead::Vector3f mUpDir;       // 0x158
  sead::Vector3f mForwardDir;  // 0x164
  uint8_t mPad170[0x2C];       // 0x170 — unproven padding (to mTilt)
  float mTilt;                 // 0x19C

  void setMatrix(gear::MtxT const& transform);
};
}  // namespace object
