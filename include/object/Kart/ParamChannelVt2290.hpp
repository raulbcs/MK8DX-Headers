#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"
#include <object/Kart/KartParamCacheChanBase.hpp>
#include <object/Kart/KartParamCacheChan.hpp>

namespace object::Kart {
// ParamChannelVt2290 — address-anchored name (vptr 0x12b2290, GOT cell
// extent 0x30
class ParamChannelVt2290 : public KartParamCacheChan {
 public:
  char mOwn20[0x10];  // 0x20 — own-field region
                      // (0x30 total)
};
}  // namespace object::Kart
