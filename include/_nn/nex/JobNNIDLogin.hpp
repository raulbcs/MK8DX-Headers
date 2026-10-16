#pragma once

#include <cstdint>

namespace nn::nex {
// JobNNIDLogin — RTTI-confirmed; vptr 0x12e7af0 (GOT 0x1314dd0, n=13);
// NEVER CONSTRUCTED (no derived-vptr store site; only .data init 0xe485d8).
class JobNNIDLogin {
 public:
  void* vtable;           // 0x00
  uint8_t mBase08[0x98];  // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
  // extent unknown (>= 0xa0): no factory/ allocation proof exists for this class.
};
}  // namespace nn::nex
