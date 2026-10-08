#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt2290 — address-anchored name (vptr 0x12b2290, GOT cell
// 0x130d910). Channel type of the 0x66496c cluster, built in
// place inside the headered param-cache containers. channel at parent+0x60: embedded node (0x710061cc48) at +0x18, u32 at +0x28.
// Extent 0x30.
class ParamChannelVt2290 : public KartParamCacheChan {
 public:
  char mOwn20[0x10];  // 0x20 — own-field region
                      // (0x30 total)
};
// vtable fact (TU vtInitParamChannel_7100647328.cpp): slot 0 (0x10) is the
// vtable-init — stores the class vtable pointer (global pointer at
// 0x710130918, +0x10) into *this.
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
