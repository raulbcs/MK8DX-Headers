#pragma once

#include <cstdint>

namespace object {
// ParamNodeModelBinding — named from ctor string evidence: ctor params ModelName + BonePrefix (EN/JP, 0xf06f37-0xf06f59) (was address-anchored ParamNodeVte3d0) (vptr 0x12be3d0, cell 0x130e988, n=27, site 0x732d38, ctor 0x732d0c).
class ParamNodeModelBinding {
 public:
  void* vtable;         // 0x00
  uint8_t mPad8[0x28];  // 0x8 — unproven gap
  uint64_t mField30;    // 0x30
  // extent 0x38 (in-place node partition: next node's vptr at +0x38 — site 0x73312c)
};
}  // namespace object
