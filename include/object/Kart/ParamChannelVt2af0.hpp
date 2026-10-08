#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt2af0 — address-anchored name (vptr 0x12b2af0, GOT cell
// 0x130d9b8). Channel type of the 0x66496c cluster: 0x20-byte
// channel instantiated MULTIPLE times in its parent (sites
// parent+0x110 and +0x130, float field at each instance's +0x18,
// fn 0x710064c9dc region). Extent 0x20.
class ParamChannelVt2af0 : public KartParamCacheChan {
 public:
  // (no own fields beyond the Chan shape)
  // (0x20 total)
};
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
