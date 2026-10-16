#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt4158 — address-anchored name (vptr 0x12b4158, GOT cell
// extent 0x28
class ParamChannelVt4158 : public KartParamCacheChan {
 public:
  uint8_t mFlag24;   // 0x24 — zeroed on init
  uint8_t pad25[3];  // 0x25 — 0x27 — unproven tail
                     // (0x28 total)
};
}  // namespace object
