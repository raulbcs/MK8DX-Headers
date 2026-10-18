#pragma once

#include <cstdint>

namespace nn::nex {
// SecureConnectionClient — RTTI-named (typeinfo 0x12e77b0, name
// "N2nn3nex22SecureConnectionClientE"; base 0x12e73c0 ServiceClient). GOT
// cell 0x1314d48 holds vptr-0x10; heap size 0xb0 proven (new at 0xa416ac).
// extent 0xb0 - details: doc/_nn/nex/SecureConnectionClient.md
class SecureConnectionClient {
 public:
  void* mVtable;         // 0x00 - 0x12e7010 (cell 0x1314d48 + 0x10)
  uint8_t mPad8[0x18];   // 0x08..0x1f - ServiceClient base region (base C1
                         //   0xa326c8, w1 = 2); unproven gap
  uint8_t mPad20[0x90];  // 0x20 - member built by 0xa2cd30(this+0x20, 0xb)
                         //   and 0xa27820 (inlined factory C1); D1 destroys
                         //   it via 0xa3045c (0xa3eff8)
};
}  // namespace nn::nex
