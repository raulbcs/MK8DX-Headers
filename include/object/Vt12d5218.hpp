#pragma once

#include <cstdint>

// Vt12d5218 — PLACEHOLDER name; vptr 0x12d5218, 93 slots, GOT cell 0x1311c30 (holds vptr-0x10).
// Base of Vt12736d0 (0x1E8 bytes) and Vt1270280 (0x398 bytes); MI secondary vptr at +0x130.
// extent 0x1E8 (size of the smallest deriving allocation; standalone size unproven) -
// details: doc/object/Vt12d5218.md

namespace object {
class Vt12d5218 {
 public:
  void* mVtable;            // 0x00 — 0x12d5218 (via GOT cell 0x1311c30)
  uint8_t mPad8[0x128];     // 0x08 — unproven padding
  void* mVtable2;           // 0x130 — 0x12d5510 (MI secondary, cell 0x1311c38)
  uint8_t mPad138[0xB0];    // 0x138 — unproven padding (fields to +0x1CC)
};
}  // namespace object
