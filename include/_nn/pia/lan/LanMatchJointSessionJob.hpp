#pragma once

#include <cstdint>

namespace nn::pia::lan {
// nn::pia::lan::LanMatchJointSessionJob — RTTI-named (typeinfo 0x12dcf00, name
// string at 0xf80f30, base nn::pia::session::JointSessionJob); vptr 0x12dce38
// (GOT cell 0x13134d0 holds 0x12dce28 = vt-0x10).
// extent 0x190 - details: doc/_nn/pia/lan/LanMatchJointSessionJob.md
class LanMatchJointSessionJob {
 public:
  void* vtable;         // 0x00 - 0x12dce38 (cell 0x13134d0 + 0x10)
  char pad08[0x110];    // 0x08..0x117 - unproven gap
  char mBase118[0x78];  // 0x118..0x18f - nn::pia::session::JointSessionJob base
                        //   subobject (base ctor 0x9b1fe8 tail-called at
                        //   0x977020 with this+0x118)
};
}  // namespace nn::pia::lan
