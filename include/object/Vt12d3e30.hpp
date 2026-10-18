#pragma once

#include <cstdint>

// Vt12d3e30 — PLACEHOLDER name; vtable of a member embedded at giant-manager
// +0x4ca8 (init 0x891450-0x89148c, sibling member at +0x4c48 = vt 0x12d3030).
// 10-slot table via GOT cell 0x1311660 (holds vt-0x10, no typeinfo).
// extent 0x40 (ctor stores reach +0x30; tail unproven) - details: doc/object/Vt12d3e30.md
namespace object {
class Vt12d3e30 {
 public:
  void* mVtable;      // 0x00 — 0x12d3e30 (cell 0x1311660 + 0x10)
  uint64_t mZero8;    // 0x08 — zeroed on init
  uint64_t mZero10;   // 0x10 — zeroed on init
  uint64_t mZero18;   // 0x18 — zeroed on init
  uint64_t mId20;     // 0x20 — -1 on init (unverified)
  uint64_t mId28;     // 0x28 — -1 on init (unverified)
  uint64_t mZero30;   // 0x30 — zeroed on init
  uint8_t mGap38[8];  // 0x38 — unproven padding
};
}  // namespace object
