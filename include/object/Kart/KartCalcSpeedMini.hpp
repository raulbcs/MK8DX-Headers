#pragma once

#include <cstdint>
#include <object/Kart/KartCalcSpeedMiniCore.hpp>

// Kart speed calculation runtime, "mini" variant — derives the core
// (factory 0x34c620: new(0x358), calls the core ctor 0x34d2d8, then
namespace object::Kart {
class KartCalcSpeedMini : public KartCalcSpeedMiniCore {
 public:
};
}  // namespace object::Kart
