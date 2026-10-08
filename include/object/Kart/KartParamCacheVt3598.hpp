#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid.hpp"

namespace object {
// KartParamCacheVt3598 — address-anchored name (vptr 0x12b3598,
// GOT cell 0x130db00). Derived KartParamCacheMid variant built by the
// factory 0x710065efbc (case w1=1, inline extension of the mid ctor);
// size 0x150 (factory alloc).
class KartParamCacheVt3598 : public KartParamCacheMid {
 public:
  char mChan110[0x18];  // 0x110 — channel-pair member (ctor pair
                        // 0x7100662f30/0x7100662f70, cell 0x130d9b8)
  uint32_t mField128;   // 0x128 — factory zero
  uint8_t pad12c[4];    // 0x12c — unproven padding
  char mChan130[0x20];  // 0x130 — channel-pair member (names
                        // 0xef9d06/0xef9d13)

  // (0x150 total)
};
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
