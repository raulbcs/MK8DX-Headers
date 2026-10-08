#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid.hpp"

namespace object {
// KartParamCacheVt36b8 — address-anchored name (vptr
// 0x12b36b8, GOT cell 0x130db08). Derived KartParamCacheMid variant,
// the SMALLEST of the big ones: factory 0x710065efbc case w1=3,
// alloc 0x118, mid ctor then this vptr and a zero at 0x110.
class KartParamCacheVt36b8 : public KartParamCacheMid {
 public:
  void* mZero110;  // 0x110 — factory zero
                   // (0x118 total)
};
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
