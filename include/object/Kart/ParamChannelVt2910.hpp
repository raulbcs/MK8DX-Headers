#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt2910 — address-anchored name (vptr 0x12b2910, GOT cell
// extent 0x1c0
class ParamChannelVt2910 : public KartParamCacheChan {
 public:
  char mOwn20[0x1a0];  // 0x20 — own-field region
                       // (0x1c0 total)
};
}  // namespace object
