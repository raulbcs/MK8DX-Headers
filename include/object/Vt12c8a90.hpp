#pragma once

#include "object/Vt12c8698.hpp"

// PROVISIONAL (no RTTI: typeinfo slot zero). Richest Vt12c8698 derivative:
// two 0x24 blobs, four 0x10 nodes into static table 0x12c8af0 (4 angle banks),
// and a 0x70 subobject. Size proven by operator new 0x108 (0xcc8ec-0xcc8fc).
// extent 0x108 - details: doc/object/Vt12c8a90.md

namespace object {
class Vt12c8a90 : public Vt12c8698 {
 public:
  uint8_t mPad70[0x20];     // 0x70 — unproven gap (base ends at 0x70)
  uint32_t mField90;        // 0x90 — zeroed (0x7e74a8)
  uint8_t mPad94[0x4];      // 0x94 — unproven padding
  void* mField98;           // 0x98 — zeroed; new 0x70 subobject (init
                            //        0x7c55cc, -1) at 0x7e7564-0x7e7578
  float mFieldA0[3];        // 0xa0 — settings singleton cell 0x12fb148 copy
  uint8_t mBlobAC[0x24];    // 0xac — memcpy 0x24 from cell 0x12fd1c8 (bss)
  float mFieldD0[3];        // 0xd0 — second singleton copy ([+0]/[+8])
  uint8_t mBlobDC[0x24];    // 0xdc — memcpy 0x24 from cell 0x12fd1c8
  uint8_t mField100;        // 0x100 — zeroed (0x7e7510)
  uint8_t mPad101[0x7];     // 0x101 — unproven tail pad to 0x108
};
}  // namespace object
