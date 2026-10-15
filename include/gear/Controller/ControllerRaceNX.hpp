#pragma once
#include <controller/seadController.h>

namespace gear {
class ControllerRaceNX {
 public:
  // Unproven — Switch ctor not identified (no RTTI, stripped binary);
  // extent fixed by mController at 0x158. The //0x144 comment below
  // is a Wii U (32-bit) relic.
  char pad_00[0x144];             // unproven padding
  sead::Controller* mController;  //0x144
  uint8_t pad_14c[0xC];           // 0x14c — unproven padding (to 0x158)
// extent 0x158 (extent fixed by mController at 0x158 (32-bit reference size))

};

ControllerRaceNX* GetControllerRace(int);
}  // namespace gear
