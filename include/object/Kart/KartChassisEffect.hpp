#pragma once

#include <cstdint>

#include "KartFloorEffect.hpp"

namespace object::Kart {
class KartChassisEffect {
 public:
  uint8_t mPad00[0x18];
  KartFloorEffect* mKartFloorEffect;  // 0x18
};
}  // namespace object::Kart
