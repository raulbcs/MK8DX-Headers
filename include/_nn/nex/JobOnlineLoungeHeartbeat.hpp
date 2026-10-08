#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo mangled name: N2nn3nex24JobOnlineLoungeHeartbeatE).
// vptr 0x12d72a8 (GOT cell 0x13121d0, n=13, ctor 0x902d00, sole construction site 0x902d68).
// Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
// secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
// base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
class JobOnlineLoungeHeartbeat {
 public:
  void* vtable;           // 0x00
  uint8_t mBase08[0x98];  // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
  uint8_t mPada0[0x20];   // 0xa0 — unproven gap
  uint64_t mFieldc0;      // 0xc0 — ctor-written
  uint8_t mPadc8[0x38];   // 0xc8 — unproven gap
  uint8_t mInit100;       // 0x100 — member-init call (subobject starts here) (size unknown)
  // Object size 0x190 (allocation size at the factory new preceding ctor 0x902d00).
};
}  // namespace nn::nex

uint8_t mPad101[0x8F];  // 0x101 — unproven gap (region unmapped by ctor analysis)
