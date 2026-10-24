#pragma once

#include <cstdint>
#include <gsys/Model/Model.hpp>

namespace object {
// DriverKart — per-driver model/animation object (KartUnit + 0x10).
// Details: doc/object/Kart/DriverKart.md
class DriverKart {
 public:
  void resetWarpPost();
  void resetWarpPre();

  gsys::Model* mModel;  // 0x30 — with 0x38, ldp pair in resetWarpPost

  // 0x38 — second resource/model-side object: [+0x48] u32 selects one of
  // two slots ([+0x50] / [+0x60]) passed to 0x6a749c/0x6a6770/0x6a617c.
  void* mAnimResource38;  // 0x38

  uint32_t mFlags78;  // 0x78 — bit1 set by resetWarpPre (0xe2508)

  uint8_t mPad7c[0x134];  // 0x7c unproven

  // 0x1b0/0x1b4 — small state pair: when [+0x1b4] == 6, resetWarpPost
  // zeroes [+0x1b0].
  uint32_t mWarpState;      // 0x1b0
  uint32_t mWarpStateKind;  // 0x1b4

  uint8_t mPad1b8[0x17c];  // 0x1b8 unproven

  // 0x334 — warp trigger flag: -1 (all ones) when idle; bit31 gate at the
  // top of resetWarpPost; reset to -1 on the warp-post path.
  int32_t mWarpFlag334;  // 0x334

  uint8_t mPad338[0x11f8];  // 0x338 unproven

  // 0x1530 — pointer checked in resetWarpPost; [+8] == 2 branches.
  void* mSub1530;  // 0x1530
};
}  // namespace object
