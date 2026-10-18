#pragma once

#include <cstdint>

// Vt12cddd0 — PLACEHOLDER name; vptr 0x12cddd0, 45 slots, GOT cell 0x1310db8.
// C1 inlines a base vptr (0x12cdf48) then a member sub-ctor at +0x58 before
// overriding the primary vptr.
// extent 0x1D0 - details: doc/object/Vt12cddd0.md

namespace object {
class Vt12cddd0 {
 public:
  void* mVtable;            // 0x00 — 0x12cddd0 (via GOT cell 0x1310db8)
  uint8_t mPad8[0x50];      // 0x08 — unproven padding
  void* mSub58;             // 0x58 — sub-object initialized by FUN_7100853148
  uint8_t mPad60[0x168];    // 0x60 — unproven padding
  uint16_t mField1C8;       // 0x1C8 — zeroed by C1
  uint8_t mField1CA;        // 0x1CA — zeroed by C1
  uint8_t mPad1CB[0x5];     // 0x1CB — unproven padding
};
}  // namespace object
