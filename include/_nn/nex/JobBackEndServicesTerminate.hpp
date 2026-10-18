#pragma once

#include <cstdint>

namespace nn::nex {
// JobBackEndServicesTerminate — RTTI-confirmed; vptr 0x12e6dc0 (GOT cell
// 0x1314bf0); ctor inlined in factory FUN_7100a37050 (new 0x140 at 0xa371b4).
// D1 0xa3d3e0 / D0 0xa3d414.
// extent 0x140 - details: doc/_nn/nex/JobBackEndServicesTerminate.md
class JobBackEndServicesTerminate {
 public:
  void* vtable;           // 0x00 - 0x12e6dc0 (cell 0x1314bf0 + 0x10)
  uint8_t mBase08[0xa8];  // 0x08 — nn::nex::ForcedCriticalSection base region
                          // (shared job ctor 0x588b04, extent 0xa0; secondary
                          // vptr at +0x78)
  char mSubB0[0x90];      // 0xb0..0x13f — member subobject destroyed by D1
                          // (0x585ae0); internal layout unproven
};
}  // namespace nn::nex
