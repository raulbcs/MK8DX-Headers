#pragma once

#include "KartCalcSpeedMiniCore.hpp"

namespace object {
// Kart speed calculation runtime, "mini" variant — derives the core
// (factory 0x34c620: new(0x358), calls the core ctor 0x34d2d8, then
// swaps the vptr to 0x124ccf8). Size 0x358, own fields 0x300..0x358.
// Slot names carry KartCalcSpeed_mini_710034b55c evidence; 88 slots.
class KartCalcSpeedMini : public KartCalcSpeedMiniCore {
 public:
};
}  // namespace object
