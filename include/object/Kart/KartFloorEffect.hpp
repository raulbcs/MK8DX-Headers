#pragma once

#include <cstdint>
#include <gear/Actor/Actor.hpp>
#include <gear/XLink/XLinkManualEffect.hpp>

namespace object::Kart {
class KartFloorEffect {
 public:
  uint8_t mPad00[0x118];                // 0x00 — unproven padding (pre-star state)
  gear::XLinkManualEffect mStarEffect;  // 0x118
};
}  // namespace object::Kart
