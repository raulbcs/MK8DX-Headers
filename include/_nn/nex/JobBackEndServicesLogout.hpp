#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo mangled name: N2nn3nex24JobBackEndServicesLogoutE).
// vptr 0x12e6d48 (GOT cell 0x1314cc8, n=13, ctor 0xa3c8e0, sole construction site 0xa3c920).
// Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
// secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
// base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
class JobBackEndServicesLogout {
 public:
  void* vtable;           // 0x00
  uint8_t mBase08[0x98];  // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
  uint32_t mFielda0;      // 0xa0 — ctor-written
  uint8_t mPada4[0x4];    // 0xa4 — unproven gap
  uint64_t mFielda8;      // 0xa8 — ctor-written
  uint64_t mFieldb0;      // 0xb0 — ctor-written (stp high half)
  uint64_t mZerob8;       // 0xb8 — ctor zero
  uint64_t mFieldc0;      // 0xc0 — ctor zero (stp high half)
  uint64_t mFieldc8;      // 0xc8 — ctor-written
  uint8_t mPadd0[0x4];    // 0xd0 — unproven gap
  uint8_t mZerod4;        // 0xd4 — ctor zero
  uint8_t mPadd5[0x3];    // 0xd5 — unproven gap
  uint64_t mZerod8;       // 0xd8 — ctor zero
  uint32_t mZeroe0;       // 0xe0 — ctor zero
  uint8_t mPade4[0x4];    // 0xe4 — unproven gap
  uint64_t mFielde8;      // 0xe8 — ctor-written
  uint64_t mFieldf0;      // 0xf0 — ctor-written (stp high half)
  uint64_t mZerof8;       // 0xf8 — ctor zero
  uint64_t mField100;     // 0x100 — ctor zero (stp high half)
  uint64_t mZero108;      // 0x108 — ctor zero
  uint64_t mField110;     // 0x110 — ctor zero (stp high half)
  uint64_t mZero118;      // 0x118 — ctor zero
  uint8_t mInit120;       // 0x120 — member-init call (subobject starts here) (size unknown)
  uint8_t mPad121[0x7];   // 0x121 — unproven gap
  uint8_t mPad128[0x10];  // 0x128 — unproven gap
  uint64_t mZero138;      // 0x138 — ctor zero
  uint32_t mZero140;      // 0x140 — ctor zero
  uint8_t mPad144[0x4];   // 0x144 — unproven gap
  uint64_t mZero148;      // 0x148 — ctor zero
  uint64_t mField150;     // 0x150 — ctor zero (stp high half)
  // Object size 0x158 (allocation size at the factory new preceding ctor 0xa3c8e0).
};
}  // namespace nn::nex
