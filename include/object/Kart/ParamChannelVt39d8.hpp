#pragma once

#include <cstdint>

#include "object/Kart/ParamChannelVt38f8.hpp"

namespace object {
// ParamChannelVt39d8 — address-anchored name (vptr 0x12b39d8, GOT cell
// 0x130db40). LAZY-resolver channel type of the 0x66496c cluster (sibling of
// ParamChannelVt38f8/0x12b38f8 and Vt3c38/0x12b3c38): no static vptr
// store — initialized at runtime by the shared lazy-init method
// 0x7100646850(this, ctx). Same proven layout (extent >= 0x170,
// resolver writes 0x11c/0x160, elems 0x110/0x118); see Vt38f8 for
// the full resolver map. Site: ctor_fn region 0x71006615fc.
class ParamChannelVt39d8 : public ParamChannelVt38f8 {
  // (same shape; extent >= 0x170, tail unmapped)
};
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
