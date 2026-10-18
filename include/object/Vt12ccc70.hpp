#pragma once

#include <cstdint>

// Vt12ccc70 — PLACEHOLDER name; vptr 0x12ccc70, 71 slots, GOT cell 0x1310b08.
// Container with inlined sub-object ctors at +0xC8 (stride 0xC8 chain, vptrs 0x12cdd08/0x12cdd38).
// extent 0x130 - details: doc/object/Vt12ccc70.md

namespace object {
class Vt12ccc70 {
 public:
  void* mVtable;            // 0x00 — 0x12ccc70 (via GOT cell 0x1310b08)
  uint8_t mPad8[0x68];      // 0x08 — unproven padding
  void* mPtr70;             // 0x70 — zeroed by C1
  uint8_t mPad78[0x28];     // 0x78 — unproven padding (zeroed 0x78-0x98)
  void* mSubA0;             // 0xA0 — inlined sub-object, vptr 0x12ccfd8 (cell 0x1310b10)
  uint8_t mPadA8[0x20];     // 0xA8 — unproven padding
  void* mSubC8;             // 0xC8 — inlined sub-object, vptr 0x12cdd08 (cell 0x1310da0)
  uint8_t mPadD0[0x60];     // 0xD0 — unproven padding (self-ptr +0xD0 → +0xDC, fields to +0x12C)
};
}  // namespace object
