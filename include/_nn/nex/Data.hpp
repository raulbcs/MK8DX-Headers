#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo 0x12e61b0: nn::nex::Data). "Data" table-node of
// the online InstanceTable (assert string references InstanceTable.h):
// slot2 allocates a 0x10 sub-entry, slot3 registers it under name "Data".
// extent 0x48 - details: doc/_nn/nex/Data.md
class Data {
 public:
  void* vtable;           // 0x00 - vptr 0x12e5a98 (GOT cell 0x1314938 holds
                          // 0x12e5a88 = vptr-0x10; typeinfo slot 0x12e5a90)
  char mPad08[0x1];       // 0x08 - ctor writes 0
  char mPad09[0x7];       // 0x09..0x0f - unproven (caller writes 0 to 0x09)
  char mPad10[0x38];      // 0x10..0x47 - caller-initialized (see doc)
};
}  // namespace nn::nex
