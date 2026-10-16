#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt20e8 — address-anchored name (vptr 0x12b20e8, GOT cell
class ParamChannelVt20e8 : public KartParamCacheChan {
 public:
  // (no own fields)
  char mPad20[0x60];  // 0x20 — unproven padding to the 0x80 embedded stride
  // (0x80 total)
  // extent 0x80 (embedded stride 0x80 proven in prior survey)
};
}  // namespace object
