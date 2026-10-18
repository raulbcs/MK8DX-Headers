#pragma once

#include <cstdint>

// Vt12b4d38 — PLACEHOLDER name; vptr 0x12b4d38, 46 slots, GOT cell 0x130dd08.
// Third of an inline-constructed sibling trio (with Vt12b4a38 0x240 / Vt12b4bb8 0x248).
// extent 0x240 - details: doc/object/Vt12b4d38.md

namespace object {
class Vt12b4d38 {
 public:
  void* mVtable;            // 0x00 — 0x12b4d38 (via GOT cell 0x130dd08)
  uint8_t mPad8[0x210];     // 0x08 — unproven padding (memset-zeroed)
  void* mPtr218;            // 0x218 — zeroed after init
  uint8_t mPad220[0x20];    // 0x220 — unproven padding
};
}  // namespace object
