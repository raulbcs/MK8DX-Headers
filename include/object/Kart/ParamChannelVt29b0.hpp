#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"
#include <object/Kart/KartParamCacheChanBase.hpp>
#include <object/Kart/KartParamCacheChan.hpp>

namespace object::Kart {
// ParamChannelVt29b0 — address-anchored name (vptr 0x12b29b0, GOT cell
// extent 0x1c0
class ParamChannelVt29b0 : public KartParamCacheChan {
 public:
  char mOwn20[0x1a0];  // 0x20 — own-field region
                       // (0x1c0 total)
};
}  // namespace object::Kart
