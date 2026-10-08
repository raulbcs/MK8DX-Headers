#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt2a50 — address-anchored name (vptr 0x12b2a50, GOT cell
// 0x130d9c0). Channel type of the 0x66496c cluster, built in
// place inside the headered param-cache containers. channel at parent+0x170: u32 quad from globals at +0x188-0x194 (fn 0x710064cae8).
// Extent 0x198.
class ParamChannelVt2a50 : public KartParamCacheChan {
 public:
  char mOwn20[0x178];  // 0x20 — own-field region
                       // (0x198 total)
};
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
