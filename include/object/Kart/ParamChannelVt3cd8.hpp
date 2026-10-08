#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt3cd8 — address-anchored name (vptr 0x12b3cd8, GOT cell
// 0x130db70). Channel type of the 0x66496c cluster, built in
// place inside the headered param-cache containers. factory alloc 0x28 (site 0x71006652b0).
// Extent 0x28.
class ParamChannelVt3cd8 : public KartParamCacheChan {
 public:
  char mOwn20[0x8];  // 0x20 — own-field region (factory alloc 0x28)
                     // (0x28 total)
};
// vtable fact (TU paramChannelVt3cd8AllocFilterArraySlot14_71006651dc.cpp):
// slot 14 (0x80) allocates 0x70 bytes via 0x710060b234, then constructs it
// with 0x7100665264(newObj, self+0x18, &sp, &sp+0x10, &sp+0x20, arg) — the
// three stack records carry a tag pair ({[0x710012fae28]+0x10, string
// record} / filter pointer from [0x71012fc190]+8) — and returns the new
// object.
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
