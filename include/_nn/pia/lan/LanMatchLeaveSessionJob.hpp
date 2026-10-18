#pragma once

#include <cstdint>

namespace nn::pia::lan {
// LanMatchLeaveSessionJob — RTTI-named (typeinfo 0x12dcfb0, name
// "N2nn3pia3lan23LanMatchLeaveSessionJobE"). Typeinfo-slot row: GOT cell
// 0x13135c0 holds 0x12dcf18 (= vt-0x8); installed vptr = 0x12dcf28.
// extent 0x98 - details: doc/_nn/pia/lan/LanMatchLeaveSessionJob.md
class LanMatchLeaveSessionJob {
 public:
  void* vtable;      // 0x00 - 0x12dcf28 (cell 0x13135c0 + 0x10)
  char pad08[0x90];  // 0x08 - base subobject region (base ctor 0x7100985060;
                     //   unproven gap, no own C1 stores beyond the vptr)
};
}  // namespace nn::pia::lan
