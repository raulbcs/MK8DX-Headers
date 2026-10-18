#pragma once

#include <cstdint>

// Vt12cb198 — PLACEHOLDER name; vptr 0x12cb198, n=10, primary table, no typeinfo.
// Per-item entries (0x378) bulk-created by FUN_7100815a48; "PathPt" literal in the creator.
// extent 0x378 - details: doc/object/Vt12cb198.md

namespace object {
class Vt12cb198 {
 public:
  void* mVtable;           // 0x00 — 0x12cb198 (via GOT cell 0x13106d8)
  uint8_t mPad8[0x358];    // 0x08 — unproven padding (ctor 0x8144d0 initializes internals)
  uint64_t mField360;      // 0x360 — zeroed by creator (0x815d1c)
  uint8_t mField368;       // 0x368 — zeroed by creator (0x815d18)
  uint8_t mPad369[3];      // 0x369 — gap
  uint32_t mField36c;      // 0x36c — zeroed by creator (0x815d14)
  uint8_t mField370;       // 0x370 — bool: [global+0x8] == 3 (0x815d2c–0x815d38)
  uint8_t mPad371[3];      // 0x371 — gap
  uint16_t mField374;      // 0x374 — zeroed by creator (0x815d28)
  uint8_t mPad376[2];      // 0x376 — gap
};
}  // namespace object
