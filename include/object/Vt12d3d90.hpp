#pragma once

#include <cstdint>

// Vt12d3d90 — PLACEHOLDER name; vptr 0x12d3d90 (GOT cell 0x1311960, holds vt-0x10), 8-slot table.
// Small record constructed on the stack inside FUN_71008a9990 (Vt12d3cc8 slot15); no out-of-line C1.
// extent 0x40 - details: doc/object/Vt12d3d90.md

namespace object {
class Vt12d3d90 {
 public:
  void* mVtable;            // 0x00 — 0x12d3d90 (installed at frame sp+0x68 by 0x8aa8f8)
  uint8_t mPad8[0x38];      // 0x08 — unproven (next frame member at +0x40)
};
}  // namespace object
