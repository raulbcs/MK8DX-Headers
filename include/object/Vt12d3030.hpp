#pragma once

#include <cstdint>

// Vt12d3030 — 'Light/' resource category entry; vptr 0x12d3030, n=10, no typeinfo, no dedicated ctor.
// In-place polymorphic entry (stride 0x60) inside the manager initialized by FUN_71008911a0.
// extent 0x60 - details: doc/object/Vt12d3030.md

namespace object {
class Vt12d3030 {
 public:
  void* mVtable;        // 0x00 — 0x12d3030 (via GOT cell 0x1311658)
  uint8_t mPad8[0x20];  // 0x08 — unproven padding (no stores in the init path)
  void* mPtr28;         // 0x28 — same global pointer as mPtr38 (x21 in FUN_71008911a0)
  void* mPathPrefix;   // const char*  // 0x30 — "Light/" (0xf0cf51), stored at 0x891420
  void* mPtr38;         // 0x38 — same global pointer as mPtr28 (x21)
  void* mExtension;   // const char*   // 0x40 — ".bfres" (0xee0c9e), stored at 0x891478
  uint32_t mField48;    // 0x48 — set to 2 (0x891428/0x89142c)
  uint8_t mPad4c[4];    // 0x4c — gap
  uint64_t mZero50;     // 0x50 — zeroed (0x891440)
  uint8_t mZero58;      // 0x58 — zeroed (0x891444)
  uint8_t mPad59[3];    // 0x59 — gap
  uint32_t mZero5c;     // 0x5c — zeroed (0x89144c)
};
}  // namespace object
