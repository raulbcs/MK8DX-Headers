#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt38f8 — address-anchored name (vptr 0x12b38f8, GOT cell
class ParamChannelVt38f8 : public KartParamCacheChan {
 public:
  char mOwn20[0xe8];       // 0x20 — own-field region
  uint32_t mCount108;      // 0x108 — element count
  uint8_t pad10c[4];       // 0x10c — unproven padding
  void** mElems110;        // 0x110 — element pointer array
  uint8_t mBlob11c[0x10];  // 0x11c — copied from ctx+0xc0
  uint8_t pad12c[0x34];    // 0x12c — unproven padding
  uint8_t mBlob160[0x10];  // 0x160 — copied from ctx+0xc0
                           // (0x170 total, tail unmapped)
                           // extent 0x170 (prior-survey total 0x170)
  uint8_t mGap118[4];      // 0x118 — unproven gap
};
}  // namespace object
