#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"
#include <object/Kart/KartParamCacheChanBase.hpp>
#include <object/Kart/KartParamCacheChan.hpp>

namespace object::Kart {
// ParamChannelVt4298 — address-anchored name (vptr 0x12b4298, GOT cell
// extent 0x28
class ParamChannelVt4298 : public KartParamCacheChan {
 public:
  uint8_t mFlag24;   // 0x24 — zeroed on init
  uint8_t pad25[3];  // 0x25 — 0x27 — unproven tail
                     // (0x28 total)
};
}  // namespace object::Kart
