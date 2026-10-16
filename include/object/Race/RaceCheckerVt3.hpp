#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

// RaceCheckerVt3 — checker family; vtable .data 0x12d0e78 (GOT 0x1311120);
// ctor 0x7100882db0, D1 0x882e48, D0 0x882e88; new[](0x70) at 0x87e030.

namespace object {
class RaceCheckerVt3 : public gear::Actor {
 public:
  virtual void slot70();  //0x70
  virtual void slot78();  //0x78

  uint64_t mField38;  // 0x38 — zeroed on ctor
  uint32_t mField40;  // 0x40 — zeroed on ctor
  uint32_t mPad44;    // 0x44 — unproven padding
  uint64_t mField48;  // 0x48 — zeroed on ctor
  char mPad50[0x18];  // 0x50 — zeroed on ctor (to 0x68)
  void* mChannel68;   // 0x68 — owned 0x38 recorder channel sub-object
  // extent 0x70 (ctor 0x7100882DB0 stores reach 0x70)
};
}  // namespace object
