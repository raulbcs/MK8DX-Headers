#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo mangled name: N2nn3nex21JobAcquireAccessTokenE).
// vptr 0x12d70b8 (GOT cell 0x1312108, n=13, ctor 0x8fd918, sole construction site 0x8fd934).
// Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
// secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
// base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
class JobAcquireAccessToken {
 public:
  void* vtable;           // 0x00
  uint8_t mBase08[0x98];  // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
  uint8_t mPada0[0x8];    // 0xa0 — unproven gap
  uint8_t mInita8;        // 0xa8 — member-init call (subobject starts here) (size unknown)
  uint8_t mPadb0[0x90];   // 0xb0 — unproven gap
  uint64_t mField140;     // 0x140 — ctor-written
  uint8_t mPad148[0x8];   // 0x148 — unproven gap
  uint8_t mInit150;       // 0x150 — member-init call (subobject starts here) (size unknown)
  uint8_t mPad158[0x8];   // 0x158 — unproven gap
  uint8_t mInit160;       // 0x160 — member-init call (subobject starts here) (size unknown)
  uint8_t mPad168[0x28];  // 0x168 — unproven gap
  uint64_t mField190;     // 0x190 — ctor-written
  uint8_t mPad198[0x8];   // 0x198 — unproven gap
  uint64_t mField1a0;     // 0x1a0 — ctor-written
  uint64_t mField1a8;     // 0x1a8 — ctor-written (stp high half)
  uint8_t mPad1b0[0x20];  // 0x1b0 — unproven gap
  uint64_t mField1d0;     // 0x1d0 — ctor-written
  uint8_t mPad1d8[0x8];   // 0x1d8 — unproven gap
  uint8_t mInit1e0;       // 0x1e0 — member-init call (subobject starts here) (size unknown)
  uint8_t mPad1e8[0x20];  // 0x1e8 — unproven gap
  uint8_t mInit208;       // 0x208 — member-init call (subobject starts here) (size unknown)
  // Object size unknown (factory function 0x8fd918 performs no direct allocation).
};
}  // namespace nn::nex
