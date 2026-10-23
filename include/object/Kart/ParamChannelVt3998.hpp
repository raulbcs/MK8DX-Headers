#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"
#include <object/Kart/KartParamCacheChanBase.hpp>
#include <object/Kart/KartParamCacheChan.hpp>

namespace object::Kart {
// ParamChannelVt3998 — address-anchored name (vptr 0x12b3998, GOT cell
// 0x130db38). Lazy-resolver channel of the 0x66496c cluster.
// extent 0x170 (cluster lower bound) - details: doc/object/Kart/ParamChannelVt3998.md
class ParamChannelVt3998 : public KartParamCacheChan {
 public:
  char mOwn20[0xe8];       // 0x20 — own-field region (same shape as Vt38f8)
  uint32_t mCount108;      // 0x108 — element count (unverified)
  uint8_t pad10c[4];       // 0x10c — unproven padding
  void** mElems110;        // 0x110 — element pointer array (unverified)
  uint8_t pad118[0x4];     // 0x118 — unproven gap
  uint8_t mBlob11c[0x10];  // 0x11c — resolver blob copy (unverified)
  uint8_t pad12c[0x34];    // 0x12c — unproven padding
  uint8_t mBlob160[0x10];  // 0x160 — resolver blob copy (unverified)
};
}  // namespace object::Kart
