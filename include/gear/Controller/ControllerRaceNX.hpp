#pragma once
#include <controller/seadController.h>

namespace gear {
class ControllerRaceNX {
 public:
  // Unproven — Switch ctor not identified (no RTTI, stripped binary);
  // extent fixed by mController at 0x158. The //0x144 comment below
  // is a Wii U (32-bit) relic.
  char pad_00[0x158];             // unproven - extent fixed by mController at 0x158
  sead::Controller* mController;  //0x144
};

ControllerRaceNX* GetControllerRace(int);
}  // namespace gear
