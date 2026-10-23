#pragma once

#include <cstdint>
#include <object/Kart/KartParamCache.hpp>
#include <object/Kart/ParamChannelVt32b8.hpp>
#include <object/Kart/KartParamCacheNode.hpp>
#include <object/Kart/ParamNodeVtd5b0.hpp>
#include <object/Kart/KartParamCacheChan.hpp>

// KartParamCacheVtd608 — address-anchored name (vptr 0x12bd608,
// GOT cell 0x130e8a8). Named node-group container of the c63c6f8
namespace object::Kart {
class KartParamCacheVtd608 : public KartParamCache {
 public:
  KartParamCacheNode mNode48;  // 0x48 — 0x30 (same node type as Mid 0x68)
  uint8_t pad78[0x18];         // 0x78 — unproven padding
  ParamChannelVt32b8 mChan78;  // 0x78 — channel pair (0x20)
  uint32_t mZero90;            // 0x90 — ctor zero
  uint8_t mString98[0x20];     // 0x98 — named-string member (ptr @0x98 = this+0xac SSO buf)
  ParamChannelVt32b8 mChanB8;  // 0xb8 — second channel pair (0x20)
  uint32_t mZeroD0;            // 0xd0 — ctor zero
  ParamNodeVtd5b0 mNodeD8;     // 0xd8 — node (ctor 0x7100728074)
  uint8_t mNode1a8[0xb8];      // 0x1a8 — Vt500 node (ctor 0x7100727a60; padded
  uint8_t mNode260[0xb8];      // 0x260 — Vt558 node (ctor 0x7100727d54; padded
};

}  // namespace object::Kart
