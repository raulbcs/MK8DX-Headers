#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"
#include <object/Kart/KartParamCacheChanBase.hpp>
#include <object/Kart/KartParamCacheChan.hpp>

namespace object::Kart {
// ParamChannelVt3cd8 — address-anchored name (vptr 0x12b3cd8, GOT cell
class ParamChannelVt3cd8 : public KartParamCacheChan {
 public:
  char mOwn20[0x8];  // 0x20 — own-field region (factory alloc 0x28)
                     // (0x28 total)
};
}  // namespace object::Kart
