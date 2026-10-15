#pragma once

#include <math/seadVector.h>

#include <gear/Math/Matrix.hpp>

namespace object {
class KartCamera {
 public:
  uint8_t mPad00[0x158];       // 0x00 — unproven padding (fields before
                               //  mUpDir not yet mapped)
  sead::Vector3f mUpDir;       // 0x158
  sead::Vector3f mForwardDir;  // 0x164
  uint8_t mPad170[0x2C];       // 0x170 — unproven padding (to mTilt)
  float mTilt;                 // 0x19C

  void setMatrix(gear::MtxT const& transform);

  // extent 0x1A0 (allocation size 0x1a0 — movz w0,#0x1a0; bl 0x710060afec
  // _Znwm @0x7100cc8b0 → ctor 0x71007ecba0, whose zero-stores walk
  // mUpDir/mForwardDir/pad/mTilt and reach 0x1a0: str wzr [x19,#0x19c]
  // @0x71007eccc0)
};
}  // namespace object
