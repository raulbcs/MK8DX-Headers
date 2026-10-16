#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt2a50 — address-anchored name (vptr 0x12b2a50, GOT cell
// extent 0x198
class ParamChannelVt2a50 : public KartParamCacheChan {
 public:
  char mOwn20[0x178];  // 0x20 — own-field region
                       // (0x198 total)
};
}  // namespace object
