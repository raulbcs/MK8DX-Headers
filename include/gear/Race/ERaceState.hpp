#pragma once
#include <cstdint>

namespace gear {
enum ERaceState : uint32_t {
  RaceState_PreStart = 0,
  RaceState_Menu = 1,
  RaceState_CountdownA = 2,
  RaceState_CountdownB = 3,
  RaceState_CountdownC = 4,
  RaceState_Go = 5,
  RaceState_Run = 6,
  RaceState_Finish = 7,
  RaceState_Exit = 8,
};
}  // namespace gear
