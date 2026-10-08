#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChanBase.hpp"

namespace object {
// KartParamCacheChan — address-anchored name (vptr 0x12b21e0,
// GOT cell 0x130d908). The recorder channel-pair member embedded at 0xb0/0xd0/0xf0 of
// KartParamCacheMid, 0x110/0x130 of the 0x150 variants and 0x200 of
// KartParamCacheColorCorrection: ctor pair 0x7100662f30 (base) + 0x7100662f70 (name/fn fill:
// fn cell 0x12fae28, rodata name, owner back-ptr).
class KartParamCacheChan : public KartParamCacheChanBase {
 public:
  char mTail18[8];  // 0x18 — filled by the 0x7100662f70 init
};
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
