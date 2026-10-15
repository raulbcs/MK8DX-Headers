#pragma once

#include <cstdint>

namespace object {
class KartVehicleNetData {
 public:
  uint8_t mPad00[0x63];  // 0x00 — unproven padding
  uint8_t mPad63;        // 0x63 — ctor zero

  // extent 0x64 (allocation size 0x64 — movz w0,#0x64; bl 0x710060afec
  // _Znwm @0x71000cca18 → ctor 0x71007e6ab0; ctor stores reach 0x5c)
};
}  // namespace object
