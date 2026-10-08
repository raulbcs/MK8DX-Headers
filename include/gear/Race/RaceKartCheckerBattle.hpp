#pragma once

#include <cstdint>

#include <math/seadVector.h>

namespace gear {
class RaceKartCheckerBattle {
 public:
  // Unproven - Switch ctor not identified (no RTTI, stripped binary);
  // extent 0x100 from the Wii U (32-bit) reference layout.
  uint8_t mPad00[0x100];  // unproven - extent 0x100 from Wii U (32-bit) reference layout

  void onCrash(int, const sead::Vector3<float>*);
};

RaceKartCheckerBattle* GetRaceKartCheckerBattle(int);
}  // namespace gear
