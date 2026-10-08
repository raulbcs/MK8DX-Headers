#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt32b8 — address-anchored name (vptr 0x12b32b8,
// GOT cell 0x130daa8). Channel type of the 0x66496c cluster, proven
// 0x20 by the stride-0x20 pattern (same shape as ParamChannelVt2af0).
// Instance evidence: KartParamCacheVtd608 ctor 0x71007284f0 embeds it
// at +0x78 and +0xb8 (0x7100662f30 base + 0x7100662f70 finish).
class ParamChannelVt32b8 : public KartParamCacheChan {
 public:
  // (0x20 total)
};
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
