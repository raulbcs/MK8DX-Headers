#pragma once

#include <cstdint>

// Placeholder Vt12c31b8: no RTTI. Singleton root object (factory 0x7920e4,
// new(0x820) via 0x60b2a8, guard cell 0x12fc390). Twin of Vt12c2fd8 (same
// slot0/1 stubs 0x79a4b8/0x79a4bc). vptr 0x12c31b8 (GOT cell 0x130f6b0, holds
// vt-0x10) stored at +0x00.
// extent 0x820 - details: doc/object/Vt12c31b8.md
class Vt12c31b8 {
 public:
  void* vtable;            // 0x00 — vptr 0x12c31b8
  uint8_t mPad08[0x7cc];   // unproven gap
  uint8_t mInit7d4;        // 0x7d4 — embedded member (vptr cell 0x130f6a0, ctor 0x799ec0; singleton ptr kept in cell 0x130f6a8) (size unknown)
  uint8_t mPad7d5[0x1f];   // unproven gap
  uint16_t mFlags7f4;      // 0x7f4 — factory sets bit 0x100
  uint8_t mPad7f6[0x2];    // 0x7f6 — unproven gap
  uint64_t mField7f8;      // 0x7f8 — zeroed
  uint64_t mField800;      // 0x800 — zeroed (released by slot9 dtor 0x792198)
  uint64_t mField808;      // 0x808 — zeroed
  uint64_t mField810;      // 0x810 — zeroed (released by slot10 dtor 0x792208)
  uint8_t mPad818[0x8];   // unproven gap
};
