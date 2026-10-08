#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo mangled name: N2nn3nex21JobDataStoreGetRatingE).
// vptr 0x12f6ce0 (GOT cell 0x1315980, n=15, ctor 0xb1ac00, sole construction site 0xb1ac74).
// Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
// secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
// base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
class JobDataStoreGetRating {
 public:
  void* vtable;           // 0x00
  uint8_t mBase08[0x98];  // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
  uint32_t mZeroa0;       // 0xa0 — ctor zero
  uint8_t mPada4[0x4];    // 0xa4 — unproven gap
  uint64_t mZeroa8;       // 0xa8 — ctor zero
  uint64_t mFieldb0;      // 0xb0 — ctor zero (stp high half)
  uint64_t mZerob8;       // 0xb8 — ctor zero
  uint64_t mFieldc0;      // 0xc0 — ctor zero (stp high half)
  uint64_t mZeroc8;       // 0xc8 — ctor zero
  uint64_t mFieldd0;      // 0xd0 — ctor zero (stp high half)
  uint64_t mZerod8;       // 0xd8 — ctor zero
  uint64_t mFielde0;      // 0xe0 — ctor zero (stp high half)
  uint64_t mZeroe8;       // 0xe8 — ctor zero
  uint64_t mFieldf0;      // 0xf0 — ctor zero (stp high half)
  uint64_t mZerof8;       // 0xf8 — ctor zero
  uint64_t mField100;     // 0x100 — ctor zero (stp high half)
  uint64_t mZero108;      // 0x108 — ctor zero
  uint8_t mZero110;       // 0x110 — ctor zero
  uint8_t mPad111[0x7];   // 0x111 — unproven gap
  uint8_t mInit118;       // 0x118 — member-init call (subobject starts here) (size unknown)
  uint8_t mPad119[0x7];   // 0x119 — unproven gap
  uint8_t mPad120[0xb8];  // 0x120 — unproven gap
  uint64_t mZero1d8;      // 0x1d8 — ctor zero
  // Object size 0x1e0 (allocation size at the factory new preceding ctor 0xb1ac00).
};
}  // namespace nn::nex
