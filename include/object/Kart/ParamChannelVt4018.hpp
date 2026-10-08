#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt4018 — address-anchored name (vptr 0x12b4018, GOT cell
// 0x130dbd0). Channel type of the 0x66496c cluster: built in
// place inside the headered containers (ctor family 0x7100668528 /
// in-place vptr store), derived from KartParamCacheChan via
// ChanBase (0x12b3af0). Byte flag at 0x24 (extent 0x28).
// Slot 0x48 returns 13 (family ID) — Slot48_ret13_7100668500.cpp.
class ParamChannelVt4018 : public KartParamCacheChan {
 public:
  uint8_t mFlag24;  // 0x24 — zeroed on init
                    // (0x28 total)
};
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
