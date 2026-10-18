#pragma once

#include <cstdint>

namespace nn::pia::local {
// nn::pia::local::LocalMatchmakeSession — RTTI-named (typeinfo 0x12e1fc0,
// name "N2nn3pia5local21LocalMatchmakeSessionE"). Constructed inside the
// LocalEjectClientListCheckJob::WaitEjectTargetClient TU; primary vptr
// 0x12e1e38 (GOT cell 0x1314128 holds 0x12e1e28 = vt-0x10).
// extent 0x60 - details: doc/_nn/pia/local/LocalMatchmakeSession.md
class LocalMatchmakeSession {
 public:
  void* vtable;      // 0x00 - 0x12e1e38 (cell 0x1314128 + 0x10)
  char pad08[0x10];  // 0x08..0x17 - base subobject (base ctor 0x710097df48:
                     //   vptr from runtime cell 0x13130688, ptr +0x8 via
                     //   0x710097df6c, flag byte +0x10)
  void* m18;         // 0x18 - ctor arg (C1 0x71009d319c)
  void* m20;         // 0x20 - ctor zero
  void* m28;         // 0x28 - ctor zero
  uint32_t mState30; // 0x30 - ctor zero; state word (==3/==4 switch in slot
                     //   code 0x71009d3254)
  char pad34[0x04];  // 0x34..0x37 - unproven gap
  void* m38;         // 0x38 - ctor zero
  char pad40[0x08];  // 0x40..0x47 - ctor zeroes the byte at +0x40
  char pad48[0x18];  // 0x48..0x5f - trailing subobject: inited by
                     //   0x7100929ec0 (zeroes +0x48/+0x60b), finalized via
                     //   0x7100929ee0 in D2; unproven
};
}  // namespace nn::pia::local
