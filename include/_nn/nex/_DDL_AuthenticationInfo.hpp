#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo record 0x12f90a0, name
// N2nn3nex23_DDL_AuthenticationInfoE; base nn::nex::Data, ti
// 0x12e61b0). vptr 0x12f9058 (GOT cell 0x1314e40 holds vptr-0x10).
// D1 0xa457e8 / D0 0xb4ccac also install the nn::nex::Data base vptr
// (runtime cell 0x130b4a8 + 0x10) at [this+0x10].
// extent 0x144 - details: doc/_nn/nex/_DDL_AuthenticationInfo.md
class _DDL_AuthenticationInfo {
 public:
  void* vtable;             // 0x00 — 0x12f9058
  uint8_t mPad08[0x8];      // 0x08 — unproven gap
  void* mDataVptr10;        // 0x10 — nn::nex::Data base vptr (runtime cell
                            // 0x130b4a8 + 0x10, installed by D1/D0)
  uint8_t mPad18[0x40];     // 0x18 — unproven gap
  uint32_t mField58;        // 0x58 — status (2 = authenticated branch)
  uint8_t mPad5c[0x68];     // 0x5c — unproven padding
  uint32_t mEntriesC4[32];  // 0xc4 — 32 dwords scanned by the consumer;
                            // consumer also reads u16 flags inside this
                            // region at 0xe8/0xec/0xf8
};
}  // namespace nn::nex
