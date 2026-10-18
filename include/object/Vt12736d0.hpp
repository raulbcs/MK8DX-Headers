#pragma once

#include <cstdint>

// Vt12736d0 — PLACEHOLDER name; vptr row 0x12736d0, 93 slots, GOT cell 0x1308eb8.
// Derived from Vt12d5218 (ctor 0x8ca8b0), overrides 8 slots. Row has a 0x10 preamble
// (offset-to-top 0 / typeinfo NULL); virtual fns begin at 0x12736e0.
// extent 0x1E8 - details: doc/object/Vt12736d0.md

namespace object {
class Vt12736d0 {
 public:
  void* mVtable;            // 0x00 — 0x12736e0 (row 0x12736d0 + 0x10; via GOT cell 0x1308eb8)
  uint8_t mPad8[0x1E0];     // 0x08 — unproven padding (base Vt12d5218 layout)
};
}  // namespace object
