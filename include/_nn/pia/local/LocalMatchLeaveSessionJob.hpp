#pragma once

#include <cstdint>

namespace nn::pia::local {
// LocalMatchLeaveSessionJob — RTTI-named (typeinfo 0x12e1cb0, name
// "N2nn3pia5local25LocalMatchLeaveSessionJobE"). Typeinfo-slot row: GOT cell
// 0x1314108 holds 0x12e1c18 (= vt-0x8); vptr = 0x12e1c28.
// extent 0xa0 - details: doc/_nn/pia/local/LocalMatchLeaveSessionJob.md
class LocalMatchLeaveSessionJob {
 public:
  void* vtable;      // 0x00 - 0x12e1c28 (cell 0x1314108 + 0x10)
  char pad08[0x90];  // 0x08 - base subobject region (base ctor 0x7100985060;
                     //   unproven gap, no own C1 stores beyond the vptr)
  void* m98;         // 0x98 - C1 arg (x1)
};
}  // namespace nn::pia::local
