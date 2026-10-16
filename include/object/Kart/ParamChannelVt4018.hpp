#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt4018 — address-anchored name (vptr 0x12b4018, GOT cell
// extent 0x28
class ParamChannelVt4018 : public KartParamCacheChan {
 public:
  uint8_t mFlag24;   // 0x24 — zeroed on init
  uint8_t pad25[3];  // 0x25 — 0x27 — unproven tail
                     // (0x28 total)
};
}  // namespace object
