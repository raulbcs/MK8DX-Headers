#pragma once

#include <cstdint>

// Vt12d2f78 — 'Screw/' resource category entry; vptr 0x12d2f78, n=10, no typeinfo, no dedicated ctor.
// In-place polymorphic entry (stride 0x60) inside the manager initialized by FUN_71008911a0.
// extent 0x60 - details: doc/object/Vt12d2f78.md

namespace object {
class Vt12d2f78 {
 public:
  void* mVtable;        // 0x00 — 0x12d2f78 (via GOT cell 0x1311650)
  uint8_t mPad8[0x20];  // 0x08 — unproven padding (no stores in the init path)
  void* mPtr28;         // 0x28 — same global pointer as mPtr38 (x21 in FUN_71008911a0)
  void* mPathPrefix;   // const char*  // 0x30 — "Screw/" (0xf0cf3b), stored at 0x8913a8
  void* mPtr38;         // 0x38 — same global pointer as mPtr28 (x21)
  void* mExtension;   // const char*   // 0x40 — ".bfres" (0xee0c9e), stored at 0x891414
  uint32_t mField48;    // 0x48 — set to 2 (0x891338/0x8913bc)
  uint8_t mPad4c[4];    // 0x4c — gap
  uint64_t mZero50;     // 0x50 — zeroed (0x8913cc)
  uint8_t mZero58;      // 0x58 — zeroed (0x8913f0)
  uint8_t mPad59[3];    // 0x59 — gap
  uint32_t mZero5c;     // 0x5c — zeroed (0x8913f0)
};
}  // namespace object
